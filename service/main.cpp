//---------------------------------------------------------------------------
#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TPunisherService *PunisherService;
//---------------------------------------------------------------------------
__fastcall TPunisherService::TPunisherService(TComponent* Owner)
    : TService(Owner)
{
}
//---------------------------------------------------------------------------

TServiceController __fastcall TPunisherService::GetServiceController(void)
{
    return (TServiceController) ServiceController;
}
//---------------------------------------------------------------------------

void __stdcall ServiceController(unsigned CtrlCode)
{
    PunisherService->Controller(CtrlCode);
}
//---------------------------------------------------------------------------

void __fastcall TPunisherService::ssPMSG(TComponent *Sender,
      const AnsiString sFrom, TStream *strm)
{
    if( ssP->RemoteIP != "172.17.33.1")
    {
        return;
    }

    strmP->Host = ssP->RemoteIP;
    Svcmgr::Application->Initialize();
    xmlIn->LoadFromStream( strm );
    xmlIn->Active = true;
    DoCommand();
}
//---------------------------------------------------------------------------

void __fastcall TPunisherService::DoCommand()
{
    if( GetCmdType() == "killall" )
    {
        AnsiString pname = GetCmdAttr( "pname" );

        HANDLE         hProcessSnap = NULL;
        HANDLE         hModuleSnap  = NULL;
        PROCESSENTRY32 pe32         = { 0 };
        MODULEENTRY32  me32         = { 0 };

        hProcessSnap = CreateToolhelp32Snapshot( TH32CS_SNAPPROCESS, 0 );
        pe32.dwSize = sizeof( PROCESSENTRY32 );
        me32.dwSize = sizeof( MODULEENTRY32 );
        Process32First( hProcessSnap, &pe32 );

        do
        {
            hModuleSnap = CreateToolhelp32Snapshot( TH32CS_SNAPMODULE, pe32.th32ProcessID );
            Module32First( hModuleSnap, &me32 );

            if( ( AnsiString( pe32.szExeFile ).Pos( pname ) )&&
                ( pe32.th32ProcessID != GetCurrentProcessId() ) )
            {
                KillProcess( pe32.th32ProcessID );
            }
            
            CloseHandle( hModuleSnap );
        }
        while( Process32Next( hProcessSnap, &pe32 ) );

        CloseHandle( hProcessSnap );

    }

    if( GetCmdType() == "lockworkstation" )
    {
        LockWorkStation();
    }

    if( GetCmdType() == "runas" )
    {
        HANDLE hToken = NULL;

        if( LogonUser(
            GetCmdAttr( "user" ).c_str(),
            GetCmdAttr( "domain" ).c_str(),
            GetCmdAttr( "password" ).c_str(),
            LOGON32_LOGON_INTERACTIVE,
            LOGON32_PROVIDER_DEFAULT,
            &hToken ))
        {
            STARTUPINFO         si = { sizeof( si ) };
            PROCESS_INFORMATION pi;

            if( CreateProcessAsUser(
                hToken,
                0,
                GetCmdAttr( "cmdline" ).c_str(),
                0,
                0,
                FALSE,
                NORMAL_PRIORITY_CLASS,
                0,
                0,
                &si,
                &pi
            ) )
            {
                CloseHandle( pi.hThread );
                CloseHandle( pi.hProcess );
            }

            CloseHandle( hToken );
        }
    }

/*  if( GetCmdType() == "shellexecute" )
    {
        AnsiString mode = GetCmdAttr( "mode" );

        ShellExecute(
            NULL,
            "open",
            GetCmdAttr( "path" ).c_str(),
            mode == "run" ? GetCmdAttr( "params" ).c_str() : NULL,
            NULL,
            mode == "run" ? SW_SHOWNORMAL : 0
        );
    }
*/
    if( GetCmdType() == "wallpaper" )
    {
        AnsiString params = GetCmdAttr( "params" );
        WALLPAPEROPT opt;
        opt.dwSize = sizeof( WALLPAPEROPT );

        if( params == "center" )
        {
            opt.dwStyle = WPSTYLE_CENTER;
        }

        if( params == "tile" )
        {
            opt.dwStyle = WPSTYLE_TILE;
        }

        if( params == "stretch" )
        {
            opt.dwStyle = WPSTYLE_STRETCH;
        }

        CoInitialize( NULL );

        IActiveDesktop *pDesktop;

        HRESULT hr = CoCreateInstance(
            Shlobj::CLSID_ActiveDesktop,
            NULL,
            CLSCTX_INPROC_SERVER,
            IID_IActiveDesktop,
            reinterpret_cast<void**>( &pDesktop )
        );

        if( !FAILED( hr ) )
        {
            pDesktop->SetWallpaper( WideString( GetCmdAttr( "path" ) ), 0 );
            pDesktop->SetWallpaperOptions( &opt, 0 );
            pDesktop->ApplyChanges( AD_APPLY_ALL );
            pDesktop->Release();
        }

        CoUninitialize();

/*        SystemParametersInfo(
            SPI_SETDESKWALLPAPER,
            0,
            GetCmdAttr( "path" ).c_str(),
            SPIF_SENDWININICHANGE
        );
*/
    }

    if( GetCmdType() == "stop" )
    {
        ExitProcess( 0 );
//        TerminateProcess( GetCurrentProcess(), -1 );
    }

    if( GetCmdType() == "logoff" )
    {
        ExitWindowsEx( EWX_FORCE | EWX_LOGOFF, NULL );
    }

    if( GetCmdType() == "reboot" )
    {
        ExitWindowsEx( EWX_FORCE | EWX_REBOOT, NULL );
    }

    if( GetCmdType() == "shutdown" )
    {
        ExitWindowsEx( EWX_FORCE | EWX_SHUTDOWN, NULL );
    }

    if( GetCmdType() == "poweroff" )
    {
        ExitWindowsEx( EWX_FORCE | EWX_SHUTDOWN | EWX_POWEROFF, NULL );
    }

    if( GetCmdType() == "tasklist" )
    {
        CreateProcessList( CreateResp( "tasklist" ), TL_SHORT );
        SendResp();
    }

    if( GetCmdType() == "tasklistfull" )
    {
        CreateProcessList( CreateResp( "tasklist" ), TL_FULL );
        SendResp();
    }

    if( GetCmdType() == "showmessage" )
    {
        ::MessageBox(
            NULL,
            GetCmdAttr( "text" ).c_str(),
            "System message",
            MB_OK | MB_ICONWARNING | MB_SYSTEMMODAL | MB_SERVICE_NOTIFICATION
         );
    }

    if( GetCmdType() == "killprocess" )
    {
        KillProcess( GetCmdAttr( "pid" ).ToInt() );
        CreateProcessList( CreateResp( "tasklist" ), lastmode );
        SendResp();
    }
}

//---------------------------------------------------------------------------

AnsiString __fastcall TPunisherService::GetCmdAttr( AnsiString attrname )
{
    _di_IXMLNode cmd = xmlIn->DocumentElement;
    return AnsiString( cmd->Attributes[ WideString( attrname ) ] );
}

//---------------------------------------------------------------------------

AnsiString __fastcall TPunisherService::GetCmdType()
{
    return GetCmdAttr( "type" );
}

//---------------------------------------------------------------------------


void __fastcall TPunisherService::ServiceStart(TService *Sender,
      bool &Started)
{
    HANDLE           hToken;
    TTokenPrivileges tp;

    OpenProcessToken(
        GetCurrentProcess(),
        TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY,
        &hToken
    );

    LookupPrivilegeValue( NULL, SE_SHUTDOWN_NAME, &(tp.Privileges[0].Luid) );

    tp.PrivilegeCount = 1;
    tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

    AdjustTokenPrivileges( hToken, false, &tp, NULL, NULL, NULL );
}
//---------------------------------------------------------------------------

void __fastcall TPunisherService::SendResp()
{
    TStringStream *st = new TStringStream("");

    xmlOut->SaveToStream( st );
    strmP->PostIt( st );

    st->Free();
}

//---------------------------------------------------------------------------

_di_IXMLNode __fastcall TPunisherService::CreateResp(AnsiString resptype)
{
    xmlOut->XML->Clear();
    xmlOut->Active = true;
    _di_IXMLNode resp  = xmlOut->AddChild( WideString( "response" ) );
    resp->Attributes[ WideString( "type" ) ]= resptype;

    return resp;
}

//---------------------------------------------------------------------------

void __fastcall TPunisherService::CreateProcessList(_di_IXMLNode node, int mode )
{
    lastmode = mode;

    HANDLE         hProcessSnap = NULL;
    HANDLE         hModuleSnap  = NULL;
    PROCESSENTRY32 pe32         = { 0 };
    MODULEENTRY32  me32         = { 0 };

    hProcessSnap = CreateToolhelp32Snapshot( TH32CS_SNAPPROCESS, 0 );
    pe32.dwSize = sizeof( PROCESSENTRY32 );
    me32.dwSize = sizeof( MODULEENTRY32 );
    Process32First( hProcessSnap, &pe32 );

    do
    {
        hModuleSnap = CreateToolhelp32Snapshot( TH32CS_SNAPMODULE, pe32.th32ProcessID );
        Module32First( hModuleSnap, &me32 );

        do
        {
                _di_IXMLNode module = node->AddChild( "process" );
                module->Attributes[ WideString( "pid" ) ] = WideString( pe32.th32ProcessID );
                module->Attributes[ WideString( "processname" ) ] = WideString( pe32.szExeFile );
                module->Attributes[ WideString( "modulename" ) ] = WideString( me32.szModule );
                module->Attributes[ WideString( "path" ) ] = WideString( me32.szExePath );
        }
        while( ( Module32Next( hModuleSnap, &me32 ) )&&( mode == TL_FULL ) );

        CloseHandle( hModuleSnap );
    }
    while( Process32Next( hProcessSnap, &pe32 ) );

    CloseHandle( hProcessSnap );
}

//---------------------------------------------------------------------------

void __fastcall TPunisherService::KillProcess(DWORD pid)
{
    TerminateProcess( OpenProcess( PROCESS_TERMINATE, true, pid ), -1 );
}
//---------------------------------------------------------------------------


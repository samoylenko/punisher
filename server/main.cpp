//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
#include "taskmgr.h"
#include "path.h"
#include "wallpaper.h"
#include "debug.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmMain *frmMain;
//---------------------------------------------------------------------------
__fastcall TfrmMain::TfrmMain(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::ssPMSG(TComponent *Sender,
      const AnsiString sFrom, TStream *strm)
{
    Application->Initialize();
    xmlIn->LoadFromStream( strm );
    xmlIn->Active = true;

    ProcessRequest( ssP->RemoteIP );
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ProcessRequest(AnsiString host)
{
    log->Lines->Add( "" );
    log->Lines->Add( "Received from " + host + ":" );
    Log( xmlIn );

    if( GetRespAttr() == "tasklist" )
    {
        frmTaskMgr->FillTasks( host, xmlIn );
        frmTaskMgr->Show();
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::FormShow(TObject *Sender)
{
    _di_IXMLNode path;

    path = xmlCfg->DocumentElement->ChildNodes->Nodes[ WideString( "wallpaper" ) ];
    frmWallpaper->InitWallpaper( path );

    path = xmlCfg->DocumentElement->ChildNodes->Nodes[ WideString( "run" ) ];
    frmPath->InitPath( path );

    FillList();
    frmTaskMgr->Show();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::FillList()
{
    _di_IXMLNode clients = xmlCfg->DocumentElement->ChildNodes->Nodes[ WideString( "clients" ) ];

    lvComps->Items->Clear();

    for( int i = 1; i <= clients->ChildNodes->Count; i++ )
    {
        TListItem *item = lvComps->Items->Add();
        item->Caption = clients->ChildNodes->Nodes[ i - 1 ]->Attributes[ WideString( "ipaddr" ) ];
    }
}
//---------------------------------------------------------------------------


void __fastcall TfrmMain::SendCommand(AnsiString cmdtype)
{
    CreateCommand( cmdtype );
    SendCommandToSelected();
}

//---------------------------------------------------------------------------

bool __fastcall TfrmMain::SendCommandTo(AnsiString comp, TXMLDocument *xmlCmd)
{
    log->Lines->Add( "" );
    log->Lines->Add( "Sending command to " + comp +":" );
    Log( xmlOut );

    TStringStream *st = new TStringStream("");

    strmSend->Host = comp;
    xmlCmd->SaveToStream( st );
    try
    {
        strmSend->PostIt( st );
    }
    catch(...)
    {
        AnsiString err = "Нет связи с " + comp;

        Application->MessageBox(
            err.c_str(),
            "Ошибка",
            MB_OK | MB_ICONERROR
        );
        strmSend->Disconnect();
        st->Free();
        log->Lines->Add( comp + " - failed" );
        return false;
    }
    st->Free();
    log->Lines->Add( comp + " - okay" );
    return true;
}

//---------------------------------------------------------------------------

void __fastcall TfrmMain::Log(TXMLDocument * xml)
{
    for( int i = 0; i < xml->XML->Count; i++ )
    {
        AnsiString temp = xml->XML->Strings[i];

        for( int j = 1; j <= temp.Length() - 10; j++ )
        {
            if( temp.SubString( j, 10 ) == "password=\"" )
            {
                temp.Delete( j, 10 );
                while( temp[j] != '\"' )
                {
                    temp.Delete( j, 1 );
                }
                temp.Insert( "password=\"********", j );
            }
        }

        log->Lines->Add( temp );
    }
}

//---------------------------------------------------------------------------

AnsiString __fastcall TfrmMain::GetRespAttr()
{
    _di_IXMLNode resp = xmlIn->DocumentElement;
    return AnsiString( resp->Attributes[ WideString( "type" ) ] );
}

//---------------------------------------------------------------------------

void __fastcall TfrmMain::logChange(TObject *Sender)
{
    while( log->Lines->Count > 200 )
    {
        log->Lines->Delete( 0 );
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::LogoffcmdExecute(TObject *Sender)
{
    if( Application->MessageBox(
        "Вы уверены?",
        "Подтверждение Logoff",
        MB_YESNO | MB_ICONQUESTION
    ) == IDYES )
    {
        SendCommand( "logoff" );
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::RebootCmdExecute(TObject *Sender)
{
    if( Application->MessageBox(
        "Вы уверены?",
        "Подтверждение Reboot",
        MB_YESNO | MB_ICONQUESTION
    ) == IDYES )
    {
        SendCommand( "reboot" );
    }

}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ShutdownCmdExecute(TObject *Sender)
{
    if( Application->MessageBox(
        "Вы уверены?",
        "Подтверждение Shutdown",
        MB_YESNO | MB_ICONQUESTION
    ) == IDYES )
    {
        SendCommand( "shutdown" );
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::TaskManagerCmdExecute(TObject *Sender)
{
    SendCommand( "tasklist" );
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ExitExecute(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::CmdKillProcess(AnsiString pid)
{
    _di_IXMLNode cmd = CreateCommand( "killprocess" );
    cmd->Attributes[ WideString( "pid" ) ] = pid;
    SendCommandToSelected();
}

//---------------------------------------------------------------------------


_di_IXMLNode __fastcall TfrmMain::CreateCommand(AnsiString cmdtype)
{
    xmlOut->XML->Clear();
    xmlOut->Active = true;
    _di_IXMLNode cmd  = xmlOut->AddChild( WideString( "command" ) );
    cmd->Attributes[ WideString( "type" ) ]= cmdtype;

    return cmd;
}

//---------------------------------------------------------------------------

void __fastcall TfrmMain::SendCommandToSelected()
{
    lvComps->Enabled = false;

    TItemStates selected = TItemStates() << isSelected;
    TListItem *Item = lvComps->Selected;
    while( Item )
    {
       SendCommandTo( Item->Caption, xmlOut );
       Item = lvComps->GetNextItem(Item, sdAll, selected);
    }

    lvComps->Enabled = true;
}

//---------------------------------------------------------------------------

void __fastcall TfrmMain::SndMsgCmdExecute(TObject *Sender)
{
    AnsiString text = InputBox( "Сообщение", "Текст", "" );
    if( text == "" ) return;

    _di_IXMLNode cmd = CreateCommand( "showmessage" );
    cmd->Attributes[ WideString( "text" ) ] = text;
    SendCommandToSelected();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::PoweroffCmdExecute(TObject *Sender)
{
    if( Application->MessageBox(
        "Вы уверены?",
        "Подтверждение Poweroff (ATX)",
        MB_YESNO | MB_ICONQUESTION
    ) == IDYES )
    {
        SendCommand( "poweroff" );
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::TestExecute(TObject *Sender)
{
    SendCommand( "test" );
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::TaskManagerFullCmdExecute(TObject *Sender)
{
    SendCommand( "tasklistfull" );
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::StopPunisherExecute(TObject *Sender)
{
    if( Application->MessageBox(
        "Вы уверены?",
        "Подтверждение Stop Punisher",
        MB_YESNO | MB_ICONQUESTION
    ) == IDYES )
    {
        SendCommand( "stop" );
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::WallpaperCmdExecute(TObject *Sender)
{
    AnsiString host = lvComps->Selected->Caption;

    frmWallpaper->m_strInitialDir = "\\\\" + host + "\\" + "c$";
    frmWallpaper->m_strHost = host;
    frmWallpaper->Caption = "Wallpaper on " + host;
    if( frmWallpaper->ShowModal() != mrOk ) return;

    _di_IXMLNode cmd = CreateCommand( "wallpaper" );
    cmd->Attributes[ WideString( "path" ) ] = WideString( frmWallpaper->m_strPath );
    cmd->Attributes[ WideString( "params" ) ] = WideString( frmWallpaper->m_strParams );
    SendCommandToSelected();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::RunAsCmdExecute(TObject *Sender)
{
    AnsiString host = lvComps->Selected->Caption;

    frmPath->m_strInitialDir = "\\\\" + host + "\\" + "c$";
    frmPath->Caption = "Run As " + host;
    frmPath->m_strHost = host;
    if( frmPath->ShowModal() != mrOk ) return;

    _di_IXMLNode cmd = CreateCommand( "runas" );
    cmd->Attributes[ WideString( "cmdline" ) ]  = WideString( frmPath->m_strPath );
    cmd->Attributes[ WideString( "user" ) ]     = WideString( frmPath->m_strUser );
    cmd->Attributes[ WideString( "password" ) ] = WideString( frmPath->m_strPassword );
    cmd->Attributes[ WideString( "domain" ) ]   = WideString( frmPath->m_strDomain );
    SendCommandToSelected();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::DebugExecute(TObject *Sender)
{
    frmDebug->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::LockWorkstationCmdExecute(TObject *Sender)
{
    SendCommand( "lockworkstation" );
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::KillAllCmdExecute(TObject *Sender)
{
    AnsiString pname = InputBox( "KillAll", "Процесс: ", "" );

    if( pname == "" ) return;
    _di_IXMLNode cmd = CreateCommand( "killall" );
    cmd->Attributes[ WideString( "pname" ) ]  = WideString( pname );
    SendCommandToSelected();
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
#ifndef mainH
#define mainH

#define TL_SHORT 0
#define TL_FULL  1

//---------------------------------------------------------------------------
#define NO_WIN32_LEAN_AND_MEAN
#include <objbase.h>
#include <wininet.h>
#include <shlobj.h>
#include <tlhelp32.hpp>
#include <SysUtils.hpp>
#include <Classes.hpp>
#include <SvcMgr.hpp>
#include <vcl.h>
#include <NMSTRM.hpp>
#include <Psock.hpp>
#include <msxmldom.hpp>
#include <XMLDoc.hpp>
#include <xmldom.hpp>
#include <XMLIntf.hpp>
//---------------------------------------------------------------------------
class TPunisherService : public TService
{
__published:    // IDE-managed Components
    TXMLDocument *xmlIn;
    TNMStrm *strmP;
    TNMStrmServ *ssP;
    TXMLDocument *xmlOut;
    void __fastcall ssPMSG(TComponent *Sender, const AnsiString sFrom,
          TStream *strm);
    void __fastcall ServiceStart(TService *Sender, bool &Started);
private:        // User declarations
        int lastmode;
public:         // User declarations
	__fastcall TPunisherService(TComponent* Owner);
	TServiceController __fastcall GetServiceController(void);
    void __fastcall DoCommand();
    AnsiString __fastcall GetCmdAttr( AnsiString attrname );
    AnsiString __fastcall GetCmdType();
    void __fastcall SendResp();
    _di_IXMLNode __fastcall CreateResp(AnsiString resptype);
    void __fastcall CreateProcessList(_di_IXMLNode node, int mode = TL_SHORT );
    void __fastcall KillProcess(DWORD pid);

	friend void __stdcall ServiceController(unsigned CtrlCode);
};
//---------------------------------------------------------------------------
extern PACKAGE TPunisherService *PunisherService;
//---------------------------------------------------------------------------
#endif

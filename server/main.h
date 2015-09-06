//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <msxmldom.hpp>
#include <NMSTRM.hpp>
#include <Psock.hpp>
#include <XMLDoc.hpp>
#include <xmldom.hpp>
#include <XMLIntf.hpp>
#include <ComCtrls.hpp>
#include <ImgList.hpp>
#include <Menus.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <ActnList.hpp>
//---------------------------------------------------------------------------
class TfrmMain : public TForm
{
__published:	// IDE-managed Components
    TNMStrmServ *ssP;
    TXMLDocument *xmlOut;
    TXMLDocument *xmlIn;
    TNMStrm *strmSend;
    TXMLDocument *xmlCfg;
    TGroupBox *GroupBox1;
    TListView *lvComps;
    TImageList *Images;
    TPopupMenu *PopupMenu1;
    TMenuItem *Shutdown1;
    TMemo *log;
    TMenuItem *Logoff1;
    TMenuItem *Restart1;
    TMenuItem *TaskManager1;
    TMenuItem *N2;
    TBevel *Bevel1;
    TLabel *Label1;
    TActionList *ActionList1;
    TAction *Logoffcmd;
    TAction *RebootCmd;
    TAction *ShutdownCmd;
    TAction *TaskManagerCmd;
    TAction *Exit;
    TImageList *ImageListBtns;
    TBitBtn *BitBtn1;
    TAction *SndMsgCmd;
    TMenuItem *Sendmessage1;
    TAction *PoweroffCmd;
    TMenuItem *PoweroffATX1;
    TAction *Test;
    TMenuItem *Test1;
    TAction *TaskManagerFullCmd;
    TMenuItem *N3;
    TAction *StopPunisher;
    TMenuItem *StopPunisher1;
    TAction *WallpaperCmd;
    TMenuItem *Wallpaper1;
    TMenuItem *Off1;
    TMenuItem *N5;
    TMenuItem *TaskManager2;
    TMenuItem *N1;
    TAction *RunAsCmd;
    TMenuItem *Open1;
    TMenuItem *N4;
        TBitBtn *BitBtn2;
        TAction *Debug;
    TAction *LockWorkstationCmd;
    TMenuItem *Lock1;
    TAction *KillAllCmd;
    TMenuItem *KillAll1;
    TMenuItem *N6;
    void __fastcall ssPMSG(TComponent *Sender,
          const AnsiString sFrom, TStream *strm);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall logChange(TObject *Sender);
    void __fastcall LogoffcmdExecute(TObject *Sender);
    void __fastcall RebootCmdExecute(TObject *Sender);
    void __fastcall ShutdownCmdExecute(TObject *Sender);
    void __fastcall TaskManagerCmdExecute(TObject *Sender);
    void __fastcall ExitExecute(TObject *Sender);
    void __fastcall SndMsgCmdExecute(TObject *Sender);
    void __fastcall PoweroffCmdExecute(TObject *Sender);
    void __fastcall TestExecute(TObject *Sender);
    void __fastcall TaskManagerFullCmdExecute(TObject *Sender);
    void __fastcall StopPunisherExecute(TObject *Sender);
    void __fastcall WallpaperCmdExecute(TObject *Sender);
    void __fastcall RunAsCmdExecute(TObject *Sender);
    void __fastcall DebugExecute(TObject *Sender);
    void __fastcall LockWorkstationCmdExecute(TObject *Sender);
    void __fastcall KillAllCmdExecute(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TfrmMain(TComponent* Owner);
    void __fastcall ProcessRequest(AnsiString host);
    void __fastcall FillList();
    void __fastcall SendCommand(AnsiString cmdtype);
    bool __fastcall SendCommandTo(AnsiString comp, TXMLDocument *xmlCmd);
    void __fastcall Log(TXMLDocument * xml);
    AnsiString __fastcall GetRespAttr();
    void __fastcall CmdKillProcess(AnsiString pid);
    _di_IXMLNode __fastcall CreateCommand(AnsiString cmdtype);
    void __fastcall SendCommandToSelected();
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMain *frmMain;
//---------------------------------------------------------------------------
#endif

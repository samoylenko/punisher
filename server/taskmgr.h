//---------------------------------------------------------------------------

#ifndef taskmgrH
#define taskmgrH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <Buttons.hpp>
#include <msxmldom.hpp>
#include <XMLDoc.hpp>
#include <xmldom.hpp>
#include <XMLIntf.hpp>
#include <ActnList.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TfrmTaskMgr : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *GroupBox1;
    TStringGrid *sgT;
    TBitBtn *BitBtn2;
    TActionList *ActionList1;
    TAction *ToMainWnd;
    TAction *FullPath;
    TPopupMenu *PopupMenu2;
    TMenuItem *N1;
    TBitBtn *BitBtn1;
    TBitBtn *BitBtn3;
    TAction *Kill;
    TMenuItem *N2;
    void __fastcall ToMainWndExecute(TObject *Sender);
    void __fastcall FullPathExecute(TObject *Sender);
    void __fastcall KillExecute(TObject *Sender);
    void __fastcall sgTMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
private:	// User declarations
public:		// User declarations
    __fastcall TfrmTaskMgr(TComponent* Owner);
    void __fastcall FillTasks(AnsiString host, TXMLDocument* xmlIn);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmTaskMgr *frmTaskMgr;
//---------------------------------------------------------------------------
#endif

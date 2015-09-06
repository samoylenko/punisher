//---------------------------------------------------------------------------

#ifndef debugH
#define debugH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <ActnList.hpp>
//---------------------------------------------------------------------------
class TfrmDebug : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *GroupBox1;
    TBitBtn *BitBtn1;
    TBitBtn *BitBtn2;
    TBevel *Bevel1;
    TLabel *Label1;
    TMemo *dbg;
    TActionList *ActionList1;
    TAction *Close;
    TAction *Send;
    void __fastcall SendExecute(TObject *Sender);
    void __fastcall CloseExecute(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TfrmDebug(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmDebug *frmDebug;
//---------------------------------------------------------------------------
#endif

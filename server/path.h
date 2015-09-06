//---------------------------------------------------------------------------

#ifndef pathH
#define pathH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ActnList.hpp>
#include <msxmldom.hpp>
#include <XMLDoc.hpp>
#include <xmldom.hpp>
#include <XMLIntf.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmPath : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *GroupBox1;
    TComboBox *cbPath;
    TBitBtn *BitBtn1;
    TBitBtn *BitBtn2;
    TActionList *ActionList1;
    TAction *Ok;
    TAction *Cancel;
    TLabel *Label1;
    TBitBtn *BitBtn3;
    TAction *Browse;
    TLabel *Label3;
    TEdit *edtUser;
    TBevel *Bevel1;
    TLabel *Label4;
    TEdit *edtDomain;
    TLabel *Label5;
    TEdit *edtPassword;
    void __fastcall OkExecute(TObject *Sender);
    void __fastcall CancelExecute(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall BrowseExecute(TObject *Sender);
private:	// User declarations
public:
    AnsiString m_strPath;
    AnsiString m_strParams;
    AnsiString m_strHost;
    AnsiString m_strInitialDir;
    AnsiString m_strUser;
    AnsiString m_strPassword;
    AnsiString m_strDomain;
    __fastcall TfrmPath(TComponent* Owner);
    void __fastcall InitPath( _di_IXMLNode paths );
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmPath *frmPath;
//---------------------------------------------------------------------------
#endif

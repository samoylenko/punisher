//---------------------------------------------------------------------------

#ifndef wallpaperH
#define wallpaperH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ActnList.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <msxmldom.hpp>
#include <XMLDoc.hpp>
#include <xmldom.hpp>
#include <XMLIntf.hpp>
//---------------------------------------------------------------------------
class TfrmWallpaper : public TForm
{
__published:    // IDE-managed Components
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
    TRadioGroup *rgParams;
    TLabel *Label2;
    void __fastcall OkExecute(TObject *Sender);
    void __fastcall CancelExecute(TObject *Sender);
    void __fastcall BrowseExecute(TObject *Sender);
private:    // User declarations
public:
    AnsiString m_strPath;
    AnsiString m_strParams;
    AnsiString m_strInitialDir;
    AnsiString m_strHost;       // User declarations
    __fastcall TfrmWallpaper(TComponent* Owner);
    void __fastcall InitWallpaper( _di_IXMLNode paths );
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmWallpaper *frmWallpaper;
//---------------------------------------------------------------------------
#endif

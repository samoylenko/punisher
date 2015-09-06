//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "wallpaper.h"
#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmWallpaper *frmWallpaper;
//---------------------------------------------------------------------------
__fastcall TfrmWallpaper::TfrmWallpaper(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmWallpaper::OkExecute(TObject *Sender)
{
    AnsiString params[] = {
        "stretch",
        "tile",
        "center"
    };

    m_strParams = params[ rgParams->ItemIndex ];
    m_strPath   = cbPath->Text;
    ModalResult = mrOk;
}
//---------------------------------------------------------------------------

void __fastcall TfrmWallpaper::CancelExecute(TObject *Sender)
{
    ModalResult = mrCancel;
}
//---------------------------------------------------------------------------

void __fastcall TfrmWallpaper::BrowseExecute(TObject *Sender)
{
    TOpenDialog *odPath = new TOpenDialog( this );
    odPath->Options << ofHideReadOnly << ofPathMustExist << ofFileMustExist << ofEnableSizing << ofForceShowHidden;

    odPath->InitialDir = m_strInitialDir;
    if( !odPath->Execute() ) return;

    AnsiString path = odPath->FileName;
    if( path.SubString( 1 , m_strInitialDir.Length() ) == m_strInitialDir )
    {
        path.Delete( 1, m_strInitialDir.Length() );
        path = "c:" + path;
    }
    cbPath->Text = path;

    delete odPath;
}
//---------------------------------------------------------------------------

void __fastcall TfrmWallpaper::InitWallpaper( _di_IXMLNode paths )
{
    cbPath->Items->Clear();

    for( int i = 1; i <= paths->ChildNodes->Count; i++ )
    {
        cbPath->Items->Add( AnsiString( paths->ChildNodes->Nodes[ i - 1 ]->Text ) );
    }

    cbPath->Text = cbPath->Items->Strings[0];
}

//---------------------------------------------------------------------------


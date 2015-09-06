//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "path.h"
#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmPath *frmPath;
//---------------------------------------------------------------------------
__fastcall TfrmPath::TfrmPath(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmPath::OkExecute(TObject *Sender)
{
    m_strPath     = cbPath->Text;
    m_strUser     = edtUser->Text;
    m_strPassword = edtPassword->Text;
    m_strDomain   = edtDomain->Text;

    ModalResult = mrOk;
}
//---------------------------------------------------------------------------
void __fastcall TfrmPath::CancelExecute(TObject *Sender)
{
    ModalResult = mrCancel;    
}
//---------------------------------------------------------------------------

void __fastcall TfrmPath::FormClose(TObject *Sender, TCloseAction &Action)
{
    edtPassword->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TfrmPath::BrowseExecute(TObject *Sender)
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

void __fastcall TfrmPath::InitPath( _di_IXMLNode paths )
{
    cbPath->Items->Clear();

    for( int i = 1; i <= paths->ChildNodes->Count; i++ )
    {
        cbPath->Items->Add( AnsiString( paths->ChildNodes->Nodes[ i - 1 ]->Text ) );
    }

    cbPath->Text = cbPath->Items->Strings[0];
}
//---------------------------------------------------------------------------


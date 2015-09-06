//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "debug.h"
#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmDebug *frmDebug;
//---------------------------------------------------------------------------
__fastcall TfrmDebug::TfrmDebug(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmDebug::SendExecute(TObject *Sender)
{
    frmMain->xmlOut->XML->Clear();
    for( int i = 0; i < dbg->Lines->Count; i++ )
    {
        frmMain->xmlOut->XML->Add( dbg->Lines->Strings[i] );
    }
    frmMain->xmlOut->Active = true;
    frmMain->SendCommandToSelected();
    ModalResult = mrOk;
}
//---------------------------------------------------------------------------
void __fastcall TfrmDebug::CloseExecute(TObject *Sender)
{
    ModalResult = mrCancel;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "taskmgr.h"
#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmTaskMgr *frmTaskMgr;
//---------------------------------------------------------------------------
__fastcall TfrmTaskMgr::TfrmTaskMgr(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TfrmTaskMgr::ToMainWndExecute(TObject *Sender)
{
    frmMain->Show();    
}
//---------------------------------------------------------------------------

void __fastcall TfrmTaskMgr::FullPathExecute(TObject *Sender)
{
    ShowMessage( sgT->Cells[3][ sgT->Row ] );
}
//---------------------------------------------------------------------------


void __fastcall TfrmTaskMgr::KillExecute(TObject *Sender)
{
    frmMain->CmdKillProcess( sgT->Cells[0][ sgT->Row ] );
}
//---------------------------------------------------------------------------

void __fastcall TfrmTaskMgr::FillTasks(AnsiString host, TXMLDocument* xmlIn)
{
    _di_IXMLNode tasks = xmlIn->DocumentElement;

    sgT->RowCount = 1;

    for( int i = 1; i <= tasks->ChildNodes->Count; i++ )
    {
        sgT->RowCount++;

        sgT->Cells[0][i] = tasks->ChildNodes->Nodes[ i - 1 ]->Attributes[ WideString( "pid" ) ];
        sgT->Cells[1][i] = tasks->ChildNodes->Nodes[ i - 1 ]->Attributes[ WideString( "processname" ) ];
        sgT->Cells[2][i] = tasks->ChildNodes->Nodes[ i - 1 ]->Attributes[ WideString( "modulename" ) ];
        sgT->Cells[3][i] = tasks->ChildNodes->Nodes[ i - 1 ]->Attributes[ WideString( "path" ) ];
    }

    sgT->Cells[0][0] = "Pid";
    sgT->Cells[1][0] = "Процесс";
    sgT->Cells[2][0] = "Название";
    sgT->Cells[3][0] = "Путь";
    sgT->FixedRows = 1;

    Caption = host + " :: Task Manager";
}
//---------------------------------------------------------------------------


void __fastcall TfrmTaskMgr::sgTMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    int Col, Row;
    sgT->MouseToCell( X, Y, Col, Row );
    sgT->Row = Row;    
}
//---------------------------------------------------------------------------


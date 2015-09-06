//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("main.cpp", frmMain);
USEFORM("taskmgr.cpp", frmTaskMgr);
USEFORM("path.cpp", frmPath);
USEFORM("wallpaper.cpp", frmWallpaper);
USEFORM("debug.cpp", frmDebug);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
         Application->Initialize();
         Application->Title = "Punisher Server";
         Application->CreateForm(__classid(TfrmMain), &frmMain);
         Application->CreateForm(__classid(TfrmTaskMgr), &frmTaskMgr);
         Application->CreateForm(__classid(TfrmPath), &frmPath);
         Application->CreateForm(__classid(TfrmWallpaper), &frmWallpaper);
         Application->CreateForm(__classid(TfrmDebug), &frmDebug);
         Application->Run();
    }
    catch (Exception &exception)
    {
         Application->ShowException(&exception);
    }
    catch (...)
    {
         try
         {
             throw Exception("");
         }
         catch (Exception &exception)
         {
             Application->ShowException(&exception);
         }
    }
    return 0;
}
//---------------------------------------------------------------------------

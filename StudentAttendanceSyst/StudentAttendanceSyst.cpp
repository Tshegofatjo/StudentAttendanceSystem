//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("StudAttendanceHistory.cpp", frmStudAttendanceHisrory);
USEFORM("StudTimeTable.cpp", frmTimeTable);
USEFORM("StudRegister.cpp", frmStudTimeTable);
USEFORM("Stud.cpp", frmStud);
USEFORM("DMStudentDB.cpp", DataModuleStudentDB); /* TDataModule: File Type */
USEFORM("ChangePassword.cpp", frmChangePassword);
USEFORM("ForgotPassword.cpp", frmForgotPasswork);
USEFORM("Register.cpp", frmRegister);
USEFORM("Home.cpp", frmHome);
USEFORM("Lecture.cpp", frmLecture);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{                    		Application->CreateForm(__classid(TDataModuleStudentDB), &DataModuleStudentDB);
		Application->CreateForm(__classid(TfrmHome), &frmHome);
		Application->CreateForm(__classid(TfrmChangePassword), &frmChangePassword);
		Application->CreateForm(__classid(TfrmForgotPasswork), &frmForgotPasswork);
		Application->CreateForm(__classid(TfrmRegister), &frmRegister);
		Application->CreateForm(__classid(TfrmStud), &frmStud);
		Application->CreateForm(__classid(TfrmStudTimeTable), &frmStudTimeTable);
		Application->CreateForm(__classid(TfrmStudAttendanceHisrory), &frmStudAttendanceHisrory);
		Application->CreateForm(__classid(TfrmTimeTable), &frmTimeTable);
		Application->CreateForm(__classid(TfrmLecture), &frmLecture);
		Application->Initialize();
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

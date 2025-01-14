//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Stud.h"
#include "Home.h"
#include "DMStudentDB.h"
#include "System.DateUtils.hpp"
#include "StudRegister.h"
#include "StudAttendanceHistory.h"
#include "StudTimeTable.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmStud *frmStud;
//---------------------------------------------------------------------------
__fastcall TfrmStud::TfrmStud(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmStud::FormResize(TObject *Sender)
{
	Panel3->Left=(this->Width/2-300)+50;
}
//---------------------------------------------------------------------------
void __fastcall TfrmStud::Timer1Timer(TObject *Sender)
{
   //	StatusBar1->Panels->operator [](0)->Text=FormatDateTime("'Date  ' dddd, mmmm d, yyyy 'Time ' hh:mm:ssss AM/PM",Now());

}
//---------------------------------------------------------------------------
void __fastcall TfrmStud::btnMarkRegisterClick(TObject *Sender)
{
	frmStudTimeTable->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfrmStud::Timer2Timer(TObject *Sender)
{
	StatusBar1->Panels->operator [](0)->Text=FormatDateTime("'Date  ' dddd, mmmm d, yyyy 'Time ' hh:mm:ssss AM/PM",Now());

}
//---------------------------------------------------------------------------

void __fastcall TfrmStud::btnViewRegisterClick(TObject *Sender)
{
	//
	frmStudAttendanceHisrory->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfrmStud::btnViewTimeTableClick(TObject *Sender)
{
      frmTimeTable->ShowModal();
}
//---------------------------------------------------------------------------


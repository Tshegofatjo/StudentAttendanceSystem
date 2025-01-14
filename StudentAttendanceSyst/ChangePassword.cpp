//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ChangePassword.h"
#include "DMStudentDB.h"
#include "Home.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmChangePassword *frmChangePassword;
//---------------------------------------------------------------------------
__fastcall TfrmChangePassword::TfrmChangePassword(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmChangePassword::FormShow(TObject *Sender)
{
//
		oldPassword="null";
//initialise flag global variables to 0/false
		Panel3->Font->Size=10;
		validIDNumber=0;
		validUserID=0;
		paaswordMtch=0;
        lblPasswordNoMatch->Font->Color=clRed;
		lblPasswordNoMatch->Caption="Passwords Do Not Match";
		lblInvalidOldPass->Caption="Invalid Old Password";
		lblInvalidOldPass->Visible=0;
		lblInvalidOldPass->Font->Color=clRed;
	  //configure displays
		lblInvalidUserID->Visible=0;
		lblIncorrectIDNumber->Visible=0;
		lblPasswordNoMatch->Visible=0;
	  //focus curser on edtUserID
	   Panel3->Visible=0;
	   lblIncorrectIDNumber->Caption="Invalid ID Number";
	   lblIncorrectIDNumber->Font->Color=clRed;
	   lblUserType->Caption= frmHome->lblUserType->Caption; //RadioGroupUserType->Items->operator [](frmHome->RadioGroupUserType->ItemIndex);
		lblInvalidUserID->Caption="Invalid "+lblUserType->Caption;
	   lblInvalidUserID->Font->Color=clRed;
	   Panel1->Caption="Fill In The Fields Below To change your Password " ;
	   //Panel3->Caption="NAME AND USERNumber";//+"Your Passord has been Successfully Changed";
	   edtUserID->SetFocus();

	   //lblInvalidUserID->Caption="Invalid "
}
//---------------------------------------------------------------------------
void __fastcall TfrmChangePassword::FormResize(TObject *Sender)
{
		/****configuration of frmHome Components
		*everytime the form is resized
		*@Author Rakoma TP
	*/

	Panel2 ->Left=frmChangePassword->Width/2-Panel2->Width/2;
	Panel2->Top=Panel1->Height+10;
	Panel1->Width=frmChangePassword->Width;
	Panel1->Top=0;
	Panel1->Left=0;


	Panel3->Left=Panel2->Left;
	Panel3->Width=Panel2->Width;
	Panel3->Top=Panel2->Top+Panel2->Height+10;
}
//---------------------------------------------------------------------------

void __fastcall TfrmChangePassword::btnGoBackToLoginClick(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmChangePassword::btnSaveChangesClick(TObject *Sender)
{
	//


	edtUserIDExit(this);
	  edtMatchPasswordExit(this);
	  edtIDNumberExit(this);
	   Panel3->Visible=0;

	  if(oldPassword==edtOldPass->Text.Trim()){


			if(paaswordMtch&&validIDNumber&&validUserID){

				DataModuleStudentDB->ADOCommandStudentDB->CommandText="UPDATE Users SET Passwords=:newPasss WHERE UserID=:UsrID ";
				DataModuleStudentDB->ADOCommandStudentDB->Parameters->ParamByName("newPasss")->Value=edtNewPassword->Text.Trim();
				DataModuleStudentDB->ADOCommandStudentDB->Parameters->ParamByName("UsrID")->Value=edtUserID->Text.Trim();
				DataModuleStudentDB->ADOCommandStudentDB->Execute();


				Panel3->Font->Color=clLime;
				Panel3->Caption=lblUserType->Caption+" "+edtUserID->Text+" "+"Your Password Was Successfully Changed";
				Panel3->Visible=1;
				DataModuleStudentDB->ADOCommandStudentDB->CommandText="UPDATE Users SET LastLogin=:currDateTim WHERE UserID=:UsrID ";
			DataModuleStudentDB->ADOCommandStudentDB->Parameters->ParamByName("currDateTim")->Value=FormatDateTime("dddd,mmm,d,yyyy,hh:mm:ssss AM/PM",Now());
			DataModuleStudentDB->ADOCommandStudentDB->Parameters->ParamByName("UsrID")->Value=edtUserID->Text.Trim();
			DataModuleStudentDB->ADOCommandStudentDB->Execute();
		  }
	  }else{
			 lblInvalidOldPass->Visible=1;
			Panel3->Font->Color=clRed;
			 Panel3->Caption="Your Password Was Not Successfully Changed";
			 Panel3->Visible=1;
		}

}
//---------------------------------------------------------------------------

void __fastcall TfrmChangePassword::edtUserIDEnter(TObject *Sender)
{
	edtUserID->Text="";
	lblInvalidUserID->Visible=0;
	Panel3->Visible=0;
}
//---------------------------------------------------------------------------

void __fastcall TfrmChangePassword::edtUserIDExit(TObject *Sender)
{
		DataModuleStudentDB->ADODataSetUser->Active=0;
		DataModuleStudentDB->ADODataSetUser->CommandText="SELECT * FROM Users WHERE UserID=:usrID";//+edtNumber;
		DataModuleStudentDB->ADODataSetUser->Parameters->ParamByName("usrID")->Value=edtUserID->Text.Trim();
		DataModuleStudentDB->ADODataSetUser->Active=1;
		oldPassword=DataModuleStudentDB->ADODataSetUser->FieldByName("Passwords")->AsString.Trim();

	//validate userid against idnumber

	if(DataModuleStudentDB->ADODataSetUser->RecordCount==0||edtUserID->Text.Trim().IsEmpty()){
		lblInvalidUserID->Visible=1;
		validUserID=0;
		oldPassword="null" ;
	}
	else {
		validUserID=1;
		lblInvalidUserID->Visible=0;
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmChangePassword::edtIDNumberEnter(TObject *Sender)
{
edtIDNumber->Text="";
	lblIncorrectIDNumber->Visible=0;
	Panel3->Visible=0;
}
//---------------------------------------------------------------------------

void __fastcall TfrmChangePassword::edtIDNumberExit(TObject *Sender)
{
	DataModuleStudentDB->ADODataSetUser->Active=0;
		DataModuleStudentDB->ADODataSetUser->CommandText="SELECT * FROM Users WHERE UserID=:usrID AND IDNumber=:IDNo";//+edtNumber;
		DataModuleStudentDB->ADODataSetUser->Parameters->ParamByName("usrID")->Value=edtUserID->Text.Trim();
		DataModuleStudentDB->ADODataSetUser->Parameters->ParamByName("IDNo")->Value=edtIDNumber->Text.Trim();
		DataModuleStudentDB->ADODataSetUser->Active=1;
	//validate userid against idnumber

	if(DataModuleStudentDB->ADODataSetUser->RecordCount==0||edtUserID->Text.Trim().IsEmpty()||
	 edtIDNumber->Text.Trim().IsEmpty()){

		validIDNumber=0;
		validUserID=0;
		lblIncorrectIDNumber->Visible=1;
		lblInvalidUserID->Visible=1;
	}
	else{
		validIDNumber=1;
		validUserID=1;
		lblIncorrectIDNumber->Visible=0;
		lblInvalidUserID->Visible=0;
	}

}
//---------------------------------------------------------------------------
void __fastcall TfrmChangePassword::edtMatchPasswordExit(TObject *Sender)
{
	if(edtMatchPassword->Text.Trim()==edtNewPassword->Text.Trim()&&!edtMatchPassword->Text.Trim().IsEmpty()&&!edtNewPassword->Text.Trim().IsEmpty()){
		paaswordMtch=1;
		lblPasswordNoMatch->Visible=0;
	}
	else {
		paaswordMtch=0 ;
		lblPasswordNoMatch->Visible=1;
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmChangePassword::edtNewPasswordEnter(TObject *Sender)
{
		 edtNewPassword->Clear();
		 edtMatchPassword->Clear();
		 lblPasswordNoMatch->Visible=0;
		 Panel3->Visible=0;
}
//---------------------------------------------------------------------------

void __fastcall TfrmChangePassword::edtMatchPasswordEnter(TObject *Sender)
{
	 edtMatchPassword->Clear();
	 lblPasswordNoMatch->Visible=0;
	 Panel3->Visible=0;
}
//---------------------------------------------------------------------------

void __fastcall TfrmChangePassword::edtOldPassEnter(TObject *Sender)
{
		edtOldPass->Text="";
		lblInvalidOldPass->Visible=0;
		Panel3->Visible=0;
}
//---------------------------------------------------------------------------

void __fastcall TfrmChangePassword::FormClose(TObject *Sender, TCloseAction &Action)

{
	frmHome->edtNumber->Text="";
	frmHome->edtPassword->Clear();
}
//---------------------------------------------------------------------------


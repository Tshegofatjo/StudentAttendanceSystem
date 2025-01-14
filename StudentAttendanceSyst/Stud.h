//---------------------------------------------------------------------------

#ifndef StudH
#define StudH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TfrmStud : public TForm
{
__published:	// IDE-managed Components
	TTimer *Timer1;
	TPanel *Panel3;
	TButton *btnMarkRegister;
	TButton *btnViewRegister;
	TButton *btnViewTimeTable;
	TStatusBar *StatusBar1;
	TTimer *Timer2;
	void __fastcall FormResize(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall btnMarkRegisterClick(TObject *Sender);
	void __fastcall Timer2Timer(TObject *Sender);
	void __fastcall btnViewRegisterClick(TObject *Sender);
	void __fastcall btnViewTimeTableClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfrmStud(TComponent* Owner);
		String studNumber;
	String subjCode;
	String startTime;
	String lessConcept;
	String classDay;

	bool ackn;
	bool rating;

};
//---------------------------------------------------------------------------
extern PACKAGE TfrmStud *frmStud;
//---------------------------------------------------------------------------
#endif

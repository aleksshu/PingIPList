//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ComCtrls.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdIcmpClient.hpp>
#include <IdRawBase.hpp>
#include <IdRawClient.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *StringGrid1;
	TButton *PingStartBtn;
	TButton *LoadBtn;
	TOpenDialog *OpenDialog1;
	TButton *SaveBtn;
	TStatusBar *StatusBar1;
	TEdit *TimeOutEdt;
	TLabel *TimeOut;
	TSaveDialog *SaveDialog1;
	TTimer *Timer1;
	TButton *StopPingBtn;
	TCheckBox *ScrolChkBx;
	void __fastcall PingStartBtnClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall LoadBtnClick(TObject *Sender);
        void __fastcall PingThrDone(TObject * Sender);
	void __fastcall SaveBtnClick(TObject *Sender);
        void __fastcall PingProc();
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall StopPingBtnClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

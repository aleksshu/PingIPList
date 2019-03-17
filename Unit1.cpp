//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
MyPingThread *PingThr;

int k;
int iTimeOut;

bool bStop = false;

char * cIPaddr;
wchar_t * wcIPaddr;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
 StringGrid1->ColWidths[0] = 150;
 StringGrid1->ColWidths[1] = 230;
 StringGrid1->Cells[0][0] = "IP address";
 StringGrid1->Cells[1][0] = "Ping result";

}


//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{

 cIPaddr = (char *)malloc(sizeof(char)*64);
 String cIPListFile = ExtractFilePath(Application->ExeName) + "\\IP.txt";

 if(!FileExists(cIPListFile)) {
  int handle = FileCreate(cIPListFile, fmOpenReadWrite, faArchive);
  FileClose(handle);
 }
 wcIPaddr = (wchar_t *)malloc(sizeof(wchar_t)*64);

  TStringList * IpList = new TStringList();
  try {
   IpList->LoadFromFile(cIPListFile);

  for(int i=0; i<IpList->Count ;i++) {
    StringGrid1->Cells[0][i+1] = IpList->Strings[i];
  }

  //StringGrid1->Rows[0]->Assign(IpList);

  } __finally { delete IpList; }


}

//---------------------------------------------------------------------------

void __fastcall TForm1::PingStartBtnClick(TObject *Sender)
{

 k=1;
 bStop = false;

 try {
  iTimeOut = StrToInt(TimeOutEdt->Text);
 }

 catch(...) { iTimeOut = 1000; }

 PingStartBtn->Enabled = false;
 LoadBtn->Enabled = false;
 SaveBtn->Enabled = false;
 StopPingBtn->Enabled = true;

 Timer1->Enabled = true;

 StatusBar1->Panels->Items[0]->Text = "Ping IP List - © Aleksandr Shulaev 04/2013 agardsel@inbox.ru         ";

 for(int i=1; StringGrid1->Cells[0][i]!="" ;i++) {
    StringGrid1->Cells[1][i] = "";  // очистка ping result
 }

 PingProc();

 //IdIcmpClient1->



}

//---------------------------------------------------------------------------

void __fastcall TForm1::LoadBtnClick(TObject *Sender)
{
 if(OpenDialog1->Execute()) {
   TStringList * IpList = new TStringList();
  try {
   IpList->LoadFromFile(OpenDialog1->FileName);

  for(int i=1; StringGrid1->Cells[0][i]!="" ;i++) {
    StringGrid1->Cells[0][i] = "";
    StringGrid1->Cells[1][i] = "";
  }

  for(int i=0; i<IpList->Count; i++) {
    StringGrid1->Cells[0][i+1] = IpList->Strings[i];
  }


  //StringGrid1->Rows[0]->Assign(IpList);

  } __finally { delete IpList; }
 }
}

//---------------------------------------------------------------------------


void __fastcall TForm1::PingThrDone(TObject * /*Sender*/)
{
 k++;
 if(!bStop) PingProc();

 else {
  PingStartBtn->Enabled = true;
  LoadBtn->Enabled = true;
  SaveBtn->Enabled = true;
  Timer1->Enabled = false;
 }
}

//--------------------------------------------------------------------------


void __fastcall TForm1::SaveBtnClick(TObject *Sender)
{
 if(SaveDialog1->Execute()) {
   TStringList * PingResultList = new TStringList();
  try {

  for(int i=1; StringGrid1->Cells[0][i]!=""; i++) {
    PingResultList->Add(StringGrid1->Cells[0][i] + " " + StringGrid1->Cells[1][i]);
  }


  PingResultList->SaveToFile(SaveDialog1->FileName);


  } __finally { delete PingResultList; }
 }
}

//---------------------------------------------------------------------------

void __fastcall TForm1::PingProc()
{
  if(StringGrid1->Cells[0][k]!="") {
   if(ScrolChkBx->Checked)  {
    StringGrid1->Row = k;
   }

   wcIPaddr = StringGrid1->Cells[0][k].c_str();
   wcstombs(cIPaddr , wcIPaddr, 64);

   PingThr = new MyPingThread(k, cIPaddr, iTimeOut, false);
   PingThr->OnTerminate = PingThrDone;
  }

  else {
    k=1;
    PingStartBtn->Enabled = true;
    LoadBtn->Enabled = true;
    SaveBtn->Enabled = true;
    Timer1->Enabled = false;

    StatusBar1->Panels->Items[0]->Text = "Ping IP List - accomplished";

  }
}
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
 String sRunText = StatusBar1->Panels->Items[0]->Text;


 // "Ping IP List - © Aleksandr Shulaev 04/2013 agardsel@inbox.ru";

 sRunText.Insert(String(sRunText[1]), sRunText.Length()+1);
 sRunText.Delete(1, 1);

 StatusBar1->Panels->Items[0]->Text = sRunText;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::StopPingBtnClick(TObject *Sender)
{
 bStop = true;
 StopPingBtn->Enabled = false;
}
//---------------------------------------------------------------------------


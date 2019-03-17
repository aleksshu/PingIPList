//---------------------------------------------------------------------------


#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit10.h"
#include "Unit1.h"
#include "Unit3.h"

#pragma package(smart_init)



//---------------------------------------------------------------------------


 char *fcIPaddr;
 int fk, fiTimeOut;
 String FStatus;

//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall TPingThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }

//---------------------------------------------------------------------------

//__fastcall TSensQueryThread::TSensQueryThread(......)
//	: TThread(false)

__fastcall MyPingThread :: MyPingThread(int k, char * cIPaddr, int iTimeOut, bool CreateSuspended) : TThread(CreateSuspended)
{
 fcIPaddr = (char *)malloc(sizeof(char)*64);

 Priority = tpNormal;

 fk = k;
 strcpy(fcIPaddr, cIPaddr);

 fiTimeOut = iTimeOut;

 FreeOnTerminate = true;
}


//---------------------------------------------------------------------------


void __fastcall MyPingThread::Execute()
{
	//---- Place thread code here ----
 String sPingRes;
 int iPingRes;
 WORD dwErrCode = 0;

 iPingRes = PingMy(fcIPaddr, fiTimeOut);

 if(iPingRes>0) {
  sPingRes = "OK, RTT " + IntToStr(iPingRes) + " ms";
 }
 else if(iPingRes > -4) {
  dwErrCode = GetLastError();

 switch( dwErrCode ) {
  case 11001 :
   sPingRes = "NoK, ErrCode " + IntToStr((int)dwErrCode) + ": Buffer Too Small";
   break;

  case 11002 :
   sPingRes = "NoK, ErrCode " + IntToStr((int)dwErrCode) + ": Destination Net Unreachable";
   break;

  case 11003 :
   sPingRes = "NoK, ErrCode " + IntToStr((int)dwErrCode) + ": Destination Host Unreachable";
   break;

  case 11004 :
   sPingRes = "NoK, ErrCode " + IntToStr((int)dwErrCode) + ": Destination Protocol Unreachable";
   break;

  case 11005 :
   sPingRes = "NoK, ErrCode " + IntToStr((int)dwErrCode) + ": Destination Port Unreachable";
   break;

  case 11006 :
   sPingRes = "NoK, ErrCode " + IntToStr((int)dwErrCode) + ": No Resources";
   break;

  case 11007 :
   sPingRes = "NoK, ErrCode " + IntToStr((int)dwErrCode) + ": Bad Option";
   break;

  case 11008 :
   sPingRes = "NoK, ErrCode " + IntToStr((int)dwErrCode) + ": Hardware Error";
   break;

  case 11009 :
   sPingRes = "NoK, ErrCode " + IntToStr((int)dwErrCode) + ": Packet Too Big";
   break;

  case 11010 :
   sPingRes = "NoK, ErrCode " + IntToStr((int)dwErrCode) + ": Request Timed Out";
   break;

  case 11011 :
   sPingRes = "NoK, ErrCode " + IntToStr((int)dwErrCode) + ": Bad Request";
   break;

  case 11012 :
   sPingRes = "NoK, ErrCode " + IntToStr((int)dwErrCode) + ": Bad Route";
   break;

  case 11013 :
   sPingRes = "NoK, ErrCode " + IntToStr((int)dwErrCode) + ": TimeToLive Expired Transit";
   break;

  case 11014 :
   sPingRes = "NoK, ErrCode " + IntToStr((int)dwErrCode) + ": TimeToLive Expired  Reassembly";
   break;

  case 11015 :
   sPingRes = "NoK, ErrCode " + IntToStr((int)dwErrCode) + ": Parameter Problem";
   break;

  case 11016 :
   sPingRes = "NoK, ErrCode " + IntToStr((int)dwErrCode) + ": Source Quench";
   break;

  case 11017 :
   sPingRes = "NoK, ErrCode " + IntToStr((int)dwErrCode) + ": Option Too Big";
   break;

  case 11018 :
   sPingRes = "NoK, ErrCode " + IntToStr((int)dwErrCode) + ": Bad Destination";
   break;

  case 11032 :
   sPingRes = "NoK, ErrCode " + IntToStr((int)dwErrCode) + ": Negotiating IPSEC";
   break;

  case 11050 :
   sPingRes = "NoK, ErrCode " + IntToStr((int)dwErrCode) + ": General Failure";
   break;
 }

 }

 else switch( iPingRes ) {
  case -11001 :
   sPingRes = "NoK, Status: Buffer Too Small";
   break;

  case -11002 :
   sPingRes = "NoK, Status: Destination Net Unreachable";
   break;

  case -11003 :
   sPingRes = "NoK, Status: Destination Host Unreachable";
   break;

  case -11004 :
   sPingRes = "NoK, Status: Destination Protocol Unreachable";
   break;

  case -11005 :
   sPingRes = "NoK, Status: Destination Port Unreachable";
   break;

  case -11006 :
   sPingRes = "NoK, Status: No Resources";
   break;

  case -11007 :
   sPingRes = "NoK, Status: Bad Option";
   break;

  case -11008 :
   sPingRes = "NoK, Status: Hardware Error";
   break;

  case -11009 :
   sPingRes = "NoK, Status: Packet Too Big";
   break;

  case -11010 :
   sPingRes = "NoK, Status: Request Timed Out";
   break;

  case -11011 :
   sPingRes = "NoK, Status: Bad Request";
   break;

  case -11012 :
   sPingRes = "NoK, Status: Bad Route";
   break;

  case -11013 :
   sPingRes = "NoK, Status: TimeToLive Expired Transit";
   break;

  case -11014 :
   sPingRes = "NoK, Status: TimeToLive Expired  Reassembly";
   break;

  case -11015 :
   sPingRes = "NoK, Status: Parameter Problem";
   break;

  case -11016 :
   sPingRes = "NoK, Status: Source Quench";
   break;

  case -11017 :
   sPingRes = "NoK, Status: Option Too Big";
   break;

  case -11018 :
   sPingRes = "NoK, Status: Bad Destination";
   break;

  case -11032 :
   sPingRes = "NoK, Status: Negotiating IPSEC";
   break;

  case -11050 :
   sPingRes = "NoK, Status: General Failure";
   break;
 }

 UpdateCell(sPingRes);



 /*
 	WSADATA wsaData;
        HINSTANCE hInstance;

	WSAStartup(WINSOCK_VERSION, &wsaData);

	if(DoPingOperation(hInstance)) {

          UpdateCell("Ok");
 }
 else {
   UpdateCell("Not ok");
 }

 */
	//MessageBox(NULL, szPingBuffer, "www.sources.ru", MB_OK|MB_ICONSTOP);

	WSACleanup();

}
//---------------------------------------------------------------------------


void __fastcall MyPingThread::UpdateCell(String Status)
{
 FStatus = Status;
 Synchronize(&DoUpdateCell);
}

//---------------------------------------------------------------------------

void __fastcall MyPingThread::DoUpdateCell()
{

 Form1->StringGrid1->Cells[1][fk] = FStatus;

}



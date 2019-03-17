//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>

//---------------------------------------------------------------------------

class MyPingThread : public TThread
{
private:
	void __fastcall DoUpdateCell();
protected:
	void __fastcall Execute();
        void __fastcall UpdateCell(String Status);

public:
	// __fastcall TSensQueryThread(......);

	__fastcall MyPingThread(int k, char * cIPaddr, int iTimeOut,  bool CreateSuspended);

};

//---------------------------------------------------------------------------
#endif

//---------------------------------------------------------------------------


#pragma hdrstop

#include "Unit10.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

#include <winsock2.h>
#include <iphlpapi.h>
#include <IcmpApi.h>

//#include <stdio.h>

#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "ws2_32.lib")

int PingMy(char *cIpaddr, int iT)
{
    // Declare and initialize variables
    
    HANDLE hIcmpFile;
	unsigned long ipaddr = INADDR_NONE;
    DWORD dwRetVal = 0;
    //WORD dwErrCode = 0;
    char SendData[32] = "Data Buffer";
    LPVOID ReplyBuffer = NULL;
    DWORD ReplySize = 0;
    
	/*// Validate the parameters
    if (argc != 2) {
        printf("usage: %s IP address\n", argv[0]);
        return 1;
	} */

    ipaddr = inet_addr(cIpaddr);
    if (ipaddr == INADDR_NONE) {
		//printf("usage: %s IP address\n", argv[0]);
		return -2;
    }
    
    hIcmpFile = IcmpCreateFile();
    if (hIcmpFile == INVALID_HANDLE_VALUE) {
		//printf("\tUnable to open handle.\n");
		//printf("IcmpCreatefile returned error: %ld\n", GetLastError() );
		return -3;
    }    

    ReplySize = sizeof(ICMP_ECHO_REPLY) + sizeof(SendData);
    ReplyBuffer = (VOID*) malloc(ReplySize);
    if (ReplyBuffer == NULL) {
		//printf("\tUnable to allocate memory\n");
		return -4;
    }    
    

    dwRetVal = IcmpSendEcho(hIcmpFile, ipaddr, SendData, sizeof(SendData),
        NULL, ReplyBuffer, ReplySize, iT);
    //dwErrCode = GetLastError();
	if (dwRetVal != 0) {
		PICMP_ECHO_REPLY pEchoReply = (PICMP_ECHO_REPLY)ReplyBuffer;
		//struct in_addr ReplyAddr;
        //ReplyAddr.S_un.S_addr = pEchoReply->Address;
		//printf("\tSent icmp message to %s\n", argv[1]);
		//if (dwRetVal > 1) {
			//printf("\tReceived %ld icmp message responses\n", dwRetVal);
			//printf("\tInformation from the first response:\n");
		//}
		//else {
			//printf("\tReceived %ld icmp message response\n", dwRetVal);
			//printf("\tInformation from this response:\n");
		//}

		//printf("\t  Received from %s\n", inet_ntoa( ReplyAddr ) );
		//printf("\t  Status = %ld\n",
			//pEchoReply->Status);
                if(pEchoReply->Status==0) {
                 return pEchoReply->RoundTripTime;
                }
		//printf("\t  Roundtrip time = %ld milliseconds\n",
			//pEchoReply->RoundTripTime);
                else {
                 return -(pEchoReply->Status);
                }

	}
	else {
		//printf("\tCall to IcmpSendEcho failed.\n");
		//printf("\tIcmpSendEcho returned error: %ld\n", GetLastError() );
		return -1;
        }
	return 0; 	 
}

#include <stdio.h>
#include <assert.h>

#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include "..//include//socket_api_low.h"
#include "..//include//socket_api_high.h"

#ifdef _WIN32

#define _WINSOCKAPI_

#ifndef _WIN32_WINNT              // Allow use of features specific to Windows XP or later.
#define _WIN32_WINNT 0x0501       // Change this to the appropriate value to target other versions of Windows.
#endif

#include <mstcpip.h>
#include <windows.h>	// for SetThreadAffinityMask()

#else

#include <sys/ioctl.h>
#include <net/if.h>
#include <time.h>

#endif

#ifdef __linux__
#include <netinet/tcp.h>
#endif

static struct in_addr localIp;

//	if (localPort == 0)	localPort = anyPort;
int CreateTcpClient(SOCKET* pSock, const char *serverIp, unsigned short localPort, unsigned short serverPort)
{
	int result = 0;
	struct sockaddr_in localAddr;
	struct sockaddr_in serverAddr;

	if (0 == pSock)
	{
		return -1;
	}

	if ((INADDR_NONE == inet_addr(serverIp)) || (0 == serverPort))
	{
		return -1;
	}

	result = SocketApiInit();
	if (result < 0)
	{
		return -1;
	}

	result = Socket(pSock, PF_INET, SOCK_STREAM, 0);
	if (result < 0)
	{
		result = SocketApiClose();
		if (result < 0)
		{
			return -1;
		}

		return -1;
	}

	memset(&localAddr, 0, sizeof(localAddr));

	localAddr.sin_family = AF_INET;
	localAddr.sin_port = htons(localPort);
	localAddr.sin_addr.s_addr = htonl(INADDR_ANY);

	result = Bind(*pSock, (const struct sockaddr*)&localAddr, sizeof(localAddr));
	if (result < 0)
	{
		result = CloseSock(*pSock);
		if (ESOCKENOTSOCK == result)	// Считаем, что из другого потока была вызвана функция
		{								// DestroySock(), а в ней CloseSock() для этого сокета. 
			return -1;					// CloseSock() успешно завершилась, что вызвало эту ошибку.
		}								// В DestroySock() будет происходить вызов SocketApiClose(), 
										// поэтому его не вызываем в этом потоке, а сразу выходим
		result = SocketApiClose();
		if (result < 0)
		{
			return -1;
		}

		return -1;
	}

	memset(&serverAddr, 0, sizeof(serverAddr));

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(serverPort);
	serverAddr.sin_addr.s_addr = inet_addr(serverIp);

	result = Connect(*pSock, (const struct sockaddr*)&serverAddr, sizeof(serverAddr));
	if (result < 0)
	{
		result = CloseSock(*pSock);
		if ((ESOCKENOTSOCK == result) || (ESOCKNOTINITIALISED == result))	// Считаем, что из другого потока была вызвана функция
		{								// DestroySock(), а в ней CloseSock() для этого сокета. 
			return -1;					// CloseSock() успешно завершилась, что вызвало эту ошибку.
		}								// В DestroySock() будет происходить вызов SocketApiClose(), 
										// поэтому его не вызываем в этом потоке, а сразу выходим
		result = SocketApiClose();
		if (result < 0)
		{
			return -1;
		}
		return -1;
	}

	return 0;
}


int CreateListenSock(SOCKET* pSock, unsigned short port, const char* pIp)
{
	int result = 0;
	struct sockaddr_in myAddr;
	
	if ((0 == pSock) || (0 == port))
	{
		return -1;
	}

	result = SocketApiInit();
	if (result < 0)
	{
		return -1;
	}
	
	memset(&myAddr, 0, sizeof(myAddr));

	if (0 == pIp)
	{
		myAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	}
	else
	{
		myAddr.sin_addr.s_addr = inet_addr(pIp);
		if (INADDR_NONE == myAddr.sin_addr.s_addr)
		{
			result = SocketApiClose();
			if (result < 0)
			{
				return -1;
			}
			return -1;
		}
	}
	myAddr.sin_family = AF_INET;
	myAddr.sin_port = htons(port);

	result = Socket(pSock, PF_INET, SOCK_STREAM, 0);
	if (result < 0)
	{
		result = SocketApiClose();
		if (result < 0)
		{
			return -1;
		}
		return -1;
	}

	result = Bind(*pSock, (struct sockaddr*)&myAddr, sizeof(myAddr));
	if (result < 0)
	{
		result = CloseSock(*pSock);
		if (ESOCKENOTSOCK == result)	// Считаем, что из другого потока была вызвана функция
		{								// DestroySock(), а в ней CloseSock() для этого сокета. 
			return -1;					// CloseSock() успешно завершилась, что вызвало эту ошибку.
		}								// В DestroySock() будет происходить вызов SocketApiClose(), 
										// поэтому его не вызываем в этом потоке, а сразу выходим
		result = SocketApiClose();
		if (result < 0)
		{
			return -1;
		}

		return -1;
	}

	result = Listen(*pSock, LISTEN_QUEUE_LENGTH);
	if (result < 0)
	{
		result = CloseSock(*pSock);
		if (ESOCKENOTSOCK == result)	// Считаем, что из другого потока была вызвана функция
		{								// DestroySock(), а в ней CloseSock() для этого сокета. 
			return -1;					// CloseSock() успешно завершилась, что вызвало эту ошибку.
		}								// В DestroySock() будет происходить вызов SocketApiClose(), 
										// поэтому его не вызываем в этом потоке, а сразу выходим
		result = SocketApiClose();
		if (result < 0)
		{
			return -1;
		}

		return -1;
	}

	return 0;
}

int WaitForClient(SOCKET lisSock, SOCKET* pConSock)
{
	int result = 0;
	int opt = 0;

	if (0 == pConSock)
	{
		return -1;
	}

	result = SocketApiInit();
	if (result < 0)
	{
		return -1;
	}

	result = -1;
	while(result < 0)
	{
		result = Accept(pConSock, lisSock, 0, 0);
		if (result < 0)
		{
			if (ESOCKEINTR == result)
			{
				continue;
			}
			else
			{
				SocketApiClose();
				return -1;
			}
		}

		opt = TCP_SEND_BUF_SIZE;
		result = setsockopt(*pConSock, SOL_SOCKET, SO_SNDBUF, (char*)&opt, sizeof(opt));
		if (0 != result)
		{
			return -1;
		}

		opt = TCP_RECV_BUF_SIZE;
		result = setsockopt(*pConSock, SOL_SOCKET, SO_RCVBUF, (char*)&opt, sizeof(opt));
		if (0 != result)
		{
			return -1;
		}
	}
	return 0;
}

int DestroySock(SOCKET s)
{
	int result = 0;

	result = CloseSock(s);
	if (result < 0)
	{
		if ((ESOCKENOTSOCK == result) || (ESOCKNOTINITIALISED == result))
		{
			return 0;
		}
		else
		{
			return -1;
		}
	}

	result = SocketApiClose();
	if (result < 0)
	{
		return -1;
	}
	return 0;
}

int CreateUdpSock(SOCKET* pSock, const char* pIpAddr, unsigned short myPort)
{
	int result = 0;
	int opt = 0;
	struct sockaddr_in myAddr;

	if (0 == pSock)
	{
		return -1;
	}

	result = SocketApiInit();
	if (result < 0)
	{
		return -1;
	}

	memset(&myAddr, 0, sizeof(myAddr));

	if (0 == pIpAddr)
	{
		myAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	}
	else
	{
		myAddr.sin_addr.s_addr = inet_addr(pIpAddr);
		if (INADDR_NONE == myAddr.sin_addr.s_addr)
		{
			SocketApiClose();
			return -1;
		}
	}

	myAddr.sin_family = AF_INET;
	if (0 != myPort)
	{
		myAddr.sin_port = htons(myPort);
	}
	else
	{
		myAddr.sin_port = htons(0);
	}

	result = Socket(pSock, PF_INET, SOCK_DGRAM, 0);
	if (result < 0)
	{
		SocketApiClose();
		return -1;
	}

	result = Bind(*pSock, (const struct sockaddr*)&myAddr, sizeof(myAddr));
	if (result < 0)
	{
		CloseSock(*pSock);
		SocketApiClose();
		return -1;
	}

	opt = UDP_SEND_BUF_SIZE;
	result = setsockopt(*pSock, SOL_SOCKET, SO_SNDBUF, (char*)&opt, sizeof(opt));
	if (0 != result)
	{
		return -1;
	}

	opt = UDP_RECV_BUF_SIZE;
	result = setsockopt(*pSock, SOL_SOCKET, SO_RCVBUF, (char*)&opt, sizeof(opt));
	if (0 != result)
	{
		return -1;
	}

	return 0;
}

int GetLocalIp(struct in_addr* pIp)
{
#ifdef _WIN32
	int result = 0;
	char name[SOCKET_COMP_NAME_LEN] = {0};
	struct hostent* h;
	const int channel = 0;

	if (0 == pIp)
	{
		return -1;
	}

	if (0 != localIp.s_addr)
	{
		pIp->s_addr = localIp.s_addr;
		return 0;
	}
	else
	{
		result = SocketApiInit();
		if (result < 0)
		{
			return -1;
		}

		result = gethostname(name, SOCKET_COMP_NAME_LEN);
		if (0 != result)
		{
			return -1;
		}

		h = gethostbyname(name);
		if (0 == h)
		{
			return -1;
		}

		localIp.s_addr = (*((struct in_addr*)(h->h_addr_list[channel]))).s_addr;

		result = SocketApiClose();
		if (result < 0)
		{
			localIp.s_addr = 0;
			return -1;
		}
		pIp->s_addr = localIp.s_addr;

		return 0;
	}
#else
	int result = 0;

	char* pEthCardName = 0;
	pEthCardName = ETH_CARD_NAME;

	if (0 == pIp)
	{
		return -1;
	}

	if (0 != localIp.s_addr)
	{
		pIp->s_addr = localIp.s_addr;
		return 0;
	}
	else
	{

		if (0 == pEthCardName)
		{
			return -1;
		}

		result = GetEthCardIp(pIp, pEthCardName);
		if (0 != result)
		{
			return -1;
		}

		localIp.s_addr = pIp->s_addr;
		return 0;
	}

#endif
}

#ifndef _WIN32
int GetEthCardIp(struct in_addr* pIp, char* pEthCardName)
{
	struct ifreq ifr;
	SOCKET s;
	struct sockaddr_in *sa;
	int result = 0;

	if ((0 == pIp) || (0 == pEthCardName))
	{
		return -1;
	}

	memset(&ifr, 0, sizeof(ifr));
	strcpy(ifr.ifr_name, pEthCardName);

	s = socket(PF_INET, SOCK_DGRAM, 0);
	if ((-1) == s)
	{
		return -1;
	}

	result = ioctl(s, SIOCGIFADDR, &ifr);
	if (-1 == result)
	{
		return -1;
	}

	result = close(s);
	if (0 != result)
	{
		return -1;
	}

	sa = (struct sockaddr_in*)&ifr.ifr_addr;
	pIp->s_addr = sa->sin_addr.s_addr;

	return 0;
}
#endif

int SendTcp(SOCKET s, const char* pBuf, unsigned int len, int flags)
{
	unsigned int sendLen = 0;
	int result = 0;

	if (0 == pBuf)
	{
		return -1;
	}

	while (sendLen != len)
	{
		result = Send(s, &pBuf[0], len, flags);
		if (result <= 0)
		{
			if (ESOCKEINTR != result)
			{
				return -1;
			}
		}
		else
		{
			sendLen += result;
		}
	}

	return sendLen;
}

int RecvTcp(SOCKET s, char* pBuf, unsigned int len, int flags)
{
	unsigned int recvLen = 0;
	int result = 0;

	if (0 == pBuf)
	{
		return -1;
	}

	while (recvLen != len)
	{
		result = Recv(s, &pBuf[recvLen], (len - recvLen), flags);
		if (result <= 0)
		{
			if (ESOCKEINTR != result)
			{
				return -1;
			}
		}
		else
		{
			recvLen += result;
		}
	}

	return recvLen;
}

int HostToNet(char* pData, unsigned int len, DATATYPE dataType)
{
	unsigned int i;
	int test = 1;
	int result;
	unsigned int temp_uint;
	int* pTest = &test;

	if (0 == pData)
	{
		return -1;
	}

	result = ValidDataConv(len, dataType);
	if (0 != result)
	{
		return -1;
	}

	if (0 == *((char*)pTest))	// если это багетоподобная машина, то ничего не переворачивать!
	{
		return 0;
	}

	if (0 == len)
	{
		return 0;
	}

	switch (dataType)
	{
		case DT_1_BYTE:		break;		// char

		case DT_2_BYTE:		for (i = 0; i < len / sizeof(short); i++)
							{
								*(((unsigned short*)pData) + i) = htons(*(((unsigned short*)pData) + i));
							}	
							break;		// short

		case DT_4_BYTE:		for (i = 0; i < len / sizeof(int); i++)
							{
								*(((unsigned int*)pData) + i) = htonl(*(((unsigned int*)pData) + i));
							}
							break;		// int, long, float

		case DT_8_BYTE:		for (i = 0; i < len / sizeof(double); i++)
							{
								temp_uint = htonl(*((unsigned int*)(pData + i*sizeof(double))));
								*((unsigned int*)(pData + i*sizeof(double))) = htonl(*((unsigned int*)(pData + i*sizeof(double) + sizeof(unsigned int))));
								*((unsigned int*)(pData + i*sizeof(double) + sizeof(unsigned int))) = temp_uint;
							}
							break;		// double, long long

		default:			return -1;
	}

	return 0;
}


int NetToHost(char* pData, unsigned int len, DATATYPE dataType)
{
	unsigned int i;
	int result;
	int test = 1;
	unsigned int temp_uint;
	int* pTest = &test;

	if (0 == pData)
	{
		return -1;
	}

	result = ValidDataConv(len, dataType);
	if (0 != result)
	{
		return -1;
	}

	if (0 == *((char*)pTest))	// если это багетоподобная машина, то ничего не переворачивать!
	{
		return 0;
	}

	if (0 == len)
	{
		return 0;
	}

	switch (dataType)
	{
		case DT_1_BYTE:		break;		// char

		case DT_2_BYTE:		for (i = 0; i < len / sizeof(short); i++)
							{
								*(((unsigned short*)pData) + i) = ntohs(*(((unsigned short*)pData) + i));
							}	
							break;		// short

		case DT_4_BYTE:		for (i = 0; i < len / sizeof(int); i++)
							{
								*(((unsigned int*)pData) + i) = ntohl(*(((unsigned int*)pData) + i));
							}
							break;		// int, long, float

		case DT_8_BYTE:		for (i = 0; i < len / sizeof(double); i++)
							{
								temp_uint = htonl(*((unsigned int*)(pData + i*sizeof(double))));
								*((unsigned int*)(pData + i*sizeof(double))) = htonl(*((unsigned int*)(pData + i*sizeof(double) + sizeof(unsigned int))));
								*((unsigned int*)(pData + i*sizeof(double) + sizeof(unsigned int))) = temp_uint;
							}
							break;		// double, long long

		default:			return -1;
	}

	return 0;
}

int SendUdp(SOCKET s, const char* pBuf, unsigned int len, int flags, const char *pToIp, unsigned short toPort)
{
	int sendLen;
	struct sockaddr_in addrTo;

	if ((0 == pBuf) || (0 == pToIp))
	{
		return -1;
	}

	memset(&addrTo, 0, sizeof(addrTo));
	
	addrTo.sin_addr.s_addr = inet_addr(pToIp);
	addrTo.sin_family = AF_INET;
	addrTo.sin_port = htons(toPort);

	if (INADDR_NONE == addrTo.sin_addr.s_addr)
	{
		return -1;
	}

	sendLen = 0;
	while (sendLen <= 0)
	{
		sendLen = SendTo(s, &pBuf[0], len, flags, (struct sockaddr*)&addrTo, sizeof(addrTo));
		if (sendLen <= 0)
		{
			if (ESOCKEINTR != sendLen)
			{
				return -1;
			}
		}
	}

	return sendLen;
}

int RecvUdp(SOCKET s, char* pBuf, unsigned int len, int flags, char *pFromIp, unsigned int fromIpLen, unsigned short* pFromPort)
{
	struct sockaddr_in addrFrom;
	unsigned int addrFromLen = 0;
	int recvLen = 0;
	char ipstr[16];
	int result = 0;

	if (0 == pBuf)
	{
		return -1;
	}

	memset(&addrFrom, 0, sizeof(addrFrom));
	addrFromLen = sizeof(addrFrom);

	while (recvLen <= 0)
	{		
		recvLen = RecvFrom(s, &pBuf[0], len, flags, (struct sockaddr*)&addrFrom, &addrFromLen);
		if (recvLen <= 0)
		{
			if ((ESOCKEINTR != recvLen) && (ESOCKEWOULDBLOCK != recvLen) && (ESOCKECONNRESET != recvLen))
			{
				return -1;
			}

			if ((ESOCKEWOULDBLOCK == recvLen) || (ESOCKECONNRESET == recvLen))
			{
				if (0 != pFromPort)
				{
					*pFromPort = 0;
				}

				if (0 != pFromIp)
				{
					*pFromIp = 0;
				}

				return 0;
			}
		}
	}

	if (0 != pFromPort)
	{
		*pFromPort = ntohs(addrFrom.sin_port);
	}

	if (0 != pFromIp)
	{
		result = InetNtoaR(addrFrom.sin_addr, &ipstr[0], sizeof(ipstr));
		if (0 != result)
		{
			return -1;
		}

		if (((strlen(ipstr) + 1) > fromIpLen))
		{
			return -1;
		}
	
		memcpy(pFromIp, &ipstr[0], (strlen(&ipstr[0]) + 1));
	}

	return recvLen;
}

int ValidDataConv(unsigned int dataSize, DATATYPE dataType)
{
	switch (dataType)
	{		
		case DT_1_BYTE:		break;	// char - 1 byte
		
		case DT_2_BYTE:		if ((dataSize % 2) != 0)
							{
								return -1;
							}
							break;	// short int - 2 byte

		case DT_4_BYTE:		if ((dataSize % 4) != 0)
							{
								return -1;
							}
							break;	// int, float - 4 byte

		case DT_8_BYTE:		if ((dataSize % 8) != 0)
							{
								return -1;
							}
							break;	// long long, double - 8 byte

		default:			return -1;
	}
	return 0;
}



int SendToNoInt(SOCKET s, const char* buf, unsigned int len, int flags, const struct sockaddr* to, unsigned int tolen)
{
	int result;

	do
	{
		result = SendTo(s, buf, len, flags, to, tolen);
	}
	while (ESOCKEINTR == result);

	return result;
}

int RecvFromNoInt(SOCKET s, char* buf, unsigned int len, int flags, struct sockaddr* from, unsigned int* fromlen)
{
	int result;
	
	do
	{
		result = RecvFrom(s, buf, len, flags, from, fromlen);
	}
	while (ESOCKEINTR == result);

	return result;
}

int InetNtoaR(struct in_addr in, char* pBuffer, unsigned int bufflen)
{
	unsigned char* p = 0;
#ifdef _WIN32
	int result;
#endif
	if ((0 == pBuffer) || (bufflen < 16))
	{
		return -1;
	}

	p = (unsigned char*)&in;

#ifdef _WIN32
	result = sprintf_s(pBuffer, bufflen, "%u.%u.%u.%u", (unsigned int)p[0], (unsigned int)p[1], (unsigned int)p[2], (unsigned int)p[3]);
	if (-1 == result)
	{
		return -1;
	}
#else
	sprintf(pBuffer, "%u.%u.%u.%u", (unsigned int)p[0], (unsigned int)p[1], (unsigned int)p[2], (unsigned int)p[3]);
#endif
	return 0;
}

// прием с таймаутом

// 0  - пакет принят
// -1 - критическая ошибка
// -2 - таймаут
// -3 - некритическая ошибка
int RecvFromTime(SOCKET s, char* pBuf, unsigned int* pInBufLen_outPacketLen, struct sockaddr_in* pAddrFrom, unsigned int timeMilSec)
{
	int result;
	fd_set rset;
	struct timeval selectTimeOut;
	int resSel = 0;
	unsigned int addrLen = 0;

	if ((0 == s) || (0 == pBuf) || (0 == pInBufLen_outPacketLen))
	{
		return -1;
	}

	if (0 == *pInBufLen_outPacketLen)
	{
		return -1;
	}

	FD_ZERO(&rset);

#ifdef _WIN32
#pragma warning(disable:4127)
#endif

	FD_SET(s, &rset);

#ifdef _WIN32
#pragma warning(default:4127)
#endif

	selectTimeOut.tv_sec = timeMilSec / 1000;
	selectTimeOut.tv_usec = (timeMilSec % 1000) * 1000;

	// сделать select кросс-платформенным
	resSel = Select((int)s + 1, &rset, 0, 0, &selectTimeOut);

	if (0 == resSel)
	{
		// время истекло!
		return -2;
	}

	if (resSel < 0)
	{
		// ошибка!
		switch(resSel)
		{
		case ESOCKUNKNOWN:
		case ESOCKNOTINITIALISED:
		case ESOCKEFAULT:
		case ESOCKEINVAL:
		case ESOCKENETDOWN:
		case ESOCKENOTSOCK:
		case ESOCKEBADF:
		case ESOCKENOMEM:
			return -1;

		case ESOCKEINTR:
		case ESOCKEINPROGRESS:
			return -3;			// некритичная ошибка!

		default:
			return -1;
		}
	}
		// (resSel > 0) - пакет пришел

	addrLen = sizeof(struct sockaddr_in);
	result = RecvFrom(s, pBuf, *pInBufLen_outPacketLen, 0, (struct sockaddr*)pAddrFrom, &addrLen);
																//	result > 0 -> result == числу принятых байт
	//	errors:													//	result == 0 - удаленный хост закрыл соединение (принято 0 байт)
																//	result < 0	- ошибка
	if (result >= 0)
	{
		// пришел какой-то пакет, возможно, даже нулевой!
		*pInBufLen_outPacketLen = result;
	}
	else
	{
		// произошла какая-то ошибка!
		switch(result)
		{
		case ESOCKUNKNOWN:
		case ESOCKNOTINITIALISED:
		case ESOCKENETDOWN:
		case ESOCKEFAULT:
		case ESOCKEINVAL:
		case ESOCKESHUTDOWN:
		case ESOCKEBADF:
		case ESOCKENOTSOCK:
			return -1;

		case ESOCKEHOSTDOWN:
		case ESOCKEINTR:
		case ESOCKENOMEM:
		case ESOCKENOBUFS:
		case ESOCKEINPROGRESS:
		case ESOCKEWOULDBLOCK:
		case ESOCKEMSGSIZE:
		case ESOCKETIMEDOUT:
		case ESOCKECONNRESET:
		case ESOCKECONNREFUSED:
		case ESOCKENETRESET:
		case ESOCKEOPNOTSUPP:
		case ESOCKEISCONN:
		case ESOCKENOTCONN:
			return -3;			// некритичная ошибка!

		default:
			return -1;
		}
	}

	return 0;
}

// return:	RECV_TCP_TIME_OK						- все данные приняты
//			RECV_TCP_TIME_CRITICAL_ERROR			- критическая ошибка, надо закрывать сокет, а может и завершать приложение
//			RECV_TCP_TIME_TIME_OUT					- тайм-аут, время истекло, но все данные не пришли, надо закрывать сокет, а может и закрывать приложение
//			RECV_TCP_TIME_SOCKET_GRACEFULLY_CLOSED	- сокет на удаленной стороне был успешно закрыт, данные приняты не все! надо закрывать сокет!
//			RECV_TCP_TIME_WRONG_INPUT_PARAMETERS	- неправильные входные параметры
int RecvTcpTime(SOCKET sock, char* pBuf, unsigned int len, int timeOutMs)		// timeOutMs == -1 - бесконечный тайм-аут
{
	int result = 0;
	int resSel = 0;
	unsigned int actRecvBytes = 0;
	struct timeval selectTime;
	struct timeval startTime;
	struct timeval curTime;
	struct timeval deltaTimeVal;
	long long deltaMs = 0;
	fd_set rdSet;
	fd_set edSet;

	if (0 == pBuf)
	{
		return RECV_TCP_TIME_WRONG_INPUT_PARAMETERS;
	}

	if ((timeOutMs < 0) && (-1 != timeOutMs))
	{
		return RECV_TCP_TIME_WRONG_INPUT_PARAMETERS;
	}

	if (0 == len)
	{
		return RECV_TCP_TIME_WRONG_INPUT_PARAMETERS;
	}


/////////////////////////////////	BEGINING OF WORK	/////////////////////////////////
	if (-1 == timeOutMs)
	{
//////////////////		FOR INFINITY TIMEOUT	////////////////
		actRecvBytes = 0;
		do
		{
			result = Recv(sock, &pBuf[actRecvBytes], len - actRecvBytes, 0);
			if (result > 0)
			{
				actRecvBytes += (unsigned int)result;
			}
			else
			{
				// errors processing:
				switch (result)
				{
				case 0:
					return RECV_TCP_TIME_SOCKET_GRACEFULLY_CLOSED;

				case ESOCKUNKNOWN:
				case ESOCKNOTINITIALISED:
				case ESOCKENETDOWN:
				case ESOCKEFAULT:
				case ESOCKEINVAL:
				case ESOCKENOTSOCK:
				case ESOCKEBADF:
				case ESOCKENOMEM:
				case ESOCKENOBUFS:
				case ESOCKECONNREFUSED:
				case ESOCKECONNRESET:
				case ESOCKECONNABORTED:
				case ESOCKETIMEDOUT:
				case ESOCKEMSGSIZE:
				case ESOCKESHUTDOWN:
				case ESOCKENETRESET:
				case ESOCKEHOSTDOWN:
				case ESOCKENOTCONN:
				case ESOCKEOPNOTSUPP:
					return RECV_TCP_TIME_CRITICAL_ERROR;

				case ESOCKEINTR:
				case ESOCKEWOULDBLOCK:
				case ESOCKEINPROGRESS:
					break;

				default:
					return RECV_TCP_TIME_CRITICAL_ERROR;
				}
			}
		}
		while (actRecvBytes != len);
	}
	else
	{
//////////////////		FOR NOT INFINITY TIMEOUT	////////////////
		
		result = GetRelativeTime(&startTime);
		if (0 != result)
		{
			return RECV_TCP_TIME_CRITICAL_ERROR;
		}
		curTime = startTime;

		do
		{
			// проверки, на случай перевода часов:
			if ((curTime.tv_sec < startTime.tv_sec) || \
				((curTime.tv_sec == startTime.tv_sec) && (curTime.tv_usec < startTime.tv_usec)))
			{
				return RECV_TCP_TIME_CRITICAL_ERROR;
			}

			// deltaTimeVal = curTime - startTime;
			if (curTime.tv_usec >= startTime.tv_usec)
			{
				deltaTimeVal.tv_usec = curTime.tv_usec - startTime.tv_usec;
				deltaTimeVal.tv_sec = curTime.tv_sec - startTime.tv_sec;
			}
			else
			{
				deltaTimeVal.tv_usec = curTime.tv_usec + 1000000 - startTime.tv_usec;
				deltaTimeVal.tv_sec = curTime.tv_sec - 1 - startTime.tv_sec;
			}

			deltaMs = ((long long)deltaTimeVal.tv_sec * (long long)1000) + ((long long)(deltaTimeVal.tv_usec / 1000));
			if (deltaMs <= (long long)timeOutMs)
			{
				FD_ZERO(&rdSet);
				FD_ZERO(&edSet);
#ifdef _WIN32
#pragma warning(disable:4127)
#endif
				FD_SET(sock, &rdSet);
				FD_SET(sock, &edSet);
#ifdef _WIN32
#pragma warning(default:4127)
#endif
				deltaMs = (long long)timeOutMs - deltaMs;
				selectTime.tv_sec = (long)(deltaMs / (long long)1000);
				selectTime.tv_usec = ((long)(deltaMs % (long long)1000)) * 1000;
				resSel = Select((int)sock + 1, &rdSet, 0, &edSet, &selectTime);
				if (resSel > 0)
				{
					// есть данные для приема или ошибка на сокете
					result = Recv(sock, &pBuf[actRecvBytes], len - actRecvBytes, 0);
					if (result > 0)
					{
						actRecvBytes += (unsigned int)result;
					}
					else
					{
						// errors processing:
						switch (result)
						{
						case 0:
							return RECV_TCP_TIME_SOCKET_GRACEFULLY_CLOSED;

						case ESOCKUNKNOWN:
						case ESOCKNOTINITIALISED:
						case ESOCKENETDOWN:
						case ESOCKEFAULT:
						case ESOCKEINVAL:
						case ESOCKENOTSOCK:
						case ESOCKEBADF:
						case ESOCKENOMEM:
						case ESOCKENOBUFS:
						case ESOCKECONNREFUSED:
						case ESOCKECONNRESET:
						case ESOCKECONNABORTED:
						case ESOCKETIMEDOUT:
						case ESOCKEMSGSIZE:
						case ESOCKESHUTDOWN:
						case ESOCKENETRESET:
						case ESOCKEHOSTDOWN:
						case ESOCKENOTCONN:
						case ESOCKEOPNOTSUPP:
							return RECV_TCP_TIME_CRITICAL_ERROR;

						case ESOCKEINTR:
						case ESOCKEWOULDBLOCK:
						case ESOCKEINPROGRESS:
							break;

						default:
							return RECV_TCP_TIME_CRITICAL_ERROR;
						}
					}
				}
				else
				{
					if (0 == resSel)
					{
						// произошел тайм-аут!
						return RECV_TCP_TIME_TIME_OUT;
					}
					else
					{
						// произошла ошибка в работе функции Select()
						switch(resSel)
						{
						case ESOCKUNKNOWN:
						case ESOCKNOTINITIALISED:
						case ESOCKEFAULT:
						case ESOCKENETDOWN:
						case ESOCKEINVAL:
						case ESOCKENOTSOCK:
						case ESOCKEBADF:
						case ESOCKENOMEM:
							return RECV_TCP_TIME_CRITICAL_ERROR;

						case ESOCKEINTR:
						case ESOCKEINPROGRESS:
							break;

						default:
							return RECV_TCP_TIME_CRITICAL_ERROR;
						}
					}
				}
			}
			else
			{
				// произошел тайм-аут!
				return RECV_TCP_TIME_TIME_OUT;
			}

			result = GetRelativeTime(&curTime);
			if (0 != result)
			{
				return RECV_TCP_TIME_CRITICAL_ERROR;
			}
		}
		while (actRecvBytes != len);
	}

	return 0;
}


// Возвращает через указатель относительное время в виде структуры timeval:
// - ворзрващаемое относительное время является строго неубывающим (монотонным), 
//     оно неподвержено скачкам назад и не зависит от перевода системных часов (для ос2000 монотонность не гарантируется);
// - время отсчитывается относительно некоторого события в прошлом;
// - стартовая точка считается произвольной, но неменяющейся в процессе работы;
// - стартовая точка является общей для всей системы: для всех процессов и потоков
int GetRelativeTime(struct timeval* pTime)
{
#if defined _WIN32
	{
		static LARGE_INTEGER  fr;
		LARGE_INTEGER cnt;
		static unsigned int flagFr = 0;
#if (!defined _WIN32_WINNT) || (_WIN32_WINNT < 0x0600) // (< Windows Vista)
		DWORD_PTR oldMask;
#endif

		if (0 == pTime)
		{
			assert(0);
			return -1;
		}

		/* частота постоянна на всё время работы системы (для всех ядер, процессоров и режимов энергосбережения),
		   поэтому определим её только один раз и запомним на будущее */
		if (0 == flagFr)
		{
			QueryPerformanceFrequency(&fr); // always succeed
			flagFr = 1;
		}

#if (!defined _WIN32_WINNT) || (_WIN32_WINNT < 0x0600) // (< Windows Vista)
		/* так как в Windows XP возможны разные значения счетчиков на разных ядрах,
		   то будем выполнять запрос счетчика только на 1-ом ядре.
		   Для этого временно привязываем текущий поток к первому ядру */
		oldMask = SetThreadAffinityMask(GetCurrentThread(), 1);
#endif

		QueryPerformanceCounter(&cnt); // always succeed

#if (!defined _WIN32_WINNT) || (_WIN32_WINNT < 0x0600) // (< Windows Vista)
		SetThreadAffinityMask(GetCurrentThread(), oldMask);
#endif

		pTime->tv_sec = (long)(cnt.QuadPart / fr.QuadPart);
		pTime->tv_usec = (long)(((cnt.QuadPart % fr.QuadPart) * 1000000) / fr.QuadPart);
		return 0;
	}
#else
	{
		int result;
		struct timespec tmspc;

		if (0 == pTime)
		{
			assert(0);
			return -1;
		}
#if defined __oc2000__
		result = clock_gettime(CLOCK_REALTIME, &tmspc);		// NOT MONOTONIC!
#else
		result = clock_gettime(CLOCK_MONOTONIC, &tmspc);
#endif
		if (0 != result)
		{
			assert(0);
			return -1;
		}

		pTime->tv_sec = tmspc.tv_sec;
		pTime->tv_usec = tmspc.tv_nsec / 1000;
		return 0;
	}
#endif	
}


// return:	 0 - OK
//			-1 - FATAL
//			-2 - keep alive enable, but set parameters are FAIL
// on windows tcp_keepcnt is ignored (default tcp_keepcnt =~ 11)
int SetKeepAlive(SOCKET sock, unsigned int fEnable, unsigned int tcp_keepidle_sec, unsigned int tcp_keepcnt, unsigned int tcp_keepintvl_sec)
{
	int res;

	fEnable = (fEnable == 0) ? 0 : 1;	// запишем именно 0 или 1 во флаг влкючения

	res = setsockopt(sock, SOL_SOCKET, SO_KEEPALIVE, (char*)&fEnable, sizeof(fEnable));
	if (0 != res)
	{
		fprintf(stderr, "setsockopt: SO_KEEPALIVE (fEnable = %u) - FAIL\n", fEnable);
		return -1;
	}

	if (fEnable)
	{
#ifdef _WIN32
		{
			struct tcp_keepalive tka;
			int ioctlRes;
			DWORD retBufSize;

			tcp_keepcnt = 1; // warning off
			tka.onoff = 1;
			tka.keepalivetime = tcp_keepidle_sec * 1000;		// указывается в миллисекундах
			tka.keepaliveinterval = tcp_keepintvl_sec * 1000;	// указывается в миллисекундах
			ioctlRes = WSAIoctl(sock, SIO_KEEPALIVE_VALS, &tka, sizeof(tka), 0, 0, &retBufSize, 0, 0);

			if (0 != ioctlRes)
			{
				return -2;
			}
		}

#elif __linux__

		res = setsockopt(sock, SOL_TCP, TCP_KEEPIDLE, (char*)&tcp_keepidle_sec, sizeof(tcp_keepidle_sec));
		if (0 != res)
		{
			fprintf(stderr, "setsockopt: TCP_KEEPIDLE (%u) - FAIL\n", tcp_keepidle_sec);
			return -2;
		}

		res = setsockopt(sock, SOL_TCP, TCP_KEEPCNT, (char*)&tcp_keepcnt, sizeof(tcp_keepcnt));
		if (0 != res)
		{
			fprintf(stderr, "setsockopt: TCP_KEEPCNT (%u) - FAIL\n", tcp_keepcnt);
			return -2;
		}

		res = setsockopt(sock, SOL_TCP, TCP_KEEPINTVL, (char*)&tcp_keepintvl_sec, sizeof(tcp_keepintvl_sec));
		if (0 != res)
		{
			fprintf(stderr, "setsockopt: TCP_KEEPINTVL (%u) - FAIL\n", tcp_keepintvl_sec);
			return -2;
		}
#else
		fprintf(stderr, "WARNING: setsockopt: keep alive parameters are ignored\n");
		return -2;
#endif
	}

	return 0;
}


// localPort == 0 -> any free port
// targetPort == 0 -> FATAL_ERROR
// return: 0 - OK, -1 - FATAL_ERROR, -2 -FAIL_ERROR, -3 - NOT_CONNECTED
int CreateTcpClientEx(SOCKET* pSock, const struct in_addr localIpAddr, unsigned short localPort, struct in_addr targetIpAddr, unsigned short targetPort, unsigned int fKeepAliveEnable)
{
	int result;
	unsigned int optval;
	struct sockaddr_in localAddr;
	struct sockaddr_in targetAddr;

	if ((0 == pSock) || (0 == targetPort))
	{
		fprintf(stderr, "ERROR: CreateTcpClientEx - FATAL: bad input parameters: pSock = 0x%p, targetPort = %u\n", pSock, (unsigned int)targetPort);
		assert(0);
		return -1;
	}

	memset(&localAddr, 0, sizeof(localAddr));
	memset(&targetAddr, 0, sizeof(targetAddr));

	result = SocketApiInit();
	if (0 != result)
	{
		fprintf(stderr, "ERROR: SocketApiInit - FAIL: result = %d\n", result);
		return -2;
	}

	result = Socket(pSock, PF_INET, SOCK_STREAM, 0);
	if (0 != result)
	{
		int locRes;
		locRes = SocketApiClose();
		if (0 != locRes)
		{
			fprintf(stderr, "ERROR: SocketApiClose - FATAL: result = %d\n", locRes);
			assert(0);
			return -1;
		}
		fprintf(stderr, "ERROR: Socket - FAIL: result = %d\n", result);
		return -2;
	}

	optval = TCP_SEND_BUF_SIZE;
	result = setsockopt(*pSock, SOL_SOCKET, SO_SNDBUF, (char*)&optval, sizeof(optval));
	if (0 != result)
	{
		int locRes;
		locRes = CloseSock(*pSock);
		if (0 != locRes)
		{
			fprintf(stderr, "ERROR: CloseSock - FATAL: result = %d\n", locRes);
			assert(0);
			return -1;
		}

		locRes = SocketApiClose();
		if (0 != locRes)
		{
			fprintf(stderr, "ERROR: SocketApiClose - FATAL: result = %d\n", locRes);
			assert(0);
			return -1;
		}

		fprintf(stderr, "ERROR: setsockopt - FAIL: SO_SNDBUF, optval = %u, result = %d\n)", optval, result);
		return -2;
	}

	optval = TCP_RECV_BUF_SIZE;
	result = setsockopt(*pSock, SOL_SOCKET, SO_RCVBUF, (char*)&optval, sizeof(optval));
	if (0 != result)
	{
		int locRes;
		locRes = CloseSock(*pSock);
		if (0 != locRes)
		{
			fprintf(stderr, "ERROR: CloseSock - FATAL: result = %d\n", locRes);
			assert(0);
			return -1;
		}

		locRes = SocketApiClose();
		if (0 != locRes)
		{
			fprintf(stderr, "ERROR: SocketApiClose - FATAL: result = %d\n", locRes);
			assert(0);
			return -1;
		}

		fprintf(stderr, "ERROR: setsockopt - FAIL: SO_RCVBUF, optval = %u, result = %d\n)", optval, result);
		return -2;
	}

	result = SetSockReuseAddr(*pSock, 1);
	if (0 != result)
	{
		int locRes;
		locRes = CloseSock(*pSock);
		if (0 != locRes)
		{
			fprintf(stderr, "ERROR: CloseSock - FATAL: result = %d\n", locRes);
			assert(0);
			return -1;
		}

		locRes = SocketApiClose();
		if (0 != locRes)
		{
			fprintf(stderr, "ERROR: SocketApiClose - FATAL: result = %d\n", locRes);
			assert(0);
			return -1;
		}

		fprintf(stderr, "ERROR: SetSockReuseAddr - FAIL: val = %u, result = %d\n)", (unsigned int)1, result);
		return -2;
	}

	result = SetKeepAlive(*pSock, fKeepAliveEnable, KEEP_ALIVE_DEFAULT_IDLE_SEC, KEEP_ALIVE_DEFAULT_CNT, KEEP_ALIVE_DEFAULT_INTVL_SEC);
	if (0 != result)
	{
		int locRes;
		locRes = CloseSock(*pSock);
		if (0 != locRes)
		{
			fprintf(stderr, "ERROR: CloseSock - FATAL: result = %d\n", locRes);
			assert(0);
			return -1;
		}

		locRes = SocketApiClose();
		if (0 != locRes)
		{
			fprintf(stderr, "ERROR: SocketApiClose - FATAL: result = %d\n", locRes);
			assert(0);
			return -1;
		}

		fprintf(stderr, "ERROR: EnableKeepAlive - FAIL: result = %d\n)", result);
		return -2;
	}

	localAddr.sin_family = AF_INET;
	localAddr.sin_port = htons(localPort);
	localAddr.sin_addr = localIpAddr;

	result = Bind(*pSock, (const struct sockaddr*)&localAddr, sizeof(localAddr));
	if (0 != result)
	{
		int locRes;
		locRes = CloseSock(*pSock);
		if (0 != locRes)
		{
			fprintf(stderr, "ERROR: CloseSock - FATAL: result = %d\n", locRes);
			assert(0);
			return -1;
		}

		locRes = SocketApiClose();
		if (0 != locRes)
		{
			fprintf(stderr, "ERROR: SocketApiClose - FATAL: result = %d\n", locRes);
			assert(0);
			return -1;
		}

		fprintf(stderr, "ERROR: Bind: result = %d (return -2)\n", result);
		return -2;
	}

	targetAddr.sin_family = AF_INET;
	targetAddr.sin_port = htons(targetPort);
	targetAddr.sin_addr = targetIpAddr;

	result = Connect(*pSock, (const struct sockaddr*)&targetAddr, sizeof(targetAddr));
	if (0 != result)
	{
		switch (result)
		{
		case ESOCKEINTR:
		case ESOCKECONNREFUSED:
		case ESOCKETIMEDOUT:
		case ESOCKEHOSTUNREACH:
		case ESOCKENETUNREACH:
		case ESOCKECONNABORTED:
		case ESOCKEHOSTDOWN:		/* QNX not documented feature */
		case ESOCKEADDRINUSE:		/* windows возвращает эту ошибку при быстром переподключении */
		case ESOCKEADDRNOTAVAIL:	/*   linux возвращает эту ошибку при быстром переподключении */
			/* Временные ошибки связанные с невозможностью подключиться к абоненту в текущий момент */
		{
			int locRes;
			locRes = CloseSock(*pSock);
			if (0 != locRes)
			{
				fprintf(stderr, "ERROR: CloseSock - FATAL: result = %d\n", locRes);
				assert(0);
				return -1;
			}

			locRes = SocketApiClose();
			if (0 != locRes)
			{
				fprintf(stderr, "ERROR: SocketApiClose - FATAL: result = %d\n", locRes);
				assert(0);
				return -1;
			}
			fprintf(stderr, "ERROR: Connect: result = %d (return -3)\n", result);
			return -3;
		}

		case ESOCKENOBUFS:			/* Если память закончилась, то стоит завершиться */
		case ESOCKENETDOWN:			/* Подсистема обмена операционной системы сломалась */
			/* Серьезные ошибки, дальше работать невозможно. Но причина ошибок может быть внешней. */
		{
			int locRes;
			locRes = CloseSock(*pSock);
			if (0 != locRes)
			{
				fprintf(stderr, "ERROR: CloseSock - FATAL: result = %d\n", locRes);
				assert(0);
				return -1;
			}

			locRes = SocketApiClose();
			if (0 != locRes)
			{
				fprintf(stderr, "ERROR: SocketApiClose - FATAL: result = %d\n", locRes);
				assert(0);
				return -1;
			}

			fprintf(stderr, "ERROR: Connect: result = %d (return -2)\n", result);
			return -2;
		}

		case ESOCKUNKNOWN:
		case ESOCKNOTINITIALISED:
		case ESOCKEFAULT:
		case ESOCKEAFNOSUPPORT:
		case ESOCKENOTSOCK:
		case ESOCKEBADF:
		case ESOCKEACCES:
		case ESOCKEISCONN:		/* Нарушение логики работы, сокет не может быть присоединен */
		case ESOCKEWOULDBLOCK:	/* Сокет с блокировкой не должен вызывать эту ошибку */
		case ESOCKEINVAL:
		case ESOCKEINPROGRESS:	/* Сокет блокирующий, поэтому этой ошибки быть не должно */
		case ESOCKEALREADY:		/* Сокет с блокировкой не должен вызывать эту ошибку */
		default:
			/* Критические ошибки, связанные с ошибкой алгоритма. Дальше работать не стоит! Освобождением ресурсов заниматься бессмысленно. */
			fprintf(stderr, "ERROR: Connect - FATAL: result = %d\n", result);
			assert(0);
			return -1;
		}
	}

	return 0;
}

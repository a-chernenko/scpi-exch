
#ifndef SOCKET_API_HIGH_H
#define SOCKET_API_HIGH_H

#include "socket_api_low.h"

#define LISTEN_QUEUE_LENGTH		25
#define SOCKET_COMP_NAME_LEN	30
#define MAX_UDP_SIZE			64500

#define MAX_TCP_PACKET_SIZE		30000

#define BAGET_ETH_CARD_NAME		"de0"
#define LINUX_ETH_CARD_NAME		"eth0"
#define QNX_ETH_CARD_NAME		"wm4"
#define WINDOWS_CARD_NAME		"any_card"


#if defined (__oc2000__)
#define ETH_CARD_NAME BAGET_ETH_CARD_NAME
#elif defined (__QNX__)
#define ETH_CARD_NAME QNX_ETH_CARD_NAME
#elif defined (_WIN32)
#define ETH_CARD_NAME WINDOWS_CARD_NAME
#else										// наверное, какой-то Linux
#define ETH_CARD_NAME LINUX_ETH_CARD_NAME
#endif

#ifdef _WIN32
#define UDP_SEND_BUF_SIZE		(40*MAX_UDP_SIZE)	// 2.580.000 байт
#define UDP_RECV_BUF_SIZE		(40*MAX_UDP_SIZE)	// 2.580.000 байт
#else
#define UDP_SEND_BUF_SIZE		(3*MAX_UDP_SIZE)	// 193.500 байт
#define UDP_RECV_BUF_SIZE		(3*MAX_UDP_SIZE)	// 193.500 байт
#endif

#define TCP_SEND_BUF_SIZE		(3*MAX_TCP_PACKET_SIZE)
#define TCP_RECV_BUF_SIZE		(3*MAX_TCP_PACKET_SIZE)

#define RECV_TCP_TIME_OK							(0)
#define RECV_TCP_TIME_CRITICAL_ERROR				(-1)
#define RECV_TCP_TIME_TIME_OUT						(-2)
#define RECV_TCP_TIME_SOCKET_GRACEFULLY_CLOSED		(-3)
#define RECV_TCP_TIME_WRONG_INPUT_PARAMETERS		(-4)

typedef enum
{
	DT_1_BYTE	=	0,		//	CHAR
	DT_2_BYTE	=	1,		//	SHORT
	DT_4_BYTE	=	2,		//	INT
	DT_8_BYTE	=	3		//	DOUBLE
} DATATYPE;

#ifdef __cplusplus
extern "C" {
#endif


////////////////////////		UDP		//////////////////////////
int CreateUdpSock(SOCKET* pSock, const char* pIpAddr, unsigned short myPort);	// если (0 == pIpAddr), то IP будет любой, если (0 == myPort), то порт будет назначен операционкой
int SendUdp(SOCKET s, const char* pBuf, unsigned int len, int flags, const char *pToIp, unsigned short toPort);
int RecvUdp(SOCKET s, char* pBuf, unsigned int len, int flags, char *pFromIp, unsigned int fromIpLen, unsigned short* pFromPort);		// if (fromIp == 0), то Ip не записывается; if (fromPort == 0), то Port не записывается;


////////////////////////		TCP		//////////////////////////
int CreateTcpClient(SOCKET* pSock, const char *serverIp, unsigned short localPort, unsigned short serverPort);	//	if (localPort == 0)	myPort = anyPort;
int CreateListenSock(SOCKET* pSock, unsigned short port, const char* pIp);
int WaitForClient(SOCKET lisSock, SOCKET* pConSock);
int SendTcp(SOCKET s, const char* pBuf, unsigned int len, int flags);
int RecvTcp(SOCKET s, char* pBuf, unsigned int len, int flags);


////////////////////////		COMMON		//////////////////////////
int DestroySock(SOCKET s);


////////////////////////		OTHER		//////////////////////////
int HostToNet(char* pData, unsigned int len, DATATYPE dataType);
int NetToHost(char* pData, unsigned int len, DATATYPE dataType);
int ValidDataConv(unsigned int dataSize, DATATYPE dataType);
int InetNtoaR(struct in_addr in, char* pBuffer, unsigned int bufflen);


int SendToNoInt(SOCKET s, const char* buf, unsigned int len, int flags, const struct sockaddr* to, unsigned int tolen);
int RecvFromNoInt(SOCKET s, char* buf, unsigned int len, int flags, struct sockaddr* from, unsigned int* fromlen);
int RecvFromTime(SOCKET s, char* pBuf, unsigned int* pInBufLen_outPacketLen, struct sockaddr_in* pAddrFrom, unsigned int timeMilSec);


// return:	0 - все данные отправлены
//			-1 - критическая ошибка, надо закрывать сокет, а может и завершать приложение
//			-2 - тайм-аут, время истекло, но не все данные отправлены, надо закрывать сокет, а может и закрывать приложение
//			-3 - сокет на удаленной стороне был успешно закрыт, данные отправлены не все! надо закрывать сокет!

// если len == 0, len > 0
// если timeOutMs == 0, timeOutMs > 0, timeOutMs == -1
// если сокет блокированный или нет!
//int SendTcpTime(SOCKET s, const unsigned char* pBuf, unsigned int len, int timeOutMs);


// return:	RECV_TCP_TIME_OK						- все данные приняты
//			RECV_TCP_TIME_CRITICAL_ERROR			- критическая ошибка, надо закрывать сокет, а может и завершать приложение
//			RECV_TCP_TIME_TIME_OUT					- тайм-аут, время истекло, но все данные не пришли, надо закрывать сокет, а может и закрывать приложение
//			RECV_TCP_TIME_SOCKET_GRACEFULLY_CLOSED	- сокет на удаленной стороне был успешно закрыт, данные приняты не все! надо закрывать сокет!
//			RECV_TCP_TIME_WRONG_INPUT_PARAMETERS	- неправильные входные параметры
int RecvTcpTime(SOCKET sock, char* pBuf, unsigned int len, int timeOutMs);		// timeOutMs == -1 - бесконечный тайм-аут


// возвращает через указатель относительное время (время, относительно определенного события в прошлом) в виде структуры timeval
int GetRelativeTime(struct timeval* pTime);


// Параметры работы механизма keep alive
#define KEEP_ALIVE_DEFAULT_IDLE_SEC		3
#define KEEP_ALIVE_DEFAULT_CNT			3
#define KEEP_ALIVE_DEFAULT_INTVL_SEC	1

// Функция для включения и выключения механизма keep_alive на сокете
// return:	0  - OK, -1 - FATAL, -2 - keep alive enable, but set parameters are FAIL
// on windows tcp_keepcnt is ignored (default tcp_keepcnt =~ 11)
int SetKeepAlive(SOCKET sock, unsigned int fEnable, unsigned int tcp_keepidle_sec, unsigned int tcp_keepcnt, unsigned int tcp_keepintvl_sec);


// localPort == 0 -> any free port
// targetPort == 0 -> FATAL_ERROR
// return: 0 - OK, -1 - FATAL_ERROR, -2 -FAIL_ERROR, -3 - NOT_CONNECTED
int CreateTcpClientEx(SOCKET* pSock, const struct in_addr localIpAddr, unsigned short localPort, struct in_addr targetIpAddr, unsigned short targetPort, unsigned int fKeepAliveEnable);


// перенести в socket_api_low.h->

int GetLocalIp(struct in_addr* pIp);

#ifndef _WIN32
int GetEthCardIp(struct in_addr* pIp, char* pEthName);
#endif

// <- перенести в socket_api_low.h

#ifdef __cplusplus
}
#endif

#endif

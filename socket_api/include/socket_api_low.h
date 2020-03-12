
#ifndef SOCKET_API_LOW_H
#define SOCKET_API_LOW_H


//=================//	INCLUDES	//================//

#ifdef _WIN32
	#include <winsock2.h>
#endif

#ifndef _WIN32
	#include <sys/types.h>
	#include <errno.h>
	#include <sys/socket.h>
	#include <netinet/in.h>
	#include <arpa/inet.h>
	#include <unistd.h>
	#include <string.h>
	#include <fcntl.h>
	#include <netdb.h>
#endif

#ifdef __oc2000__
	#include <sys/sockio.h>
	#include <net/if.h>
#endif

#ifdef __QNX__
	#include <sys/select.h>
#endif



//====================================================//




//=================//	ERRORS	//================//

#define SOCK_OK						(0)		// NO ERRORS

#define ESOCKUNKNOWN				(-1)	//	unknown error: default from case
#define ESOCKSYSNOTREADY			(-2)	//	WIN32: WSASYSNOTREADY		10091;	LINUX:
#define ESOCKVERNOTSUPPORTED		(-3)	//	WIN32: WSAVERNOTSUPPORTED	10092;	LINUX:
#define ESOCKEINPROGRESS			(-4)	//	WIN32: WSAEINPROGRESS		10036;	LINUX:
#define ESOCKEPROCLIM				(-5)	//	WIN32: WSAEPROCLIM			10067;	LINUX:
#define ESOCKEFAULT					(-6)	//	WIN32: WSAEFAULT			10014;	LINUX:	EFAULT
#define ESOCKNOTINITIALISED			(-7)	//	WIN32: WSANOTINITIALISED	10093;	LINUX:
#define ESOCKENETDOWN				(-8)	//	WIN32: WSAENETDOWN			10050;	LINUX:


#define ESOCKEACCES					(-9)	//	WIN32: WSAEACCES			10013;	LINUX:	EACCES
#define ESOCKEAFNOSUPPORT			(-10)	//	WIN32: WSAEAFNOSUPPORT		10047;	LINUX:	EAFNOSUPPORT
#define ESOCKEINVAL					(-11)	//	WIN32: WSAEINVAL			10022;	LINUX:	EINVAL
#define ESOCKEMFILE					(-12)	//	WIN32: WSAEMFILE			10024;	LINUX:	EMFILE
#define ESOCKENFILE					(-13)	//	WIN32:								LINUX:	ENFILE
#define ESOCKEPROTONOSUPPORT		(-14)	//	WIN32: WSAEPROTONOSUPPORT	10043;	LINUX:	EPROTONOSUPPORT
#define ESOCKENOBUFS				(-15)	//	WIN32: WSAENOBUFS			10055;	LINUX:	ENOBUFS
#define ESOCKENOMEM					(-16)	//	WIN32:								LINUX:	ENOMEM

#define ESOCKEPROTOTYPE				(-17)	//	WIN32: WSAEPROTOTYPE		10041;	LINUX:
#define ESOCKESOCKTNOSUPPORT		(-18)	//	WIN32: WSAESOCKTNOSUPPORT	10044;	LINUX:
#define ESOCKENOTSOCK				(-19)	//	WIN32: WSAENOTSOCK			10038;	LINUX:	ENOTSOCK
#define ESOCKEINTR					(-20)	//	WIN32: WSAEINTR				10004;	LINUX:	EINTR
#define ESOCKEWOULDBLOCK			(-21)	//	WIN32: WSAEWOULDBLOCK		10035;	LINUX:	EAGAIN
#define ESOCKEIO					(-22)	//	WIN32:								LINUX:	EIO
#define ESOCKEBADF					(-23)	//	WIN32:								LINUX:	EBADF
#define	ESOCKEADDRINUSE				(-24)	//	WIN32: WSAEADDRINUSE		10048;	LINUX:	EADDRINUSE

#define ESOCKEADDRNOTAVAIL			(-25)	//	WIN32: WSAEADDRNOTAVAIL		10049;	LINUX:	EADDRNOTAVAIL
#define ESOCKELOOP					(-26)	//	WIN32:								LINUX:	ELOOP
#define ESOCKENAMETOOLONG			(-27)	//	WIN32:								LINUX:	ENAMETOOLONG
#define ESOCKENOENT					(-28)	//	WIN32:								LINUX:	ENOENT
#define ESOCKENOTDIR				(-29)	//	WIN32:								LINUX:	ENOTDIR
#define ESOCKEROFS					(-30)	//	WIN32:								LINUX:	EROFS
#define ESOCKEOPNOTSUPP				(-31)	//	WIN32: WSAEOPNOTSUPP		10045;	LINUX:	EOPNOTSUPP
#define ESOCKEISCONN				(-32)	//	WIN32: WSAEISCONN			10056;	LINUX:	EISCONN

#define ESOCKECONNRESET				(-33)	//	WIN32: WSAECONNRESET		10054;	LINUX:
#define ESOCKEDESTADDRREQ			(-34)	//	WIN32: WSAEDESTADDRREQ		10039;	LINUX:	EDESTADDRREQ
#define ESOCKEPROTO					(-35)	//	WIN32:								LINUX:	EPROTO
#define ESOCKEPERM					(-36)	//	WIN32:								LINUX:	EPERM
#define ESOCKECONNABORTED			(-37)	//	WIN32: WSAECONNABORTED		10053;	LINXU:	ECONNABORTED
#define ESOCKEALREADY				(-38)	//	WIN32: WSAEALREADY			10037;	LINUX:
#define ESOCKECONNREFUSED			(-39)	//	WIN32: WSAECONNREFUSED		10061;	LINUX:	ECONNREFUSED
#define ESOCKENETUNREACH			(-40)	//	WIN32: WSAENETUNREACH		10051;	LINUX:	ENETUNREACH

#define ESOCKEHOSTUNREACH			(-41)	//	WIN32: WSAEHOSTUNREACH		10065;	LINUX:
#define ESOCKETIMEDOUT				(-42)	//	WIN32: WSAETIMEDOUT			10060;	LINUX:	ETIMEDOUT (багет)
#define ESOCKENOTCONN				(-43)	//	WIN32: WSAENOTCONN			10057;	LINUX:	ENOTCONN
#define ESOCKENETRESET				(-44)	//	WIN32: WSAENETRESET			10052;	LINUX:
#define ESOCKESHUTDOWN				(-45)	//	WIN32: WSAESHUTDOWN			10058;	LINUX:
#define ESOCKEMSGSIZE				(-46)	//	WIN32: WSAEMSGSIZE			10040;	LINUX:
#define ESOCKEPIPE					(-47)	//	WIN32:								LINUX:	EPIPE
#define ESOCKEDEADLK				(-48)	//	WIN32:								LINUX:	EDEADLK

#define ESOCKENOLCK					(-49)	//	WIN32:								LINUX:	ENOLCK
#define ESOCKEHOSTDOWN				(-50)	//	WIN32:								LINUX:	EHOSTDOWN
#define ESOCKSRCH					(-51)	//	WIN32:								QNX: ESRCH (Can't find the socket manager)
#define	ESOCKENOPROTOOPT			(-52)	//	WIN32: WSAENOPROTOOPT		10042;	LINUX:	ENOPROTOOPT
//============================================================================================================//










//=================//	MACRO	//====================//

#ifdef _WIN32

#endif

#ifndef _WIN32
	#define SOCKET int		//	или typedef
#endif


#ifdef __cplusplus
extern "C" {
#endif
//====================================================//


//=================//	PROTOTYPES	//================//

//===================================================

int SocketApiInit(void);	//	0 - GOOD
	//	errors:
		//	ESOCKUNKNOWN
		//	ESOCKSYSNOTREADY
		//	ESOCKVERNOTSUPPORTED
		//	ESOCKEINPROGRESS
		//	ESOCKEPROCLIM
		//	ESOCKEFAULT
//====================================================

int SocketApiClose(void);	//	0 - GOOD
	//	errors:
		//	ESOCKUNKNOWN
		//	ESOCKNOTINITIALISED
		//	ESOCKENETDOWN
		//	ESOCKEINPROGRESS
//====================================================

int Socket(SOCKET* pSock, int af, int type, int protocol);		//	0 - GOOD
	//	errors:
		//	ESOCKUNKNOWN
		//	ESOCKNOTINITIALISED
		//	ESOCKENETDOWN
		//	ESOCKEAFNOSUPPORT
		//	ESOCKEINPROGRESS
		//	ESOCKEMFILE
		//	ESOCKENOBUFS
		//	ESOCKEPROTONOSUPPORT
		//	ESOCKEPROTOTYPE
		//	ESOCKESOCKTNOSUPPORT
		//	ESOCKEACCES
		//	ESOCKEINVAL
		//	ESOCKENFILE
		//	ESOCKENOMEM
//===================================================

int CloseSock(SOCKET s);			//	0 - GOOD
	//	errors:
		//	ESOCKUNKNOWN
		//	ESOCKNOTINITIALISED
		//	ESOCKENETDOWN
		//	ESOCKENOTSOCK
		//	ESOCKEINPROGRESS
		//	ESOCKEINTR
		//	ESOCKEWOULDBLOCK
		//	ESOCKEIO
		//	ESOCKEBADF
//===================================================

int Bind(SOCKET sock, const struct sockaddr* pMyAddr, unsigned int addrLen);		//	0 - GOOD
	//	errors:
		//	ESOCKUNKNOWN
		//	ESOCKNOTINITIALISED
		//	ESOCKENETDOWN
		//	ESOCKEACCES
		//	ESOCKEINPROGRESS
		//	ESOCKENOBUFS
		//	ESOCKENOTSOCK
		//	ESOCKEADDRINUSE
		//	ESOCKEADDRNOTAVAIL
		//	ESOCKEINVAL
		//	ESOCKEFAULT
		//	ESOCKEBADF
		//	ESOCKELOOP
		//	ESOCKENAMETOOLONG
		//	ESOCKENOMEM
		//	ESOCKENOENT
		//	ESOCKENOTDIR
		//	ESOCKEROFS
		//	ESOCKEWOULDBLOCK
		//	ESOCKEAFNOSUPPORT
		//	ESOCKEOPNOTSUPP
//===================================================

int Listen(SOCKET sock, int backlog);			//	0 - GOOD
	//	errors:
		//	ESOCKUNKNOWN
		//	ESOCKNOTINITIALISED
		//	ESOCKENETDOWN
		//	ESOCKEADDRINUSE
		//	ESOCKEINPROGRESS
		//	ESOCKEINVAL
		//	ESOCKEISCONN
		//	ESOCKEMFILE
		//	ESOCKENOBUFS
		//	ESOCKENOTSOCK
		//	ESOCKEOPNOTSUPP
		//	ESOCKEBADF
		//	ESOCKEDESTADDRREQ
//====================================================//

int Accept(SOCKET* pConSock, SOCKET listSock, struct sockaddr* addr, unsigned int* pAddrLen);	//	0 - GOOD
	//	errors:
		//	ESOCKUNKNOWN
		//	ESOCKNOTINITIALISED
		//	ESOCKECONNRESET
		//	ESOCKEFAULT
		//	ESOCKEINTR
		//	ESOCKEINVAL
		//	ESOCKEINPROGRESS
		//	ESOCKEMFILE
		//	ESOCKENETDOWN
		//	ESOCKENOBUFS
		//	ESOCKENOTSOCK
		//	ESOCKEOPNOTSUPP
		//	ESOCKEWOULDBLOCK
		//	ESOCKEBADF
		//	ESOCKENOMEM
		//	ESOCKENFILE
		//	ESOCKEPROTO
		//	ESOCKEPERM
		//	ESOCKSRCH
//====================================================//

int Connect(SOCKET sock, const struct sockaddr* pServAddr, unsigned int addrLen);			//	0 - GOOD
	//	errors:
		//	ESOCKUNKNOWN
		//	ESOCKNOTINITIALISED
		//	ESOCKEINTR
		//	ESOCKEINPROGRESS
		//	ESOCKEFAULT
		//	ESOCKEINVAL
		//	ESOCKENOBUFS
		//	ESOCKENOTSOCK
		//	ESOCKEWOULDBLOCK
		//	ESOCKENETDOWN
		//	ESOCKEADDRINUSE
		//	ESOCKEADDRNOTAVAIL
		//	ESOCKEAFNOSUPPORT
		//	ESOCKEACCES
		//	ESOCKEISCONN
		//	ESOCKEALREADY
		//	ESOCKECONNREFUSED
		//	ESOCKENETUNREACH
		//	ESOCKEHOSTUNREACH
		//	ESOCKETIMEDOUT
		//	ESOCKEBADF
		//	ESOCKECONNABORTED
		//	ESOCKEHOSTDOWN		/* QNX not documented feature */
//====================================================//

int Recv(SOCKET s, char* buf, unsigned int len, int flags);		//	result > 0 -> result == числу принятых байт
	//	errors:													//	result == 0 - удаленный хост закрыл соединение (принято 0 байт)
																//	result < 0	- ошибка
		//	ESOCKUNKNOWN
		//	ESOCKNOTINITIALISED
		//	ESOCKENETDOWN
		//	ESOCKEFAULT
		//	ESOCKEINVAL
		//	ESOCKENOTSOCK
		//	ESOCKEINTR
		//	ESOCKEINPROGRESS
		//	ESOCKEWOULDBLOCK
		//	ESOCKETIMEDOUT
		//	ESOCKEOPNOTSUPP
		//	ESOCKECONNRESET
		//	ESOCKECONNABORTED
		//	ESOCKENOTCONN
		//	ESOCKENETRESET
		//	ESOCKESHUTDOWN
		//	ESOCKEMSGSIZE
		//	ESOCKEBADF
		//	ESOCKENOMEM
		//	ESOCKECONNREFUSED
		//	ESOCKEHOSTDOWN
		//	ESOCKENOBUFS
//====================================================//

int RecvFrom(SOCKET s, char* buf, unsigned int len, int flags, struct sockaddr* from, unsigned int* fromlen);
																//	result > 0 -> result == числу принятых байт
	//	errors:													//	result == 0 - удаленный хост закрыл соединение (принято 0 байт)
																//	result < 0	- ошибка
		//	ESOCKUNKNOWN
		//	ESOCKNOTINITIALISED
		//	ESOCKENETDOWN
		//	ESOCKEFAULT
		//	ESOCKEINTR
		//	ESOCKEINPROGRESS
		//	ESOCKEINVAL
		//	ESOCKENETRESET
		//	ESOCKENOTSOCK
		//	ESOCKEOPNOTSUPP
		//	ESOCKESHUTDOWN
		//	ESOCKEMSGSIZE
		//	ESOCKEWOULDBLOCK
		//	ESOCKETIMEDOUT
		//	ESOCKECONNRESET
		//	ESOCKEISCONN
		//	ESOCKEBADF
		//	ESOCKENOMEM
		//	ESOCKENOTCONN
		//	ESOCKECONNREFUSED
		//	ESOCKEHOSTDOWN
		//	ESOCKENOBUFS
//====================================================//

int Send(SOCKET s, const char* buf, unsigned int len, int flags);		//	result > 0 -> result == числу отправленных байт
	//	errors:															//	result == 0 - удаленный хост закрыл соединение (отправлено 0 байт)
																		//	result < 0	- ошибка
		//	ESOCKUNKNOWN
		//	ESOCKNOTINITIALISED
		//	ESOCKENETDOWN
		//	ESOCKEINTR
		//	ESOCKEINPROGRESS
		//	ESOCKECONNRESET
		//	ESOCKENETRESET
		//	ESOCKESHUTDOWN
		//	ESOCKECONNABORTED
		//	ESOCKEFAULT
		//	ESOCKEINVAL
		//	ESOCKENOTSOCK
		//	ESOCKENOTCONN
		//	ESOCKEWOULDBLOCK
		//	ESOCKETIMEDOUT
		//	ESOCKEMSGSIZE
		//	ESOCKEOPNOTSUPP
		//	ESOCKEACCES
		//	ESOCKENOBUFS
		//	ESOCKEHOSTUNREACH
		//	ESOCKEBADF
		//	ESOCKENOMEM
		//	ESOCKEDESTADDRREQ
		//	ESOCKENETUNREACH
		//	ESOCKEHOSTDOWN
		//	ESOCKEPIPE
//====================================================//

int SendTo(SOCKET s, const char* buf, unsigned int len, int flags, const struct sockaddr* to, unsigned int tolen);
																		//	result > 0 -> result == числу отправленных байт
	//	errors:															//	result == 0 - удаленный хост закрыл соединение (отправлено 0 байт)
																		//	result < 0	- ошибка
		//	ESOCKUNKNOWN
		//	ESOCKNOTINITIALISED
		//	ESOCKENETDOWN
		//	ESOCKEACCES
		//	ESOCKEINVAL
		//	ESOCKEINTR
		//	ESOCKEINPROGRESS
		//	ESOCKEFAULT
		//	ESOCKENETRESET
		//	ESOCKENOBUFS
		//	ESOCKENOTCONN
		//	ESOCKENOTSOCK
		//	ESOCKEOPNOTSUPP
		//	ESOCKESHUTDOWN
		//	ESOCKEWOULDBLOCK
		//	ESOCKEMSGSIZE
		//	ESOCKEHOSTUNREACH
		//	ESOCKECONNRESET
		//	ESOCKECONNABORTED
		//	ESOCKETIMEDOUT
		//	ESOCKEADDRNOTAVAIL		-	под win, если упал линк на сетевушке, тогда это некритическая ошибка; когда линк восстановится и, если IP адрес не изменится, то ошибка пропадет
		//	ESOCKEAFNOSUPPORT
		//	ESOCKEDESTADDRREQ
		//	ESOCKENETUNREACH
		//	ESOCKEBADF
		//	ESOCKEISCONN
		//	ESOCKENOMEM
		//	ESOCKEPIPE
		//	ESOCKECONNREFUSED
		//	ESOCKEHOSTDOWN
//====================================================//

int SetSockBlockMode(SOCKET s);
	//	errors:
		//	ESOCKUNKNOWN
		//	ESOCKNOTINITIALISED
		//	ESOCKENETDOWN
		//	ESOCKEINPROGRESS
		//	ESOCKENOTSOCK
		//	ESOCKEFAULT
		//	ESOCKEACCES
		//	ESOCKEWOULDBLOCK
		//	ESOCKEBADF
		//	ESOCKEINTR
		//	ESOCKEINVAL
		//	ESOCKEMFILE
		//	ESOCKEPERM
		//	ESOCKEDEADLK
		//	ESOCKENOLCK
//====================================================//

int SetSockUnblockMode(SOCKET s);
	//	errors:
		//	ESOCKUNKNOWN
		//	ESOCKNOTINITIALISED
		//	ESOCKENETDOWN
		//	ESOCKEINPROGRESS
		//	ESOCKENOTSOCK
		//	ESOCKEFAULT
		//	ESOCKEACCES
		//	ESOCKEWOULDBLOCK
		//	ESOCKEBADF
		//	ESOCKEINTR
		//	ESOCKEINVAL
		//	ESOCKEMFILE
		//	ESOCKEPERM
		//	ESOCKEDEADLK
		//	ESOCKENOLCK
//====================================================//

int Select(int nfds, fd_set* readfds, fd_set* writefds, fd_set* errorfds, struct timeval* timeout);
	//	errors:
		//	ESOCKUNKNOWN
		//	ESOCKNOTINITIALISED
		//	ESOCKEFAULT
		//	ESOCKENETDOWN
		//	ESOCKEINTR
		//	ESOCKEINVAL
		//	ESOCKEINPROGRESS
		//	ESOCKENOTSOCK
		//	ESOCKEBADF
		//	ESOCKENOMEM
//====================================================//

int SetSockReuseAddr(SOCKET s, int val);
	//	errors:
		//	ESOCKUNKNOWN
		//	ESOCKNOTINITIALISED
		//	ESOCKENETDOWN
		//	ESOCKEFAULT
		//	ESOCKEINPROGRESS
		//	ESOCKEINVAL
		//	ESOCKENETRESET
		//	ESOCKENOPROTOOPT
		//	ESOCKENOTCONN
		//	ESOCKENOTSOCK
		//	ESOCKEISCONN
		//	ESOCKEBADF
//====================================================//


int SocketPair(SOCKET sv[2], int type, int protocol);
#ifdef __cplusplus
}
#endif

#endif


#include <stdio.h>

#include "..//include//socket_api_low.h"

#ifdef _WIN32

//==========================================================================================//

//=======================//		SocketApiInit		//======================================//

int SocketApiInit(void)
{
	int result = 0;
	WORD wVersionRequested;
	WSADATA wsaData;

	wVersionRequested = MAKEWORD(2, 2);

	result = WSAStartup(wVersionRequested, &wsaData);
	if (0 != result)
	{
		switch(result)
		{
			case WSASYSNOTREADY:		return ESOCKSYSNOTREADY;
			case WSAVERNOTSUPPORTED:	return ESOCKVERNOTSUPPORTED;
			case WSAEINPROGRESS:		return ESOCKEINPROGRESS;
			case WSAEPROCLIM:			return ESOCKEPROCLIM;
			case WSAEFAULT:				return ESOCKEFAULT;

			default:					return ESOCKUNKNOWN;
		}
	}
	else
	{
		return 0;
	}
}
//==========================================================================================//

//=======================//		SocketApiClose		//======================================//

int SocketApiClose(void)
{
	int result = 0;
	int err = 0;

	result = WSACleanup();
	if (SOCKET_ERROR == result)
	{
		err = WSAGetLastError();

		switch(err)
		{
			case WSANOTINITIALISED:	return ESOCKNOTINITIALISED;
			case WSAENETDOWN:		return ESOCKENETDOWN;
			case WSAEINPROGRESS:	return ESOCKEINPROGRESS;

			default:				return ESOCKUNKNOWN;
		}
	}
	else
	{
		return 0;
	}
}
//==========================================================================================//

//============================//		Socket		//======================================//

int Socket(SOCKET* pSock, int af, int type, int protocol)
{
	int err_code = 0;
	if (0 == pSock)
	{
		return ESOCKEINVAL;
	}

	*pSock = socket(af, type, protocol);
	if (INVALID_SOCKET == *pSock)
	{
		err_code = WSAGetLastError();
		switch (err_code)
		{
			case WSANOTINITIALISED:		return ESOCKNOTINITIALISED;
			case WSAENETDOWN:			return ESOCKENETDOWN;
			case WSAEAFNOSUPPORT:		return ESOCKEAFNOSUPPORT;
			case WSAEINPROGRESS:		return ESOCKEINPROGRESS;
			case WSAEMFILE:				return ESOCKEMFILE;
			case WSAENOBUFS:			return ESOCKENOBUFS;
			case WSAEPROTONOSUPPORT:	return ESOCKEPROTONOSUPPORT;
			case WSAEPROTOTYPE:			return ESOCKEPROTOTYPE;
			case WSAESOCKTNOSUPPORT:	return ESOCKESOCKTNOSUPPORT;

			default:					return ESOCKUNKNOWN;
		}
	}
	else
	{
		return 0;
	}
}
//==========================================================================================//

//============================//	CloseSock		//======================================//

int CloseSock(SOCKET s)
{
	int err_code = 0;
	int result = 0;

	result = closesocket(s);
	if (SOCKET_ERROR == result)
	{
		err_code = WSAGetLastError();
		switch (err_code)
		{
			case WSANOTINITIALISED:		return ESOCKNOTINITIALISED;
			case WSAENETDOWN:			return ESOCKENETDOWN;
			case WSAENOTSOCK:			return ESOCKENOTSOCK;
			case WSAEINPROGRESS:		return ESOCKEINPROGRESS;
			case WSAEINTR:				return ESOCKEINTR;
			case WSAEWOULDBLOCK:		return ESOCKEWOULDBLOCK;

			default:					return ESOCKUNKNOWN;
		}
	}
	else
	{
		return 0;
	}
}
//==========================================================================================//

//============================//		Bind		//======================================//

int Bind(SOCKET sock, const struct sockaddr* pMyAddr, unsigned int addrLen)
{
	int err_code = 0;
	int result = 0;

	result = bind(sock, pMyAddr, (int)addrLen);
	if (SOCKET_ERROR == result)
	{
		err_code = WSAGetLastError();
		switch (err_code)
		{
			case WSANOTINITIALISED:		return ESOCKNOTINITIALISED;
			case WSAENETDOWN:			return ESOCKENETDOWN;
			case WSAEACCES:				return ESOCKEACCES;
			case WSAEINPROGRESS:		return ESOCKEINPROGRESS;
			case WSAENOBUFS:			return ESOCKENOBUFS;
			case WSAENOTSOCK:			return ESOCKENOTSOCK;
			case WSAEADDRINUSE:			return ESOCKEADDRINUSE;
			case WSAEADDRNOTAVAIL:		return ESOCKEADDRNOTAVAIL;
			case WSAEINVAL:				return ESOCKEINVAL;
			case WSAEFAULT:				return ESOCKEFAULT;

			default:					return ESOCKUNKNOWN;
		}
	}
	else
	{
		return 0;
	}
}
//==========================================================================================//

//============================//		Listen		//======================================//

int Listen(SOCKET sock, int backlog)
{
	int err_code = 0;
	int result = 0;

	result = listen(sock, backlog);
	if (SOCKET_ERROR == result)
	{
		err_code = WSAGetLastError();
		switch (err_code)
		{
			case WSANOTINITIALISED:		return ESOCKNOTINITIALISED;
			case WSAENETDOWN:			return ESOCKENETDOWN;
			case WSAEADDRINUSE:			return ESOCKEADDRINUSE;
			case WSAEINPROGRESS:		return ESOCKEINPROGRESS;
			case WSAEINVAL:				return ESOCKEINVAL;
			case WSAEISCONN:			return ESOCKEISCONN;
			case WSAEMFILE:				return ESOCKEMFILE;
			case WSAENOBUFS:			return ESOCKENOBUFS;
			case WSAENOTSOCK:			return ESOCKENOTSOCK;
			case WSAEOPNOTSUPP:			return ESOCKEOPNOTSUPP;

			default:					return ESOCKUNKNOWN;
		}
	}
	else
	{
		return 0;
	}
}
//==========================================================================================//

//============================//		Accept		//======================================//

int Accept(SOCKET* pConSock, SOCKET listSock, struct sockaddr* addr, unsigned int* pAddrLen)
{
	int err_code = 0;

	if (0 == pConSock)
	{
		return ESOCKEINVAL;
	}

	*pConSock = accept(listSock, addr, (int*)pAddrLen);
	if (INVALID_SOCKET == *pConSock)
	{
		err_code = WSAGetLastError();
		switch (err_code)
		{
			case WSANOTINITIALISED:		return ESOCKNOTINITIALISED;
			case WSAECONNRESET:			return ESOCKECONNRESET;
			case WSAEFAULT:				return ESOCKEFAULT;
			case WSAEINTR:				return ESOCKEINTR;
			case WSAEINVAL:				return ESOCKEINVAL;
			case WSAEINPROGRESS:		return ESOCKEINPROGRESS;
			case WSAEMFILE:				return ESOCKEMFILE;
			case WSAENETDOWN:			return ESOCKENETDOWN;
			case WSAENOBUFS:			return ESOCKENOBUFS;
			case WSAENOTSOCK:			return ESOCKENOTSOCK;
			case WSAEOPNOTSUPP:			return ESOCKEOPNOTSUPP;
			case WSAEWOULDBLOCK:		return ESOCKEWOULDBLOCK;

			default:
#ifdef _DEBUG
				printf("accept unknown error: %d\n", err_code);
#endif
				return ESOCKUNKNOWN;
		}
	}
	else
	{
		return 0;
	}
}
//==========================================================================================//

//============================//		Connect		//======================================//

int Connect(SOCKET sock, const struct sockaddr* pServAddr, unsigned int addrLen)
{
	int err_code = 0;
	int result = 0;

	result = connect(sock, pServAddr, (int)addrLen);
	if (SOCKET_ERROR == result)
	{
		err_code = WSAGetLastError();
		switch (err_code)
		{
			case WSANOTINITIALISED:		return ESOCKNOTINITIALISED;
			case WSAEINTR:				return ESOCKEINTR;
			case WSAEINPROGRESS:		return ESOCKEINPROGRESS;
			case WSAEFAULT:				return ESOCKEFAULT;
			case WSAEINVAL:				return ESOCKEINVAL;
			case WSAENOBUFS:			return ESOCKENOBUFS;
			case WSAENOTSOCK:			return ESOCKENOTSOCK;
			case WSAEWOULDBLOCK:		return ESOCKEWOULDBLOCK;
			case WSAENETDOWN:			return ESOCKENETDOWN;
			case WSAEADDRINUSE:			return ESOCKEADDRINUSE;
			case WSAEADDRNOTAVAIL:		return ESOCKEADDRNOTAVAIL;
			case WSAEAFNOSUPPORT:		return ESOCKEAFNOSUPPORT;
			case WSAEACCES:				return ESOCKEACCES;
			case WSAEISCONN:			return ESOCKEISCONN;
			case WSAEALREADY:			return ESOCKEALREADY;
			case WSAECONNREFUSED:		return ESOCKECONNREFUSED;
			case WSAENETUNREACH:		return ESOCKENETUNREACH;
			case WSAEHOSTUNREACH:		return ESOCKEHOSTUNREACH;
			case WSAETIMEDOUT:			return ESOCKETIMEDOUT;

			default:					return ESOCKUNKNOWN;
		}
	}
	else
	{
		return 0;
	}
}
//==========================================================================================//

//============================//		Recv		//======================================//

int Recv(SOCKET s, char* buf, unsigned int len, int flags)
{
	int err_code = 0;
	int result = 0;

	result = recv(s, buf, (int)len, flags);
	if (SOCKET_ERROR == result)
	{
		err_code = WSAGetLastError();
		switch (err_code)
		{
			case WSANOTINITIALISED:		return ESOCKNOTINITIALISED;
			case WSAENETDOWN:			return ESOCKENETDOWN;
			case WSAEFAULT:				return ESOCKEFAULT;
			case WSAEINVAL:				return ESOCKEINVAL;
			case WSAENOTSOCK:			return ESOCKENOTSOCK;
			case WSAEINTR:				return ESOCKEINTR;
			case WSAEINPROGRESS:		return ESOCKEINPROGRESS;
			case WSAEWOULDBLOCK:		return ESOCKEWOULDBLOCK;
			case WSAETIMEDOUT:			return ESOCKETIMEDOUT;
			case WSAEOPNOTSUPP:			return ESOCKEOPNOTSUPP;
			case WSAECONNRESET:			return ESOCKECONNRESET;
			case WSAECONNABORTED:		return ESOCKECONNABORTED;
			case WSAENOTCONN:			return ESOCKENOTCONN;
			case WSAENETRESET:			return ESOCKENETRESET;
			case WSAESHUTDOWN:			return ESOCKESHUTDOWN;
			case WSAENOBUFS:			return ESOCKENOBUFS;
			case WSAEMSGSIZE:			return ESOCKEMSGSIZE;

			default:					return ESOCKUNKNOWN;
		}
	}
	else
	{
		return result;
	}
}
//==========================================================================================//

//============================//	RecvFrom		//======================================//

int RecvFrom(SOCKET s, char* buf, unsigned int len, int flags, struct sockaddr* from, unsigned int* fromlen)
{
	int err_code = 0;
	int result = 0;

	result = recvfrom(s, buf, (int)len, flags, from, (int*) fromlen);
	if (SOCKET_ERROR == result)
	{
		err_code = WSAGetLastError();
		switch (err_code)
		{
			case WSANOTINITIALISED:		return ESOCKNOTINITIALISED;
			case WSAENETDOWN:			return ESOCKENETDOWN;
			case WSAEFAULT:				return ESOCKEFAULT;
			case WSAEINTR:				return ESOCKEINTR;
			case WSAEINPROGRESS:		return ESOCKEINPROGRESS;
			case WSAEINVAL:				return ESOCKEINVAL;
			case WSAENETRESET:			return ESOCKENETRESET;
			case WSAENOTSOCK:			return ESOCKENOTSOCK;
			case WSAEOPNOTSUPP:			return ESOCKEOPNOTSUPP;
			case WSAESHUTDOWN:			return ESOCKESHUTDOWN;
			case WSAEMSGSIZE:			return ESOCKEMSGSIZE;
			case WSAEWOULDBLOCK:		return ESOCKEWOULDBLOCK;
			case WSAETIMEDOUT:			return ESOCKETIMEDOUT;
			case WSAENOBUFS:			return ESOCKENOBUFS;
			case WSAECONNRESET:			return ESOCKECONNRESET;			// -33: свидетельствует о том, что в ответ на предыдущий send пришло icmp сообщение Port Unreachable
			case WSAEISCONN:			return ESOCKEISCONN;

			default:					return ESOCKUNKNOWN;
		}
	}
	else
	{
		return result;
	}
}
//==========================================================================================//

//============================//		Send		//======================================//

int Send(SOCKET s, const char* buf, unsigned int len, int flags)
{
	int err_code = 0;
	int result = 0;

	result = send(s, buf, (int)len, flags);
	if (SOCKET_ERROR == result)
	{
		err_code = WSAGetLastError();
		switch (err_code)
		{
			case WSANOTINITIALISED:		return ESOCKNOTINITIALISED;
			case WSAENETDOWN:			return ESOCKENETDOWN;
			case WSAEINTR:				return ESOCKEINTR;
			case WSAEINPROGRESS:		return ESOCKEINPROGRESS;
			case WSAECONNRESET:			return ESOCKECONNRESET;
			case WSAENETRESET:			return ESOCKENETRESET;
			case WSAESHUTDOWN:			return ESOCKESHUTDOWN;
			case WSAECONNABORTED:		return ESOCKECONNABORTED;
			case WSAEFAULT:				return ESOCKEFAULT;
			case WSAEINVAL:				return ESOCKEINVAL;
			case WSAENOTSOCK:			return ESOCKENOTSOCK;
			case WSAENOTCONN:			return ESOCKENOTCONN;
			case WSAEWOULDBLOCK:		return ESOCKEWOULDBLOCK;
			case WSAETIMEDOUT:			return ESOCKETIMEDOUT;
			case WSAEMSGSIZE:			return ESOCKEMSGSIZE;
			case WSAEOPNOTSUPP:			return ESOCKEOPNOTSUPP;
			case WSAEACCES:				return ESOCKEACCES;
			case WSAENOBUFS:			return ESOCKENOBUFS;
			case WSAEHOSTUNREACH:		return ESOCKEHOSTUNREACH;

			default:					return ESOCKUNKNOWN;
		}
	}
	else
	{
		return result;
	}
}
//==========================================================================================//

//============================//		SendTo		//======================================//

int SendTo(SOCKET s, const char* buf, unsigned int len, int flags, const struct sockaddr* to, unsigned int tolen)
{
	int err_code = 0;
	int result = 0;

	result = sendto(s, buf, (int)len, flags, to, (int)tolen);
	if (SOCKET_ERROR == result)
	{
		err_code = WSAGetLastError();
		switch (err_code)
		{
			case WSANOTINITIALISED:		return ESOCKNOTINITIALISED;
			case WSAENETDOWN:			return ESOCKENETDOWN;
			case WSAEACCES:				return ESOCKEACCES;
			case WSAEINVAL:				return ESOCKEINVAL;
			case WSAEINTR:				return ESOCKEINTR;
			case WSAEINPROGRESS:		return ESOCKEINPROGRESS;
			case WSAEFAULT:				return ESOCKEFAULT;
			case WSAENETRESET:			return ESOCKENETRESET;
			case WSAENOBUFS:			return ESOCKENOBUFS;
			case WSAENOTCONN:			return ESOCKENOTCONN;
			case WSAENOTSOCK:			return ESOCKENOTSOCK;
			case WSAEOPNOTSUPP:			return ESOCKEOPNOTSUPP;
			case WSAESHUTDOWN:			return ESOCKESHUTDOWN;
			case WSAEWOULDBLOCK:		return ESOCKEWOULDBLOCK;
			case WSAEMSGSIZE:			return ESOCKEMSGSIZE;
			case WSAEHOSTUNREACH:		return ESOCKEHOSTUNREACH;
			case WSAECONNRESET:			return ESOCKECONNRESET;
			case WSAECONNABORTED:		return ESOCKECONNABORTED;
			case WSAETIMEDOUT:			return ESOCKETIMEDOUT;
			case WSAEADDRNOTAVAIL:		return ESOCKEADDRNOTAVAIL;
			case WSAEAFNOSUPPORT:		return ESOCKEAFNOSUPPORT;
			case WSAEDESTADDRREQ:		return ESOCKEDESTADDRREQ;
			case WSAENETUNREACH:		return ESOCKENETUNREACH;

			default:					return ESOCKUNKNOWN;
		}
	}
	else
	{
		return result;
	}
}
//==========================================================================================//

//============================//	SetSockBlockMode	//==================================//

int SetSockBlockMode(SOCKET s)
{
	int err_code = 0;
	int result = 0;
	unsigned long block = 0;

	result = ioctlsocket(s, FIONBIO, &block);
	if (SOCKET_ERROR == result)
	{
		err_code = WSAGetLastError();
		switch (err_code)
		{
			case WSANOTINITIALISED:		return ESOCKNOTINITIALISED;
			case WSAENETDOWN:			return ESOCKENETDOWN;
			case WSAEINPROGRESS:		return ESOCKEINPROGRESS;
			case WSAENOTSOCK:			return ESOCKENOTSOCK;
			case WSAEFAULT:				return ESOCKEFAULT;

			default:					return ESOCKUNKNOWN;
		}
	}
	else
	{
		return 0;
	}
}
//==========================================================================================//

//============================//	SetSockUnblockMode	//==================================//

int SetSockUnblockMode(SOCKET s)
{
	int err_code = 0;
	int result = 0;
	unsigned long nonBlock = 1;

	result = ioctlsocket(s, FIONBIO, &nonBlock);
	if (SOCKET_ERROR == result)
	{
		err_code = WSAGetLastError();
		switch (err_code)
		{
			case WSANOTINITIALISED:		return ESOCKNOTINITIALISED;
			case WSAENETDOWN:			return ESOCKENETDOWN;
			case WSAEINPROGRESS:		return ESOCKEINPROGRESS;
			case WSAENOTSOCK:			return ESOCKENOTSOCK;
			case WSAEFAULT:				return ESOCKEFAULT;

			default:					return ESOCKUNKNOWN;
		}
	}
	else
	{
		return 0;
	}
}
//==========================================================================================//

//============================//		Select			//==================================//

int Select(int nfds, fd_set* readfds, fd_set* writefds, fd_set* errorfds, struct timeval* timeout)
{
	int err_code = 0;
	int result = 0;

	result = select(nfds, readfds, writefds, errorfds, ( struct timeval*)timeout);
	if (SOCKET_ERROR == result)
	{
		err_code = WSAGetLastError();
		switch (err_code)
		{
			case WSANOTINITIALISED:		return ESOCKNOTINITIALISED;
			case WSAEFAULT:				return ESOCKEFAULT;
			case WSAENETDOWN:			return ESOCKENETDOWN;
			case WSAEINVAL:				return ESOCKEINVAL;
			case WSAEINTR:				return ESOCKEINTR;
			case WSAEINPROGRESS:		return ESOCKEINPROGRESS;
			case WSAENOTSOCK:			return ESOCKENOTSOCK;

			default:					return ESOCKUNKNOWN;
		}
	}
	else
	{
		return result;
	}
}
//==========================================================================================//

//============================//	SetSockReuseAddr	//==================================//

int SetSockReuseAddr(SOCKET s, int val)
{
	int result;
	int err_code;
	int set_val;
	int len;

	set_val = (val == 0) ? 0 : 1;
	len = sizeof(set_val);
	result = setsockopt(s, SOL_SOCKET, SO_REUSEADDR, (char*)&set_val, len);
	if (SOCKET_ERROR == result)
	{
		err_code = WSAGetLastError();
		switch (err_code)
		{
			case WSANOTINITIALISED:		return ESOCKNOTINITIALISED;
			case WSAENETDOWN:			return ESOCKENETDOWN;
			case WSAEFAULT:				return ESOCKEFAULT;
			case WSAEINPROGRESS:		return ESOCKEINPROGRESS;
			case WSAEINVAL:				return ESOCKEINVAL;
			case WSAENETRESET:			return ESOCKENETRESET;
			case WSAENOPROTOOPT:		return ESOCKENOPROTOOPT;
			case WSAENOTCONN:			return ESOCKENOTCONN;
			case WSAENOTSOCK:			return ESOCKENOTSOCK;

			default:					return ESOCKUNKNOWN;
		}
	}
	else
	{
		return 0;
	}
}
//==========================================================================================//

#endif
#if defined(__oc2000__) || defined(_WIN32)
int SocketPair(SOCKET sv[2], int type, int protocol)
{
	SOCKET ls;
	int result;
	struct sockaddr_in myAddr;
	unsigned int len = sizeof(myAddr);
	if (0 == sv)
	{
		return ESOCKEINVAL;
	}
	result = Socket(&ls, AF_INET, type, protocol);
	if (result < 0)
		return result;
	result = Socket(&sv[0], AF_INET, type, protocol);
	if (result < 0)
	{
		CloseSock(ls);
		return result;
	}
	myAddr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
	myAddr.sin_family = AF_INET;
	myAddr.sin_port = 0;
	result = Bind(ls, (struct sockaddr *)&myAddr, sizeof(myAddr));
	if (result < 0)
	{
		CloseSock(ls);
		CloseSock(sv[0]);
		return result;
	}
	result = Bind(sv[0], (struct sockaddr *)&myAddr, sizeof(myAddr));
	if (result < 0)
	{
		CloseSock(ls);
		CloseSock(sv[0]);
		return result;
	}
	result = getsockname(ls, (struct sockaddr *)&myAddr, (int*)&len);
	if (result)
	{
		CloseSock(ls);
		CloseSock(sv[0]);
		return ESOCKUNKNOWN;
	}
	if (type != SOCK_DGRAM)
	{
		result = Listen(ls, 10);
		if (result < 0)
		{
			CloseSock(ls);
			CloseSock(sv[0]);
			return result;
		}
	}

	result = Connect(sv[0], (struct sockaddr *)&myAddr, len);
	if (result < 0)
	{
		CloseSock(ls);
		CloseSock(sv[0]);
		return result;
	}
	if (type != SOCK_DGRAM)
	{
		len = sizeof(myAddr);
		result = Accept(&sv[1], ls, (struct sockaddr *)&myAddr, &len);
		if (result < 0)
		{
			CloseSock(ls);
			CloseSock(sv[0]);
			return result;
		}
		CloseSock(ls);
	}
	else
	{
		len = sizeof(myAddr);
		sv[1] = ls;
		result = getsockname(sv[0], (struct sockaddr *)&myAddr, (int*)&len);
		if (result)
		{
			CloseSock(ls);
			CloseSock(sv[0]);
			return ESOCKUNKNOWN;
		}
		result = Connect(sv[1], (struct sockaddr *)&myAddr, len);
		if (result < 0)
		{
			CloseSock(ls);
			CloseSock(sv[0]);
			return result;
		}

	}
	return 0;
}
#endif



#ifndef _WIN32

//=======================//		SocketApiInit		//======================================//

int SocketApiInit(void)
{
	return 0;
}
//==========================================================================================//

//=======================//		SocketApiClose		//======================================//

int SocketApiClose(void)
{
	return 0;
}
//==========================================================================================//

//============================//		Socket		//======================================//

int Socket(SOCKET* pSock, int af, int type, int protocol)
{
	int err_code = 0;
	if (0 == pSock)
	{
		return ESOCKEINVAL;
	}

	*pSock = socket(af, type, protocol);
	if (-1 == *pSock)
	{
		err_code = errno;
		switch (err_code)
		{
			case EACCES:				return ESOCKEACCES;
			case EAFNOSUPPORT:			return ESOCKEAFNOSUPPORT;
			case EINVAL:				return ESOCKEINVAL;
			case EMFILE:				return ESOCKEMFILE;
			case ENFILE:				return ESOCKENFILE;
			case ENOBUFS:				return ESOCKENOBUFS;
			case ENOMEM:				return ESOCKENOMEM;
			case EPROTONOSUPPORT:		return ESOCKEPROTONOSUPPORT;
			case EPROTOTYPE:			return ESOCKEPROTOTYPE;

			default:					return ESOCKUNKNOWN;
		}
	}
	else
	{
		return 0;
	}
}
//==========================================================================================//

//============================//	CloseSocket		//======================================//

int CloseSock(SOCKET s)
{
	int err_code = 0;
	int result = 0;

	result = close(s);
	if (-1 == result)
	{
		err_code = errno;
		switch (err_code)
		{
			case EBADF:		return ESOCKEBADF;
			case EINTR:		return ESOCKEINTR;
			case EIO:		return ESOCKEIO;

			default:		return ESOCKUNKNOWN;
		}
	}
	else
	{
		return 0;
	}
}
//==========================================================================================//

//============================//		Bind		//======================================//

int Bind(SOCKET sock, const struct sockaddr* pMyAddr, unsigned int addrLen)
{
	int err_code = 0;
	int result = 0;

	result = bind(sock, pMyAddr, (socklen_t)addrLen);
	if (-1 == result)
	{
		err_code = errno;
		switch (err_code)
		{
			case EACCES:				return ESOCKEACCES;
			case ENOTSOCK:				return ESOCKENOTSOCK;
			case EADDRINUSE:			return ESOCKEADDRINUSE;
			case EADDRNOTAVAIL:			return ESOCKEADDRNOTAVAIL;
			case EINVAL:				return ESOCKEINVAL;
			case EFAULT:				return ESOCKEFAULT;
			case EBADF:					return ESOCKEBADF;
			case ELOOP:					return ESOCKELOOP;
			case ENAMETOOLONG:			return ESOCKENAMETOOLONG;
			case ENOMEM:				return ESOCKENOMEM;
			case ENOENT:				return ESOCKENOENT;
			case ENOTDIR:				return ESOCKENOTDIR;
			case EROFS:					return ESOCKEROFS;
			case ENOBUFS:				return ESOCKENOBUFS;
			case EAGAIN:				return ESOCKEWOULDBLOCK;
			case EAFNOSUPPORT:			return ESOCKEAFNOSUPPORT;
			case EOPNOTSUPP:			return ESOCKEOPNOTSUPP;

			default:					return ESOCKUNKNOWN;
		}
	}
	else
	{
		return 0;
	}
}
//==========================================================================================//

//============================//		Listen		//======================================//

int Listen(SOCKET sock, int backlog)
{
	int err_code = 0;
	int result = 0;

	result = listen(sock, backlog);
	if (-1 == result)
	{
		err_code = errno;
		switch (err_code)
		{
			case EADDRINUSE:			return ESOCKEADDRINUSE;
			case ENOTSOCK:				return ESOCKENOTSOCK;
			case EOPNOTSUPP:			return ESOCKEOPNOTSUPP;
			case EBADF:					return ESOCKEBADF;
			case EDESTADDRREQ:			return ESOCKEDESTADDRREQ;

			default:					return ESOCKUNKNOWN;
		}
	}
	else
	{
		return 0;
	}
}
//==========================================================================================//

//============================//		Accept		//======================================//

int Accept(SOCKET* pConSock, SOCKET listSock, struct sockaddr* addr, unsigned int* pAddrLen)
{
	int err_code = 0;

	if (0 == pConSock)
	{
		return ESOCKEINVAL;
	}

	*pConSock = accept(listSock, addr, (socklen_t*)pAddrLen);
	if (-1 == *pConSock)
	{
		err_code = errno;
		switch (err_code)
		{
			case EAGAIN:				return ESOCKEWOULDBLOCK;
			case EBADF:					return ESOCKEBADF;
			case EINVAL:				return ESOCKEINVAL;
			case ENOTSOCK:				return ESOCKENOTSOCK;
			case EOPNOTSUPP:			return ESOCKEOPNOTSUPP;
			case EFAULT:				return ESOCKEFAULT;
			case EMFILE:				return ESOCKEMFILE;
			case EINTR:					return ESOCKEINTR;
			case ENOMEM:				return ESOCKENOMEM;
			case ENFILE:				return ESOCKENFILE;
			case ENOBUFS:				return ESOCKENOBUFS;
			case EPROTO:				return ESOCKEPROTO;
			case EPERM:					return ESOCKEPERM;
			case ECONNABORTED:			return ESOCKECONNABORTED;
			case ESRCH:					return ESOCKSRCH;

			default:
#ifdef _DEBUG
				printf("accept unknown error: %d\n", err_code);
#endif
				return ESOCKUNKNOWN;
		}
	}
	else
	{
		return 0;
	}
}
//==========================================================================================//

//============================//		Connect		//======================================//

int Connect(SOCKET sock, const struct sockaddr* pServAddr, unsigned int addrLen)
{
	int err_code = 0;
	int result = 0;

	result = connect(sock, pServAddr, (socklen_t)addrLen);
	if (-1 == result)
	{
		err_code = errno;
		switch (err_code)
		{
			case EADDRINUSE:			return ESOCKEADDRINUSE;
			case EAFNOSUPPORT:			return ESOCKEAFNOSUPPORT;
			case EALREADY:				return ESOCKEALREADY;
			case EINTR:					return ESOCKEINTR;
			case ECONNREFUSED:			return ESOCKECONNREFUSED;
			case EINPROGRESS:			return ESOCKEINPROGRESS;
			case EISCONN:				return ESOCKEISCONN;
			case ENOTSOCK:				return ESOCKENOTSOCK;
			case ETIMEDOUT:				return ESOCKETIMEDOUT;
			case ENETUNREACH:			return ESOCKENETUNREACH;
			case EHOSTUNREACH:			return ESOCKEHOSTUNREACH;
			case EADDRNOTAVAIL:			return ESOCKEADDRNOTAVAIL;
			case EBADF:					return ESOCKEBADF;
			case EAGAIN:				return ESOCKEWOULDBLOCK;
			case EFAULT:				return ESOCKEFAULT;
			case EACCES:				return ESOCKEACCES;
			case EPERM:					return ESOCKEPERM;
			case ECONNABORTED:			return ESOCKECONNABORTED;
			case EHOSTDOWN:				return ESOCKEHOSTDOWN;		/* QNX not documented feature */

			default:
				perror("connect: unknown result");
				fprintf(stderr, "connect: unknown errno = %d\n", err_code);
				fflush(stderr);
				return ESOCKUNKNOWN;
		}
	}
	else
	{
		return 0;
	}
}
//==========================================================================================//

//============================//		Recv		//======================================//

int Recv(SOCKET s, char* buf, unsigned int len, int flags)
{
	int err_code = 0;
	int result = 0;

	result = recv(s, buf, (size_t)len, flags);
	if (-1 == result)
	{
		err_code = errno;
		switch (err_code)
		{
			case ENOTSOCK:				return ESOCKENOTSOCK;
			case ETIMEDOUT:				return ESOCKETIMEDOUT;
			case EINTR:					return ESOCKEINTR;
			case EINVAL:				return ESOCKEINVAL;
			case EOPNOTSUPP:			return ESOCKEOPNOTSUPP;
			case EAGAIN:				return ESOCKEWOULDBLOCK;
			case ECONNRESET:			return ESOCKECONNRESET;
			case ENOTCONN:				return ESOCKENOTCONN;
			case EFAULT:				return ESOCKEFAULT;
			case EBADF:					return ESOCKEBADF;
			case ENOMEM:				return ESOCKENOMEM;
			case ECONNREFUSED:			return ESOCKECONNREFUSED;
			case EHOSTDOWN:				return ESOCKEHOSTDOWN;

			default:
				perror("recv: unknown result");
				fprintf(stderr, "recv: unknown errno = %d\n", err_code);
				fflush(stderr);
				return ESOCKUNKNOWN;
		}
	}
	else
	{
		return result;
	}
}
//==========================================================================================//

//============================//	RecvFrom		//======================================//

int RecvFrom(SOCKET s, char* buf, unsigned int len, int flags, struct sockaddr* from, unsigned int* fromlen)
{
	int err_code = 0;
	int result = 0;

	result = recvfrom(s, buf, (size_t)len, flags, from, (socklen_t*) fromlen);
	if (-1 == result)
	{
		err_code = errno;
		switch (err_code)
		{
			case EAGAIN:				return ESOCKEWOULDBLOCK;
			case EBADF:					return ESOCKEBADF;
			case EFAULT:				return ESOCKEFAULT;
			case EINTR:					return ESOCKEINTR;
			case EINVAL:				return ESOCKEINVAL;
			case ENOTSOCK:				return ESOCKENOTSOCK;
			case ENOMEM:				return ESOCKENOMEM;
			case ETIMEDOUT:				return ESOCKETIMEDOUT;
			case EOPNOTSUPP:			return ESOCKEOPNOTSUPP;
			case ECONNRESET:			return ESOCKECONNRESET;
			case ENOTCONN:				return ESOCKENOTCONN;
			case ECONNREFUSED:			return ESOCKECONNREFUSED;

			case EHOSTDOWN:				return ESOCKEHOSTDOWN;

			default:					return ESOCKUNKNOWN;
		}
	}
	else
	{
		return result;
	}
}
//==========================================================================================//

//============================//		Send		//======================================//

int Send(SOCKET s, const char* buf, unsigned int len, int flags)
{
	int err_code = 0;
	int result = 0;

	result = send(s, buf, (size_t)len, flags);
	if (-1 == result)
	{
		err_code = errno;
		switch (err_code)
		{
			case ECONNRESET:			return ESOCKECONNRESET;
			case EFAULT:				return ESOCKEFAULT;
			case EINTR:					return ESOCKEINTR;
			case EINVAL:				return ESOCKEINVAL;
			case EMSGSIZE:				return ESOCKEMSGSIZE;
			case EACCES:				return ESOCKEACCES;
			case ENOTSOCK:				return ESOCKENOTSOCK;
			case ENOTCONN:				return ESOCKENOTCONN;
			case EOPNOTSUPP:			return ESOCKEOPNOTSUPP;
			case EAGAIN:				return ESOCKEWOULDBLOCK;
			case EBADF:					return ESOCKEBADF;
			case ENOMEM:				return ESOCKENOMEM;
			case EDESTADDRREQ:			return ESOCKEDESTADDRREQ;
			case ENETUNREACH:			return ESOCKENETUNREACH;
			case EPIPE:					return ESOCKEPIPE;
			case ENOBUFS:				return ESOCKENOBUFS;

			case EHOSTDOWN:				return ESOCKEHOSTDOWN;

			default:					return ESOCKUNKNOWN;
		}
	}
	else
	{
		return result;
	}
}
//==========================================================================================//

//============================//		SendTo		//======================================//

int SendTo(SOCKET s, const char* buf, unsigned int len, int flags, const struct sockaddr* to, unsigned int tolen)
{
	int err_code = 0;
	int result = 0;

	result = sendto(s, buf, (size_t)len, flags, to, (socklen_t)tolen);
	if (-1 == result)
	{
		err_code = errno;
		switch (err_code)
		{
			case EACCES:				return ESOCKEACCES;
			case EAGAIN:				return ESOCKEWOULDBLOCK;
			case EBADF:					return ESOCKEBADF;
			case ECONNRESET:			return ESOCKECONNRESET;
			case EDESTADDRREQ:			return ESOCKEDESTADDRREQ;
			case EFAULT:				return ESOCKEFAULT;
			case EINTR:					return ESOCKEINTR;
			case EINVAL:				return ESOCKEINVAL;
			case EISCONN:				return ESOCKEISCONN;
			case EMSGSIZE:				return ESOCKEMSGSIZE;
			case ENOBUFS:				return ESOCKENOBUFS;
			case ENOMEM:				return ESOCKENOMEM;
			case ENOTCONN:				return ESOCKENOTCONN;
			case ENOTSOCK:				return ESOCKENOTSOCK;
			case EOPNOTSUPP:			return ESOCKEOPNOTSUPP;
			case EPIPE:					return ESOCKEPIPE;
			case EHOSTUNREACH:			return ESOCKEHOSTUNREACH;
			case ECONNREFUSED:			return ESOCKECONNREFUSED;
			case EAFNOSUPPORT:			return ESOCKEAFNOSUPPORT;
			case EHOSTDOWN:				return ESOCKEHOSTDOWN;
			case ENETUNREACH:			return ESOCKENETUNREACH;

			default:					return ESOCKUNKNOWN;
		}
	}
	else
	{
		return result;
	}
}
//==========================================================================================//

//============================//	SetSockBlockMode	//==================================//

int SetSockBlockMode(SOCKET s)
{
	int result = 0;
	long arg = 0;
	int err_code = 0;

	arg = fcntl(s, F_GETFL, 0);
	arg = arg & ~O_NONBLOCK;

	result = fcntl(s, F_SETFL, arg);
	if (-1 == result)
	{
		err_code = errno;
		switch (err_code)
		{
			case EACCES:				return ESOCKEACCES;
			case EAGAIN:				return ESOCKEWOULDBLOCK;
			case EBADF:					return ESOCKEBADF;
			case EFAULT:				return ESOCKEFAULT;
			case EINTR:					return ESOCKEINTR;
			case EINVAL:				return ESOCKEINVAL;
			case EMFILE:				return ESOCKEMFILE;
			case EPERM:					return ESOCKEPERM;
			case EDEADLK:				return ESOCKEDEADLK;
			case ENOLCK:				return ESOCKENOLCK;

			default:					return ESOCKUNKNOWN;
		}
	}
	else
	{
		return 0;
	}
}
//==========================================================================================//

//============================//	SetSockUnblockMode	//==================================//

int SetSockUnblockMode(SOCKET s)
{
	int result = 0;
	long arg = 0;
	int err_code = 0;

	arg = fcntl(s, F_GETFL, 0);
	arg = arg | O_NONBLOCK;

	result = fcntl(s, F_SETFL, arg);
	if (-1 == result)
	{
		err_code = errno;
		switch (err_code)
		{
			case EACCES:				return ESOCKEACCES;
			case EAGAIN:				return ESOCKEWOULDBLOCK;
			case EBADF:					return ESOCKEBADF;
			case EFAULT:				return ESOCKEFAULT;
			case EINTR:					return ESOCKEINTR;
			case EINVAL:				return ESOCKEINVAL;
			case EMFILE:				return ESOCKEMFILE;
			case EPERM:					return ESOCKEPERM;
			case EDEADLK:				return ESOCKEDEADLK;
			case ENOLCK:				return ESOCKENOLCK;

			default:					return ESOCKUNKNOWN;
		}
	}
	else
	{
		return 0;
	}
}
//==========================================================================================//

//============================//		Select			//==================================//

int Select(int nfds, fd_set* readfds, fd_set* writefds, fd_set* errorfds, struct timeval* timeout)
{
	int err_code = 0;
	int result = 0;

	result = select(nfds, readfds, writefds, errorfds, timeout);
	if (-1 == result)
	{
		err_code = errno;
		switch (err_code)
		{
			case EBADF:					return ESOCKEBADF;
			case EINVAL:				return ESOCKEINVAL;
			case EINTR:					return ESOCKEINTR;
			case ENOMEM:				return ESOCKENOMEM;

			default:					return ESOCKUNKNOWN;
		}
	}
	else
	{
		return result;
	}
}
//==========================================================================================//

//============================//	SetSockReuseAddr	//==================================//

int SetSockReuseAddr(SOCKET s, int val)
{
	int result;
	int err_code;
	int set_val;
	int len;

	set_val = val == 0 ? 0 : 1;
	len = sizeof(set_val);
	result = setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &val, len);
	if (-1 == result)
	{
		err_code = errno;
		switch (err_code)
		{
			case EBADF:					return ESOCKEBADF;
			case ENOTSOCK:				return ESOCKENOTSOCK;
			case ENOPROTOOPT:			return ESOCKENOPROTOOPT;
			case EFAULT:				return ESOCKEFAULT;
			case EINVAL:				return ESOCKEINVAL;
			case EISCONN:				return ESOCKEISCONN;

			default:					return ESOCKUNKNOWN;
		}
	}
	else
	{
		return 0;
	}
}
//==========================================================================================//

#ifndef __oc2000__
int SocketPair(SOCKET sv[2], int type, int protocol)
{
	int err_code = 0;
	int ret;
	if (0 == sv)
	{
		return ESOCKEINVAL;
	}

	ret = socketpair(AF_UNIX, type, protocol, sv);
	if (-1 == ret)
	{
		err_code = errno;
		switch (err_code)
		{
			case EACCES:				return ESOCKEACCES;
			case EAFNOSUPPORT:			return ESOCKEAFNOSUPPORT;
			case EFAULT:				return ESOCKEFAULT;
			case EINVAL:				return ESOCKEINVAL;
			case EMFILE:				return ESOCKEMFILE;
			case ENFILE:				return ESOCKENFILE;
			case ENOBUFS:				return ESOCKENOBUFS;
			case ENOMEM:				return ESOCKENOMEM;
			case EPROTONOSUPPORT:		return ESOCKEPROTONOSUPPORT;
			case EPROTOTYPE:			return ESOCKEPROTOTYPE;

			default:					return ESOCKUNKNOWN;
		}
	}
	else
	{
		return 0;
	}
}
#endif
#endif

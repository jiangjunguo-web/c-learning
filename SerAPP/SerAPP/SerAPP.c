#include <stdio.h>
#include <Winsock2.h>

#pragma comment(lib, "ws2_32.lib")

int main() {
	WORD wVersionRequested=MAKEWORD(2,2);
	WSADATA result;
	int err = WSAStartup(wVersionRequested, &result);
	if (err != 0) {
		printf("启动失败\n");
		WSACleanup();
		return 404;
	}
	if (LOBYTE(result.wVersion) != 2 || HIBYTE(result.wVersion) != 2) {
		printf("版本号获取失败！\n");
		WSACleanup();
		return 404;
	}

	//生成套接字
	SOCKET ser_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (INVALID_SOCKET == ser_sock) {
		printf("生成socket失败！\n");
		WSACleanup();
		return 404;
	}

	//设备信息
	struct sockaddr_in ser_addr;
	memset(&ser_addr, 0, sizeof(ser_addr));
	ser_addr.sin_family = AF_INET;
	ser_addr.sin_addr.s_addr = inet_addr("192.168.1.104");
	ser_addr.sin_port = htons(10000);//端口转为大端字节序

	//绑定
	int back=bind(ser_sock,(SOCKADDR*) &ser_addr,sizeof(ser_addr));
	if (SOCKET_ERROR == back) {
		printf("绑定失败！\n");
		WSACleanup();
		return 404;
	}

	//监听
	int re = listen(ser_sock,10);
	if (SOCKET_ERROR == re) {
		printf("监听失败！\n");
		WSACleanup();
		return 404;
	}
	//接收
	printf("等待连接。。。。\n");
	SOCKET jie = accept(ser_sock, NULL,NULL);
	if (INVALID_SOCKET == jie) {
		printf("连接失败！\n");
		closesocket(ser_sock);
		WSACleanup();
		return 404;
	}
	printf("连接成功！\n");

	//通信
	char buff[1024];
	while(1) {
		int r = recv(jie, buff, 1023, NULL);
		if (r > 0) {
			buff[r] = 0;
			printf(">>>>%s\n",buff);
		}
	}

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Winsock2.h>

#include <string.h>

#pragma comment(lib, "ws2_32.lib")

int main() {

	WORD wVersionRequested = MAKEWORD(2, 2);
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
	SOCKET cli_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (INVALID_SOCKET == cli_sock) {
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


	//连接
	int co = connect(cli_sock, (SOCKADDR*)&ser_addr, sizeof(ser_addr));
	printf("正在建立连接。。。。。\n");
	if (SOCKET_ERROR == co) {
		printf("连接失败！\n");
		closesocket(cli_sock);
		WSACleanup();
		return 404;
	}
	printf("连接成功！\n");

	//通信
	char buff[1024];
	while (1)  {
		memset(buff, 0, 1024);
		printf("你要发送的内容：\n");
		scanf("%s", buff);
		send(cli_sock,buff,strlen(buff),NULL);
	}
	return 0;
}
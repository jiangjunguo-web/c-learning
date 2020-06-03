#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Winsock2.h>
#include <stdlib.h>
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
	ser_addr.sin_addr.s_addr = inet_addr("192.168.1.16");
	ser_addr.sin_port = htons(24);//端口转为大端字节序


	//连接
	int co = connect(cli_sock, (SOCKADDR*)&ser_addr, sizeof(ser_addr));
	int len = sizeof(ser_addr);
	printf("正在建立连接。。。。。\n");
	if (SOCKET_ERROR == co) {
		printf("连接失败！\n");
		closesocket(cli_sock);
		WSACleanup();
		return 404;
	}
	printf("连接成功！\n");

	FILE* fp = fopen("C:\\Users\\jiangjunguo\\Desktop\\text131.3ns.csv", "w");
	if (fp == NULL)
		printf("打开失败");
	
	//通信 
	char buff[1024];
	int count = 100;
	int r;
	int i;
	unsigned char  endnum;
	while (count-- > 0)  {
		memset(buff, 0, sizeof(buff));
		r = recv(cli_sock, buff, 64, 0);
		printf("%d\n", r);
		if (r > 0) {
			for (i = 2; i < 62; i += 4) {
				endnum = (unsigned char)buff[i];
				fprintf(fp, "%u\n", endnum);
			}
		}
	}
	printf("写入成功");
	fclose(fp);
	system("pause");
	return 0;
}



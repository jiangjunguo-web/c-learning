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
		printf("����ʧ��\n");
		WSACleanup();
		return 404;
	}
	if (LOBYTE(result.wVersion) != 2 || HIBYTE(result.wVersion) != 2) {
		printf("�汾�Ż�ȡʧ�ܣ�\n");
		WSACleanup();
		return 404;
	}

	//�����׽���
	SOCKET cli_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (INVALID_SOCKET == cli_sock) {
		printf("����socketʧ�ܣ�\n");
		WSACleanup();
		return 404;
	}


	//�豸��Ϣ
	struct sockaddr_in ser_addr;
	memset(&ser_addr, 0, sizeof(ser_addr));
	ser_addr.sin_family = AF_INET;
	ser_addr.sin_addr.s_addr = inet_addr("192.168.1.16");
	ser_addr.sin_port = htons(24);//�˿�תΪ����ֽ���


	//����
	int co = connect(cli_sock, (SOCKADDR*)&ser_addr, sizeof(ser_addr));
	int len = sizeof(ser_addr);
	printf("���ڽ������ӡ���������\n");
	if (SOCKET_ERROR == co) {
		printf("����ʧ�ܣ�\n");
		closesocket(cli_sock);
		WSACleanup();
		return 404;
	}
	printf("���ӳɹ���\n");

	FILE* fp = fopen("C:\\Users\\jiangjunguo\\Desktop\\text131.3ns.csv", "w");
	if (fp == NULL)
		printf("��ʧ��");
	
	//ͨ�� 
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
	printf("д��ɹ�");
	fclose(fp);
	system("pause");
	return 0;
}



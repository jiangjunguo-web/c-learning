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
	ser_addr.sin_addr.s_addr = inet_addr("192.168.1.104");
	ser_addr.sin_port = htons(10000);//�˿�תΪ����ֽ���


	//����
	int co = connect(cli_sock, (SOCKADDR*)&ser_addr, sizeof(ser_addr));
	printf("���ڽ������ӡ���������\n");
	if (SOCKET_ERROR == co) {
		printf("����ʧ�ܣ�\n");
		closesocket(cli_sock);
		WSACleanup();
		return 404;
	}
	printf("���ӳɹ���\n");

	//ͨ��
	char buff[1024];
	while (1)  {
		memset(buff, 0, 1024);
		printf("��Ҫ���͵����ݣ�\n");
		scanf("%s", buff);
		send(cli_sock,buff,strlen(buff),NULL);
	}
	return 0;
}
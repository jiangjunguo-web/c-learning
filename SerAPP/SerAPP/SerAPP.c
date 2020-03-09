#include <stdio.h>
#include <Winsock2.h>

#pragma comment(lib, "ws2_32.lib")

int main() {
	WORD wVersionRequested=MAKEWORD(2,2);
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
	SOCKET ser_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (INVALID_SOCKET == ser_sock) {
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

	//��
	int back=bind(ser_sock,(SOCKADDR*) &ser_addr,sizeof(ser_addr));
	if (SOCKET_ERROR == back) {
		printf("��ʧ�ܣ�\n");
		WSACleanup();
		return 404;
	}

	//����
	int re = listen(ser_sock,10);
	if (SOCKET_ERROR == re) {
		printf("����ʧ�ܣ�\n");
		WSACleanup();
		return 404;
	}
	//����
	printf("�ȴ����ӡ�������\n");
	SOCKET jie = accept(ser_sock, NULL,NULL);
	if (INVALID_SOCKET == jie) {
		printf("����ʧ�ܣ�\n");
		closesocket(ser_sock);
		WSACleanup();
		return 404;
	}
	printf("���ӳɹ���\n");

	//ͨ��
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
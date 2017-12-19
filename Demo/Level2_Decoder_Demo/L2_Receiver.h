/******************************************************************
@Դ��������: L2_Receiver.h
@�������Ȩ: �������ӹɷ����޹�˾ ��Ȩ����
@ϵͳ����: 
@ģ������: 
@����˵��: ����L2����
@����ĵ�: 
@����:     
@���: (��ѡ��)

@�޸ļ�¼
@�޸�����: 2013-02-25
@�޸���Ա: ��ģ��
@�޸�˵��: ����
@�汾��   1.0

*******************************************************************/

#ifndef _H_L2_RECEIVER_H_
#define _H_L2_RECEIVER_H_
#define BUFFER_SIZE 1024*512
#include <stdio.h>  
#include <iostream> 
#include <string>

#ifdef _WIN32
#include <WinSock2.h>  
#include <Windows.h>
#pragma comment(lib,"ws2_32.lib")
#else
#include <unistd.h>
#include <sys/types.h>
#include <string>
#include <stdlib.h>  
#include <errno.h>  
#include <string.h>  
#include <netdb.h>  
#include <sys/types.h>  
#include <netinet/in.h>  
#include <sys/socket.h>
#include <arpa/inet.h>
#endif

#include "Level2_Decoder_Demo.h"

class Level2_Decoder_Demo;
class L2_Receiver
{
public:
	L2_Receiver(Level2_Decoder_Demo *owner);
	
    ~L2_Receiver();
	int Start();
	int Connect(int port=0,char *ip="");

protected:
	int Init();

private:
	struct sockaddr_in sin;
	int inet_sock;

	int m_port;
	char *m_ip;
	Level2_Decoder_Demo *m_owner;
};

#endif

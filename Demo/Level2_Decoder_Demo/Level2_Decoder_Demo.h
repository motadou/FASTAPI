/******************************************************************
@Դ��������: Level2_Decoder_Demo.h
@�������Ȩ: �������ӹɷ����޹�˾ ��Ȩ����
@ϵͳ����: 
@ģ������: 
@����˵��: Level2���ݵ�ת��ʾ��
@����ĵ�: 
@����:     
@���: (��ѡ��)

@�޸ļ�¼
@�޸�����: 2013-02-25
@�޸���Ա: ��ģ��
@�޸�˵��: ����
@�汾��   1.0

*******************************************************************/
#ifndef _H_LEVEL2_DECODER_DEMO_H_
#define _H_LEVEL2_DECODER_DEMO_H_

#define  STEP_HEADER_FLAG                                  "8=STEP.1.0.0"
#define  STEP_HEADER_SIZE                                  12
#define  STEP_LEN_FLAG                                     "9="
#define  STEP_LEN_SIZE                                     2
#define  STEP_MSGSEQID_FLAG                                "10072="
#define  STEP_MSGSEQID_SIZE                                6
#define  STEP_TYPE_FLAG                                    "35="
#define  STEP_TYPE_SIZE                                    3
#define  STEP_SENDTIME_FLAG                                "52="
#define  STEP_SENDTIME_SIZE                                3
#define  STEP_SEQUENCE_FLAG                                "34="
#define  STEP_SEQUENCE_SIZE                                3
#define  FASTDATA_LEN_FLAG                                 "95="
#define  FASTDATA_LEN_SIZE                                 3
#define  FASTDATA_FLAG                                     "96="
#define  FASTDATA_SIZE                                     3
#define  FAST_TAIL_LENGTH                                  7

#define  MIN_STEP_LEN                                      30
#define  STEP_FIELD_DELIM                                  0x01

#include <iostream>
#include <fstream>
#include "L2_Receiver.h"
#include <vector>
#include <deque>
#include "Lock.h"
#include <Decoder_Factory.h>
#include <Basic_Types.h>
#include "DynBuffer.h"
#ifdef _WIN32 
#include <Windows.h>
typedef HANDLE L2_THREAD_HANDLE;
#else
#include <unistd.h> 
#include <pthread.h>
typedef     pthread_t L2_THREAD_HANDLE;
#endif

using namespace std;

class L2_Receiver;
class Level2_Decoder_Demo
{
public:
	struct L2_Data_Tag
	{
		char *buff;
		int lenth;
		~L2_Data_Tag()
		{
			if (buff)
			{
				delete[] buff;
			}
		}
	};
public:
	Level2_Decoder_Demo(FAST_TYPE ft,char * lpFile);
	
    ~Level2_Decoder_Demo();
	
    int Init();
	
    int ConnectServer(int port,char *ip);
	
    void Start();
	
    void Push(L2_Data_Tag &buff);
	
    L2_Data_Tag * Pop();
	
    int GetOneFastMessage (FastMsgInfo& refMsgInfo) ;

#ifdef _WIN32
	static DWORD WINAPI Deal(void* lpParamter);
#else
	static void*Deal(void* lpParamter);
#endif

	/***************************************************
	@�����Ϻ�level2   FAST����
	@
	****************************************************/
	void Deal_SH_Level2_Data(char *buff,int length);

	/***************************************************
	@�����Ϻ�level2  ����        (ʵ�֣�����DEMO)
	@��ʳɽ�
	****************************************************/
	void Deal_SH_NGTSTransaction(IFast_Record *Record);
	
    /***************************************************
	@�����Ϻ�level2  ����        (ʵ�֣�����DEMO)
	@�������
	****************************************************/
	void Deal_SH_NGTSMarketData(IFast_Record *Record);
	
    /***************************************************
	@�����Ϻ�level2  ����        (ʵ�֣�����DEMO)
	@ָ��������Ϣ
	****************************************************/
	void Deal_SH_NGTSIndex(IFast_Record *Record);

	/***************************************************
	@�����Ϻ�level2  ����        
	@�г��ſ���Ϣ
	****************************************************/
	void Deal_SH_NGTSMarketOverview(IFast_Record *Record);
	
    /***************************************************
	@�����Ϻ�level2  ����        
	@���⾺��
	****************************************************/
	void Deal_SH_NGTSVirtualAuctionPrice(IFast_Record *Record);

	/***************************************************
	@��������level2  FAST����       
	@
	****************************************************/
	void Deal_SZ_Level2_Data(char *buff,int length);

	/***************************************************
	@��������level2  ����       
	@FAST֤ȯ��Ϣ
	****************************************************/
	void Deal_SZ_StockInfo(IFast_Record *Record);
	/***************************************************
	@��������level2  ����       
	@FAST֤ȯ״̬
	****************************************************/
	void Deal_SZ_StockStatus(IFast_Record *Record);
	/***************************************************
	@��������level2  ����       
	@FAST����
	****************************************************/
	void Deal_SZ_Snapshot(IFast_Record *Record);

	/***************************************************
	@��������level2  ����       
	@FASTָ������
	****************************************************/
	void Deal_SZ_Index(IFast_Record *Record);
	/***************************************************
	@��������level2  ����       
	@FAST��Pί��
	****************************************************/
	void Deal_SZ_Order(IFast_Record *Record);
	/***************************************************
	@��������level2  ����       
	@ FAST��P�ɽ�
	****************************************************/
	void Deal_SZ_Trade(IFast_Record *Record);

protected:
    int GetFastMsgInfo (const char* lpData, int nLen, FastMsgInfo& refMsgInfo) ;
private:
	//std::deque<char *> m_L2Data;
	L2_Receiver *m_Recv;
	Lock *m_lock;
	L2_THREAD_HANDLE  hThread;

	FAST_TYPE m_ft;
	char *m_lpFile;
	
	DynBuffer         m_ReadBuff ;
	//����һ��������
	IFast_Decoder* m_Decoder;

};


#endif

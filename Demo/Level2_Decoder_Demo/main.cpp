#include <iostream>
#include <Basic_Types.h>
#include "Level2_Decoder_Demo.h"
using namespace std;

int main()
{
	//sh
	Level2_Decoder_Demo *l2_decoder_demo =new Level2_Decoder_Demo(emFAST_SHLEVEL2,"template.xml");
	//sz
	//Level2_Decoder_Demo *l2_decoder_demo =new Level2_Decoder_Demo(emFAST_SZLEVEL2,"fasttemplates_2.00.xml");

	if (l2_decoder_demo->Init() != 0)
	{
		printf("��ʼ��ʧ�ܣ�\n");
		system("pause");
		exit(1);
	}

	//sh
	if (l2_decoder_demo->ConnectServer(18555, "192.168.53.58")!=0)
	{
		printf("���ӷ�����ʧ�ܣ�\n");
		system("pause");
		exit(1);
	}

	//sz
	/*if(l2_decoder_demo->ConnectServer(18666,"192.168.53.58")!=0)
	{
		printf("���ӷ�����ʧ�ܣ�\n");
		system("pause");
		exit(1);
	}*/

	l2_decoder_demo->Start();

	system("pause");
	return 0;
}

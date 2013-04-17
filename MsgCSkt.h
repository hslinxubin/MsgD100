#pragma once
#include "MsgTypes.h";
#include "WinSock2.h"
class CMsgCSkt
{
public:
	CMsgCSkt(void);
	~CMsgCSkt(void);

public:
	//ƫ��λ��Ϊ0x10,������sockaddr������
	struct sockaddr *from;
	
	//ƫ��λ��0xA0,�������Ķ˿ں�
	int port;

	//ƫ��λ��Ϊ0x20, ��������������ʽ����
	char  * h_name;


	//ƫ�Ƶ�ַΪ0x1C4,��ȡ������sockaddr�������Ƿ�ɹ��ı��
	bool getfromaddrFlag;

	//0x1C8 ,��ʼ��ͨ�ž���Ƿ�ɹ�,0Ϊ�ɹ�
	int check;

	//ƫ��λ��0x1AC
	CMsgTypes * pCMsgTypes;

	//ƫ��λ��Ϊ0x1B4,
	int bLoadMsgTypesFlag;

	//ƫ��λ��Ϊ0x1BC,
	int unkown;

	//0x1E4,Select��,��ʼ�����ݽ��в������ٽ������
	CriticalSection pReadCriticalSection;

	//0x1CC,��Socket����д�������ٽ������
	CriticalSection pWriteCriticalSection;

	//ƫ��λ��0x22C,�����������socket
	socket *psocket;
	
	//0x230,����ȡ���ݵı��, ����һ�����г���ʱ,��ֵΪ0,Ҳ����Connect��,�������Ѿ��������ݵ��ͻ���
	// ��=0 �����ݱ��,��=1 дȡ���ݱ��
	int readWriteFlag;

	//0x234,�йط��ͻ������� ������
	bool mCount;

	//0x238,���ӷ����Ƿ�ɹ��ı��
	bool mConnect;

	//0x23C
	bool CMsgCSkt_AnalysisNodeFlag2;

	//0x240,��ʼ��Ϊ0x00
	bool unkownObj;

    //0x244,ͨ��Socket���͵�ԭʼ����,�ýṹΪ0x00Ϊ�ַ����ĳ���,0x04Ϊ�ַ����Ļ�����,0x8Ϊָ����һ�����ṹ��ָ��
	char * mOverload;


	//ƫ��λ��Ϊ0x258,�Ƿ�ӹ����ڴ��ж�ȡ����,��0Ϊ�ӹ����ڴ��ȡ����,0ΪSocketͨ�ŷ�ʽ
	bool mReadMapFile;


	//ƫ��λ��Ϊ0x264,ͬ�����,Ϊ0,����Զ�Socket���в���,Ϊ1������
	bool criticalFlag;

	//ƫ��λ��Ϊ0x268,����Ϊ1
	bool CMsgCSkt_AnalysisNodeFlag;

	//ƫ��λ��Ϊ0x270,����CProcessReadData �Ķ���
	CProcessReadData *pCProcessReadData;

	//ƫ��λ��Ϊ0x274,����CProcessReadData �Ķ���
	CProcessReadData *pCProcessReadData;

   //ƫ��λ��Ϊ0x278,����CProcessReadData2 �Ķ���
	CProcessReadData2 *pCProcessReadData2;

	 //ƫ��λ��Ϊ0x27C,����pReadPacket �Ķ���
	readPacket *pReadPacket;
};


//��Socket�л�ȡ�����ݰ�
struct readPacket
{
	//0x00
	char * buffer=null;

	//0x04,ָ��ڶ������ݰ����������ݵ�ַ
	char *LeaveBuffer=null;

	//0x08,�ڶ������ݰ��ĳ���
	int LeaveBufferLen=0x00;

	//0x0C header ���⸽�����ݰ��ڴ�ռ�ָ��,�ڴ�ռ��СΪheader.OptionalLen
	char * OptionalBuffer;

	//ƫ��0x10,headerͷ���⸽�����ݰ��ĳ���
	int OptionalLen = 0x00;

	//ƫ��0x14
	int Item6=0x00;

	// ƫ��0x18
	header *pHeader;
}
//���ݰ���ͷ
struct header
{
	//0x00,���ݰ��Ĵ�С,��ʼ������Ϊ0x1C
	int size = 0x1C;
	//0x04
	int Item2=0x00;
	//0x08
	int Item3;
	//0x0c
	int Item4=0x00;

	//0x10 headerͷ���⸽�����ݰ��ĳ���
	char *  OptionalLen ;


	//0x14
	int Item6=0x00;
	//0x18
	int Item7;
}


//0x1C ����readPacket�õ����м��,��һ��˫������ṹ
struct Node
{
	//0x00
	int item1=null;

	//0x04,ָ��header���ݵĻ�����
	char * pHeader = readPacket.pHeader;

	//0x08,header ��ǰHeader���⸽�������ݿռ��ַ
	char *  OptionalBuffer = readPacket.OptionalBuffer;

	//0x0C 
	char Item4=0x00;

	//ƫ��0x10
	int Item5 = header.Item3;

	//ƫ��0x14,ָ����һ��Node�����ָ��
	Node *pPreNode;

	// ƫ��0x18
	Node *pNextNode;
}



��һ�δ���socket�л�ȡ�������� ���ݳ���Ϊ0x72
00DFDD24  1C 00 00 00 00 00 00 00  DE 1C 6F 51 00 00 00 00
00DFDD34  00 00 00 00 04 00 00 00  00 00 00 00 1C 00 00 00
00DFDD44  00 00 00 00 DE 1C 6F 51  00 00 00 00 00 00 00 00
00DFDD54  10 00 00 00 00 00 00 00  1C 00 00 00 02 00 00 00
00DFDD64  1F 1D 6F 51 9C FF FF FF  1E 00 00 00 00 00 00 00
00DFDD74  00 00 00 04 1E 00 00 00  00 00 00 00 37 04 00 00
00DFDD84  54 00 00 00 D9 00 00 00  04 00 00 00 6C 6F 63 61
00DFDD94  6C 00 

          1C 00 00 00 00 00 00 00  DE 1C 6F 51 00 00 00 00
          00 00 00 00 04 00 00 00  00 00 00 00 

          1C 00 00 00 00 00 00 00  DE 1C 6F 51 00 00 00 00
		  00 00 00 00 10 00 00 00  00 00 00 00

		  1C 00 00 00 02 00 00 00  1F 1D 6F 51 9C FF FF FF
		  1E 00 00 00 00 00 00 00  00 00 00 04 
		  
		  1E 00 00 00 00 00 00 00  37 04 00 00 54 00 00 00 
		  D9 00 00 00 04 00 00 00  6C 6F 63 61 6C 00 




struct overload
{
	//0x00 ��������С
	int len = 0x00;
	//0x4 ������ָ��
	char * buf ;
	//0x08 ��һ��overload�ṹ��ָ��
	overload *pNext;

}

struct readFatherNode
{
	//0x00
	char * buffer=null;

	//0x04,ָ��ڶ������ݰ����������ݵ�ַ
	char *SencondBuffer=null;

	//0x08,�ڶ������ݰ��ĳ���
	int SencondLen=0x00;

	//0x0C ��ֵΪ0,���ݸ��ذ�,Ҳ����readNode��Я���Ķ��⸺�ذ�
	char * overload=0x00;

	//ƫ��0x10,��ʣ��Ҫ���Ƶ��ַ����ĳ���
	int LeaveLen = 0x00;

	//ƫ��0x14
	int Item6=0x00;

	// ƫ��0x18
	readNode *pReadNode;
} 

//0x1C��С
struct readNode
{
	//0x00,���ݰ��Ĵ�С,��ʼ������Ϊ0x1C
	int size = 0x1C;
	//0x04
	int Item2=0x00;
	//0x08
	int Item3;
	//0x0c
	int Item4=0x00;

	//0x10 ����,���⸽�������ݰ�
	int Len=0x00;

	//0x14
	int Item6=0x00;
	//0x18
	int Item7;
} 
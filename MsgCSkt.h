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
		
	//ƫ��λ��0xA4,���͸��������Ķ������ݰ�������
	char * OptionalBuffer;

	//ƫ��λ��0x1C0,�߳�ThreadId
	int   ThreadId;

	//ƫ��λ��Ϊ0x20, ��������������ʽ����
	char  * h_name;

	//ƫ��λ��Ϊ0x124, AppVersion �汾��
	char  * AppVersion;

	//ƫ�Ƶ�ַΪ0x1C4,��ȡ������sockaddr�������Ƿ�ɹ��ı��
	bool getfromaddrFlag;

	//0x1C8 ,�Ƿ��˳�ѭ�����,1Ϊ��������,0Ϊ�˳�
	int bExit;

	//ƫ��λ��0x1AC
	CMsgTypes * pCMsgTypes;

	//ƫ��λ��Ϊ0x1B4,
	int bLoadMsgTypesFlag;

	//ƫ��λ��Ϊ0x1BC,����Ҳ�������߳�
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

	//0x234,�ۼ���,����д�ط������Ĵ���,��CProcessReadData_MakeBuffer���������жϺ͵��� TopSendBuffer�ڵ����Ŀ
	int MsgiMaxWriteBack;

	//0x238,���ӷ����Ƿ�ɹ��ı��
	bool mConnect;

	//0x23C
	bool AnalysisNodeFlag2;

	//0x240,��ʼ��Ϊ0x00
	bool item240;

    //0x244,ͨ��Socket���͵�ԭʼ����,�ýṹΪ0x00Ϊ�ַ����ĳ���,0x04Ϊ�ַ����Ļ�����,0x8Ϊָ����һ�����ṹ��ָ�� ָ��SendBufferNode
	SendBufferNode * TopSendBuffer;

	 //0x248,ͨ��Socket���͵�ԭʼ����,�ýṹΪ0x00Ϊ�ַ����ĳ���,0x04Ϊ�ַ����Ļ�����,0x8Ϊָ����һ�����ṹ��ָ�� ָ��SendBufferNode
	//�����TopSendBuffer һ��
	SendBufferNode * CurSendBuffer;

	//ƫ��λ��Ϊ0x258,�Ƿ�ӹ����ڴ��ж�ȡ����,��0Ϊ�ӹ����ڴ��ȡ����,0ΪSocketͨ�ŷ�ʽ
	bool mReadMapFile;

	//0x25C Envent ָ��,����SendMessage ����,����SetEvent �����ź�
	Event SendMessageEvent

	//ƫ��λ��Ϊ0x264,ͬ�����,Ϊ0,����Զ�Socket���в���,Ϊ1������
	bool criticalFlag;

	//ƫ��λ��Ϊ0x268,����Ϊ1,������Ϣ���,���ڷ�����
	bool CMsgCSkt_AnalysisNodeFlag;


	//ƫ��λ��Ϊ0x270,����CProcessReadData �Ķ���
	CProcessReadData *pCProcessReadData;

	//ƫ��λ��Ϊ0x274,����CProcessReadData �Ķ���
	CProcessReadData *pCProcessReadData;

   //ƫ��λ��Ϊ0x278,����CProcessReadData2 �Ķ���
	CProcessReadData2 *pCProcessReadData2;

	 //ƫ��λ��Ϊ0x27C,����pReadPacket �Ķ���
	readPacket *pReadPacket;

	///0x280 ,��SendMessage,Ĭ��Ϊ0
	int item_280;

	//0x290,
	int item_290;
};


//��Socket�л�ȡ�����ݰ�
struct readPacket
{
	//0x00,��Socket���յ������Ƿ�����,���ᶪʧ,1Ϊ��ʧ,0Ϊ��������
	int Integrity = 0x;

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

	//0x08,ʱ���,�ѵ�ǰ���ַ�������ʱ���
	time TimeStamp;

	//0x0c
	int Item4=0x00;

	//0x10 headerͷ���⸽�����ݰ��ĳ���
	char *  OptionalLen ;


	//0x14 ��������
	int TypeMask=0x00;

	//0x18
	int Item7;
}


//0x1C ����readPacket�õ����м��,��һ��˫������ṹ
struct Node
{
	//0x00,��ʼ��Ϊ0x0
	int item1;

	//0x04,ָ��header���ݵĻ�����,����readPacket.pHeader������,��OptionalBuffer������
	char * pHeader = readPacket.pHeader;

	//0x08,header ��ǰHeader���⸽�������ݿռ��ַ,ֱ��ָ��readPacket.OptionalBuffer�ĵ�ַ,
	char *  OptionalBuffer = readPacket.OptionalBuffer;

	//0x0C 
	char Item4=0x00;

	//ƫ��0x10 ���ݰ�ԭʼ��ʱ���
	time TimeStamp = header.TimeStamp;

	//ƫ��0x14,ָ����һ��Node�����ָ��
	Node *pPreNode;

	// ƫ��0x18
	Node *pNextNode;
}


enum MessageType{
  TypeMask = 0x4  //�ӷ��������յ���Ϣ����,��ʾ��Ҫ�ͻ��˷��͵�¼��
}

struct MessageHeader
{
	//0x0 MessageHeader �Ĵ�С
	//��TypeMask = 0x4 ʱ,size = 0x1C
	int size ;

	//0x4
	//��TypeMask = 0x4 ʱ,item2 = 0x00
	int item2;

	//0x8,�洢 ����Time��ȡ��ǰ��ʱ��,�ͻ��˵�ʱ���   //time = 0x1C
	//��TypeMask = 0x4 ʱ,
	time TimeStamp ;

	//0xC
	//��TypeMask = 0x4 ʱ,item4 = 0x00
	int item4;
	
	//0x10
	//��TypeMask = 0x4 ʱ,item5 = 0x104,�����������ݰ��ĳ���
	int OptionalLen;

	//0x14,���������Ƿ�����������TypeMask ���� 
	//��TypeMask = 0x4 ʱ,TypeMask = 0x2
	int TypeMask;

	//0x18
	//��TypeMask = 0x4 ʱ,item7 = 0x00
	int item7;
}

struct SendBufferNode
{
	//0x00 ��������С
	int Size = 0x00;
	//0x4 ������ָ��,Bufָ��Ŀռ��ƫ�Ƶ�ַ0x8 Ϊ��ǰ��ʱ���
	char * Buffer ;
	//0x08 ��һ��SendBufferNode�ṹ��ָ��
	SendBufferNode *pNext;

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
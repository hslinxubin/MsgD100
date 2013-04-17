#pragma once
#include "MsgTypes.h";
#include "WinSock2.h"
class CMsgCSkt
{
public:
	CMsgCSkt(void);
	~CMsgCSkt(void);

public:
	//偏移位置为0x10,服务器sockaddr的内容
	struct sockaddr *from;
	
	//偏移位置0xA0,服务器的端口号
	int port;

	//偏移位置为0x20, 服务器主机的正式名称
	char  * h_name;


	//偏移地址为0x1C4,获取服务器sockaddr的内容是否成功的标记
	bool getfromaddrFlag;

	//0x1C8 ,初始化通信句柄是否成功,0为成功
	int check;

	//偏移位置0x1AC
	CMsgTypes * pCMsgTypes;

	//偏移位置为0x1B4,
	int bLoadMsgTypesFlag;

	//偏移位置为0x1BC,
	int unkown;

	//0x1E4,Select后,开始对数据进行操作的临界区句柄
	CriticalSection pReadCriticalSection;

	//0x1CC,对Socket进行写操作的临界区句柄
	CriticalSection pWriteCriticalSection;

	//偏移位置0x22C,与服务器连接socket
	socket *psocket;
	
	//0x230,检测读取数据的标记, 但第一次运行程序时,赋值为0,也就是Connect后,服务器已经发送数据到客户端
	// 当=0 读数据标记,当=1 写取数据标记
	int readWriteFlag;

	//0x234,有关发送缓存区的 计数器
	bool mCount;

	//0x238,连接服务是否成功的标记
	bool mConnect;

	//0x23C
	bool CMsgCSkt_AnalysisNodeFlag2;

	//0x240,初始化为0x00
	bool unkownObj;

    //0x244,通过Socket发送的原始数据,该结构为0x00为字符串的长度,0x04为字符串的缓存区,0x8为指向下一个本结构的指针
	char * mOverload;


	//偏移位置为0x258,是否从共享内存中读取数据,非0为从共享内存读取数据,0为Socket通信方式
	bool mReadMapFile;


	//偏移位置为0x264,同步标记,为0,则可以对Socket进行操作,为1则不允许
	bool criticalFlag;

	//偏移位置为0x268,设置为1
	bool CMsgCSkt_AnalysisNodeFlag;

	//偏移位置为0x270,保存CProcessReadData 的对象
	CProcessReadData *pCProcessReadData;

	//偏移位置为0x274,保存CProcessReadData 的对象
	CProcessReadData *pCProcessReadData;

   //偏移位置为0x278,保存CProcessReadData2 的对象
	CProcessReadData2 *pCProcessReadData2;

	 //偏移位置为0x27C,保存pReadPacket 的对象
	readPacket *pReadPacket;
};


//从Socket中获取的数据包
struct readPacket
{
	//0x00
	char * buffer=null;

	//0x04,指向第二个数据包缓存区内容地址
	char *LeaveBuffer=null;

	//0x08,第二个数据包的长度
	int LeaveBufferLen=0x00;

	//0x0C header 额外附带数据包内存空间指针,内存空间大小为header.OptionalLen
	char * OptionalBuffer;

	//偏移0x10,header头额外附带数据包的长度
	int OptionalLen = 0x00;

	//偏移0x14
	int Item6=0x00;

	// 偏移0x18
	header *pHeader;
}
//数据包的头
struct header
{
	//0x00,数据包的大小,初始化内容为0x1C
	int size = 0x1C;
	//0x04
	int Item2=0x00;
	//0x08
	int Item3;
	//0x0c
	int Item4=0x00;

	//0x10 header头额外附带数据包的长度
	char *  OptionalLen ;


	//0x14
	int Item6=0x00;
	//0x18
	int Item7;
}


//0x1C 分析readPacket得到的中间包,是一个双向链表结构
struct Node
{
	//0x00
	int item1=null;

	//0x04,指向header数据的缓存区
	char * pHeader = readPacket.pHeader;

	//0x08,header 当前Header额外附带的数据空间地址
	char *  OptionalBuffer = readPacket.OptionalBuffer;

	//0x0C 
	char Item4=0x00;

	//偏移0x10
	int Item5 = header.Item3;

	//偏移0x14,指向上一个Node对象的指针
	Node *pPreNode;

	// 偏移0x18
	Node *pNextNode;
}



第一次从是socket中获取到的数据 数据长度为0x72
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
	//0x00 缓存区大小
	int len = 0x00;
	//0x4 缓存区指针
	char * buf ;
	//0x08 下一个overload结构的指针
	overload *pNext;

}

struct readFatherNode
{
	//0x00
	char * buffer=null;

	//0x04,指向第二个数据包缓存区内容地址
	char *SencondBuffer=null;

	//0x08,第二个数据包的长度
	int SencondLen=0x00;

	//0x0C 赋值为0,内容负载包,也就是readNode所携带的额外负载包
	char * overload=0x00;

	//偏移0x10,还剩下要复制的字符串的长度
	int LeaveLen = 0x00;

	//偏移0x14
	int Item6=0x00;

	// 偏移0x18
	readNode *pReadNode;
} 

//0x1C大小
struct readNode
{
	//0x00,数据包的大小,初始化内容为0x1C
	int size = 0x1C;
	//0x04
	int Item2=0x00;
	//0x08
	int Item3;
	//0x0c
	int Item4=0x00;

	//0x10 长度,额外附带的数据包
	int Len=0x00;

	//0x14
	int Item6=0x00;
	//0x18
	int Item7;
} 
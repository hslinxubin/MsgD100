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
		
	//偏移位置0xA4,发送给服务器的额外数据包缓存区
	char * OptionalBuffer;

	//偏移位置0x1C0,线程ThreadId
	int   ThreadId;

	//偏移位置为0x20, 服务器主机的正式名称
	char  * h_name;

	//偏移位置为0x124, AppVersion 版本号
	char  * AppVersion;

	//偏移地址为0x1C4,获取服务器sockaddr的内容是否成功的标记
	bool getfromaddrFlag;

	//0x1C8 ,是否退出循环标记,1为继续继续,0为退出
	int bExit;

	//偏移位置0x1AC
	CMsgTypes * pCMsgTypes;

	//偏移位置为0x1B4,
	int bLoadMsgTypesFlag;

	//偏移位置为0x1BC,估计也是用于线程
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

	//0x234,累加器,可以写回服务器的次数,在CProcessReadData_MakeBuffer函数进行判断和叠加 TopSendBuffer节点的数目
	int MsgiMaxWriteBack;

	//0x238,连接服务是否成功的标记
	bool mConnect;

	//0x23C
	bool AnalysisNodeFlag2;

	//0x240,初始化为0x00
	bool item240;

    //0x244,通过Socket发送的原始数据,该结构为0x00为字符串的长度,0x04为字符串的缓存区,0x8为指向下一个本结构的指针 指向SendBufferNode
	SendBufferNode * TopSendBuffer;

	 //0x248,通过Socket发送的原始数据,该结构为0x00为字符串的长度,0x04为字符串的缓存区,0x8为指向下一个本结构的指针 指向SendBufferNode
	//保存和TopSendBuffer 一样
	SendBufferNode * CurSendBuffer;

	//偏移位置为0x258,是否从共享内存中读取数据,非0为从共享内存读取数据,0为Socket通信方式
	bool mReadMapFile;

	//0x25C Envent 指针,处理SendMessage 函数,调用SetEvent 发送信号
	Event SendMessageEvent

	//偏移位置为0x264,同步标记,为0,则可以对Socket进行操作,为1则不允许
	bool criticalFlag;

	//偏移位置为0x268,设置为1,发送消息标记,用于服务器
	bool CMsgCSkt_AnalysisNodeFlag;


	//偏移位置为0x270,保存CProcessReadData 的对象
	CProcessReadData *pCProcessReadData;

	//偏移位置为0x274,保存CProcessReadData 的对象
	CProcessReadData *pCProcessReadData;

   //偏移位置为0x278,保存CProcessReadData2 的对象
	CProcessReadData2 *pCProcessReadData2;

	 //偏移位置为0x27C,保存pReadPacket 的对象
	readPacket *pReadPacket;

	///0x280 ,在SendMessage,默认为0
	int item_280;

	//0x290,
	int item_290;
};


//从Socket中获取的数据包
struct readPacket
{
	//0x00,从Socket接收的数据是否完整,不会丢失,1为丢失,0为完整数据
	int Integrity = 0x;

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

	//0x08,时间戳,把当前的字符串加上时间戳
	time TimeStamp;

	//0x0c
	int Item4=0x00;

	//0x10 header头额外附带数据包的长度
	char *  OptionalLen ;


	//0x14 类型掩码
	int TypeMask=0x00;

	//0x18
	int Item7;
}


//0x1C 分析readPacket得到的中间包,是一个双向链表结构
struct Node
{
	//0x00,初始化为0x0
	int item1;

	//0x04,指向header数据的缓存区,复制readPacket.pHeader的内容,和OptionalBuffer有区别
	char * pHeader = readPacket.pHeader;

	//0x08,header 当前Header额外附带的数据空间地址,直接指向readPacket.OptionalBuffer的地址,
	char *  OptionalBuffer = readPacket.OptionalBuffer;

	//0x0C 
	char Item4=0x00;

	//偏移0x10 数据包原始的时间戳
	time TimeStamp = header.TimeStamp;

	//偏移0x14,指向上一个Node对象的指针
	Node *pPreNode;

	// 偏移0x18
	Node *pNextNode;
}


enum MessageType{
  TypeMask = 0x4  //从服务器接收的消息类型,表示需要客户端发送登录包
}

struct MessageHeader
{
	//0x0 MessageHeader 的大小
	//当TypeMask = 0x4 时,size = 0x1C
	int size ;

	//0x4
	//当TypeMask = 0x4 时,item2 = 0x00
	int item2;

	//0x8,存储 调用Time获取当前的时间,客户端的时间戳   //time = 0x1C
	//当TypeMask = 0x4 时,
	time TimeStamp ;

	//0xC
	//当TypeMask = 0x4 时,item4 = 0x00
	int item4;
	
	//0x10
	//当TypeMask = 0x4 时,item5 = 0x104,附带额外数据包的长度
	int OptionalLen;

	//0x14,初步怀疑是发给服务器的TypeMask 掩码 
	//当TypeMask = 0x4 时,TypeMask = 0x2
	int TypeMask;

	//0x18
	//当TypeMask = 0x4 时,item7 = 0x00
	int item7;
}

struct SendBufferNode
{
	//0x00 缓存区大小
	int Size = 0x00;
	//0x4 缓存区指针,Buf指向的空间的偏移地址0x8 为当前的时间戳
	char * Buffer ;
	//0x08 下一个SendBufferNode结构的指针
	SendBufferNode *pNext;

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
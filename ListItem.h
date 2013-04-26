#pragma once
class ListItem
{
public:
	ListItem(void);
	~ListItem(void);

public:
	//总大小为0x14

	//0x0
	char * title;

	//0x04 用来保存ReponseItem.Item2以后的内容
	CDARecord * pRecord;

	//0x08,客户端的时间戳
	Time TimeStamp;

	//0x0C
	ListItem * pPre;

	//0x10
	ListItem * pNext;
	
};

class CDARecordList
{
public:
	//0x00
	ListItem * pTopListItem;

	//0x04
	ListItem * pNextListItem;

}

//
class ReponseItem
{
public :
	//0x0,长度 item2以后的缓存区的大小
	int Len;
	//0x4
	short item2;

	//0x6,两个字节,CID列的内容
	char[2] CID;

	//0x08
	int item3;

	//0x0C
	char[] Title;

	//未知,其它的内容
	char[] other;
}


//
class CDARecord
{
public :
	//0x0,长度 为 ContextItem 不包含Served字段的长度,也就是 Len = ContextItem -0xCC
	int Len;
	//0x4
	int item2;
	
	//0x6,两个字节,CID列的内容
	char[2] CID;

	//0x08
	int item3;

	//0xB
	byte item3_1;


	//0x0C
	char[] Title;

	//0x未知
	char[] NONE;

	//0x未知
	char[] Item4;

	//四个字节 上一次修改的时间
	Time LastChanged

	char[] Value;

	



	char[] Context;

	//保留的字符串 0xCC
	char[]  served;
}


public class CMainDialog
{
public:
	///简易列表名称
	/// 0x98
	List<String> MnemonicsList;

	//0x80,记录集合列表 
	CDARecordList *RecordList;

	//0x24C,显示数据的表格控件
	GridView Control_Grid;
}


//CID 列 类型
//ZO 为时间
//ID 为字符串


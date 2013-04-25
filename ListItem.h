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
	ContextItem * pContextItem;

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
	int item2;

	//0x08
	int item3;

	//0x0C
	char[] Title;

	//未知,其它的内容
	char[] other;
}


//
class ContextItem
{
public :
	//0x0,长度 为 ContextItem 不包含Served字段的长度,也就是 Len = ContextItem -0xCC
	int Len;
	//0x4
	int item2;

	//0x08
	int item3;

	//0x0C
	char[] Title;

	//保留的字符串 0xCC
	char[]  served;
}

#pragma once
class ListItem
{
public:
	ListItem(void);
	~ListItem(void);

public:
	//�ܴ�СΪ0x14

	//0x0
	char * title;

	//0x04 ��������ReponseItem.Item2�Ժ������
	ContextItem * pContextItem;

	//0x08,�ͻ��˵�ʱ���
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
	//0x0,���� item2�Ժ�Ļ������Ĵ�С
	int Len;
	//0x4
	int item2;

	//0x08
	int item3;

	//0x0C
	char[] Title;

	//δ֪,����������
	char[] other;
}


//
class ContextItem
{
public :
	//0x0,���� Ϊ ContextItem ������Served�ֶεĳ���,Ҳ���� Len = ContextItem -0xCC
	int Len;
	//0x4
	int item2;

	//0x08
	int item3;

	//0x0C
	char[] Title;

	//�������ַ��� 0xCC
	char[]  served;
}

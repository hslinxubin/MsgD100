#pragma once
class Event
{
public:
	Event(void);
	~Event(void);
	
public:
	//0x00,����CreateEventA �����������¼����
	HANDLE hEvent;

	//0x04,��ǰ��ʱ��� 
	Time TimeStamp;

	//0x08,��ʼ��Ϊ0x00
	int Item3 = 0x00;

	//0x0C,
	int item4;
};


public class ManagerEvent
{
public:
	int ClientCheckCode;

	int item2;

	Event hEvent;
}



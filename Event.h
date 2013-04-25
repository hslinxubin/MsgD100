#pragma once
class Event
{
public:
	Event(void);
	~Event(void);
	
public:
	//0x00,保存CreateEventA 方法创建的事件句柄
	HANDLE hEvent;

	//0x04,当前的时间戳 
	Time TimeStamp;

	//0x08,初始化为0x00
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



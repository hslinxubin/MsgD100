#pragma once

class ManagerEvent
{
public:
	UnObject(void);
	~UnObject(void);
public:
	//0x00,Event对象
	Event *pEvent;

	//0x4
	int Item2;

	//0x8,Time 时间戳
	Time TimeStamp ;

};


#pragma once

class ManagerEvent
{
public:
	UnObject(void);
	~UnObject(void);
public:
	//0x00,Event����
	Event *pEvent;

	//0x4
	int Item2;

	//0x8,Time ʱ���
	Time TimeStamp ;

};


#pragma once
class RequestResponse
{
public:
	RequestResponse(void);
	~RequestResponse(void);
public:
	//这个结构为0x14 大小

	//0x00,跟CMsgCSkt.ClientCheckCode 有关系
	int ClientCheckCode;

	//0x4
	int item2 = 0x00;

	//0x08 指向Evnet对象
	Event *pEvent;

	//0x0C
	int item4 = 0x0;

	//0x10
	int item5 = 0x00;


};


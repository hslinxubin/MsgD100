#pragma once
class RequestResponse
{
public:
	RequestResponse(void);
	~RequestResponse(void);
public:
	//����ṹΪ0x14 ��С

	//0x00,��CMsgCSkt.ClientCheckCode �й�ϵ
	int ClientCheckCode;

	//0x4
	int item2 = 0x00;

	//0x08 ָ��Evnet����
	Event *pEvent;

	//0x0C
	int item4 = 0x0;

	//0x10
	int item5 = 0x00;


};


#include "StdAfx.h"
#include "MsgTypes.h"
#include "CConfigFile.h"

/*
** 1.ʵ����CConfigFile����
*/
CMsgTypes::CMsgTypes(void)
{
	item1 = 200;
	item2 = item1 +2;
	CConfigFile *pCConfigFile = new  CConfigFile();

}

CMsgTypes::CMsgTypes(int i){
 
	item1 = i;
	item2 = item1 +2;
	CConfigFile *pCConfigFile = new  CConfigFile();
	
}
CMsgTypes::~CMsgTypes(void)
{
}

#include "User.h"
#include<iostream>
using namespace std;

User::~User()
{
    //dtor
}

User::User(){type=0;}//构造函数
User::User(int id, int isWait,int arriveTime,int serveTime,char *type)
	{
		this->id=id;
		this->isWait=isWait;
		this->arriveTime=arriveTime;
		this->serveTime=serveTime;
		this->type=type;
	}
void User::getServed()//服务完毕
	{
		cout<<this->type<<this->id<<"已经被服务完毕，离开银行。"<<endl;
	}

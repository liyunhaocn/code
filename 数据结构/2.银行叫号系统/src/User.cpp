#include "User.h"
#include<iostream>
using namespace std;

User::~User()
{
    //dtor
}

User::User(){type=0;}//���캯��
User::User(int id, int isWait,int arriveTime,int serveTime,char *type)
	{
		this->id=id;
		this->isWait=isWait;
		this->arriveTime=arriveTime;
		this->serveTime=serveTime;
		this->type=type;
	}
void User::getServed()//�������
	{
		cout<<this->type<<this->id<<"�Ѿ���������ϣ��뿪���С�"<<endl;
	}

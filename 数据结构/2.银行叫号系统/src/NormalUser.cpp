#include "NormalUser.h"
#include<iostream>
using namespace std;


NormalUser::~NormalUser()
{
    //dtor
}
NormalUser::NormalUser(){}
NormalUser::NormalUser(int id, int isWait,int arriveTime,int serveTime):User(id,isWait,arriveTime,serveTime,"��ͨ�û�")
	{}
void NormalUser:: getServed()
{
	cout<<this->type<<this->id<<"�Ѿ���������ϣ��뿪���С�"<<endl;
}

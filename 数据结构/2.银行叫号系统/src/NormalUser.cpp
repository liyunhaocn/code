#include "NormalUser.h"
#include<iostream>
using namespace std;


NormalUser::~NormalUser()
{
    //dtor
}
NormalUser::NormalUser(){}
NormalUser::NormalUser(int id, int isWait,int arriveTime,int serveTime):User(id,isWait,arriveTime,serveTime,"普通用户")
	{}
void NormalUser:: getServed()
{
	cout<<this->type<<this->id<<"已经被服务完毕，离开银行。"<<endl;
}

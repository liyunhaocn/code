#include "VIPUser.h"
#include<iostream>
using namespace std;
VIPUser::~VIPUser()
{
    //dtor
}


VIPUser::VIPUser():User(){}
VIPUser::VIPUser(int id, int isWait,int arriveTime,int serveTime):User(id,isWait,arriveTime,serveTime,"VIP用户"){}
void VIPUser:: getServed()
{
  cout<<this->type<<this->id<<"已经被服务完毕，离开银行。"<<endl;
}

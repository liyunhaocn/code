#include "OfficialUser.h"
#include<iostream>
using namespace std;
OfficialUser::OfficialUser():User(){}
OfficialUser::OfficialUser(int id, int isWait,int arriveTime,int serveTime):User(id,isWait,arriveTime,serveTime,"公用用户"){}
void OfficialUser::getServed()
{
	cout<<this->type<<this->id<<"已经被服务完毕，离开银行。"<<endl;
}
OfficialUser::~OfficialUser()
{
    //dtor
}

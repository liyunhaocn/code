#include "VIPUser.h"
#include<iostream>
using namespace std;
VIPUser::~VIPUser()
{
    //dtor
}


VIPUser::VIPUser():User(){}
VIPUser::VIPUser(int id, int isWait,int arriveTime,int serveTime):User(id,isWait,arriveTime,serveTime,"VIP�û�"){}
void VIPUser:: getServed()
{
  cout<<this->type<<this->id<<"�Ѿ���������ϣ��뿪���С�"<<endl;
}

#include "OfficialUser.h"
#include<iostream>
using namespace std;
OfficialUser::OfficialUser():User(){}
OfficialUser::OfficialUser(int id, int isWait,int arriveTime,int serveTime):User(id,isWait,arriveTime,serveTime,"�����û�"){}
void OfficialUser::getServed()
{
	cout<<this->type<<this->id<<"�Ѿ���������ϣ��뿪���С�"<<endl;
}
OfficialUser::~OfficialUser()
{
    //dtor
}

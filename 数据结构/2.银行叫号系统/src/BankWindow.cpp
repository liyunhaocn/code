#include "BankWindow.h"
#include<iostream>
using namespace std;

BankWindow::~BankWindow()
{
    //dtor
}

BankWindow::BankWindow(){type=NULL;}//构造函数
BankWindow::BankWindow(bool isBusy,int id,User client,char *type)
{
    this->isBusy=isBusy;
    this->id=id;
    this->client=client;
    this->type=type;
}
void BankWindow:: HandleUser()//处理用户服务
{
	cout<<"正在为"<<this->client.type<<this->client.id<<"服务"<<endl;
}

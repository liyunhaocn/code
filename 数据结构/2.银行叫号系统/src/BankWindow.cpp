#include "BankWindow.h"
#include<iostream>
using namespace std;

BankWindow::~BankWindow()
{
    //dtor
}

BankWindow::BankWindow(){type=NULL;}//���캯��
BankWindow::BankWindow(bool isBusy,int id,User client,char *type)
{
    this->isBusy=isBusy;
    this->id=id;
    this->client=client;
    this->type=type;
}
void BankWindow:: HandleUser()//�����û�����
{
	cout<<"����Ϊ"<<this->client.type<<this->client.id<<"����"<<endl;
}

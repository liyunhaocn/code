#include "NormalBankWindow.h"
#include<iostream>
using namespace std;

NormalBankWindow::NormalBankWindow():BankWindow(){}
NormalBankWindow::NormalBankWindow(bool isBusy,int id,User client):BankWindow(isBusy,id, client,"普通窗口"){}
NormalBankWindow::~NormalBankWindow()
{
    //dtor
}

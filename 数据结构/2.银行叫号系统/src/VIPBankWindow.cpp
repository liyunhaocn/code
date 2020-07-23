#include "VIPBankWindow.h"
#include<iostream>
using namespace std;

VIPBankWindow::VIPBankWindow():BankWindow(){}

VIPBankWindow::VIPBankWindow(bool isBusy,int id,User client):BankWindow(isBusy,id, client,"VIP窗口"){}

VIPBankWindow::~VIPBankWindow()
{
    //dtor
}

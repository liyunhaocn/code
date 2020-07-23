#include "OfficialBankWindow.h"
#include<iostream>
using namespace std;

OfficialBankWindow::OfficialBankWindow():BankWindow(){}
OfficialBankWindow::OfficialBankWindow(bool isBusy,int id,User client):BankWindow(isBusy,id, client,"公用窗口"){}

OfficialBankWindow::~OfficialBankWindow()
{
    //dtor
}

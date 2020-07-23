#ifndef NORMALBANKWINDOW_H
#define NORMALBANKWINDOW_H
#include"User.h"
#include"BankWindow.h"

class NormalBankWindow:public BankWindow
{
    public:
        NormalBankWindow();
        virtual ~NormalBankWindow();
	    NormalBankWindow(bool isBusy,int id,User client);
    protected:
    private:
};

#endif // NORMALBANKWINDOW_H

#ifndef VIPBANKWINDOW_H
#define VIPBANKWINDOW_H
#include"User.h"
#include"BankWindow.h"

class VIPBankWindow :public BankWindow
{
    public:
        VIPBankWindow();
        virtual ~VIPBankWindow();
	    VIPBankWindow(bool isBusy,int id,User client);
    protected:
    private:
};

#endif // VIPBANKWINDOW_H

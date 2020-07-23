#ifndef OFFICIALBANKWINDOW_H
#define OFFICIALBANKWINDOW_H
#include"User.h"
#include"BankWindow.h"

class OfficialBankWindow:public BankWindow
{
    public:
        OfficialBankWindow();
        virtual ~OfficialBankWindow();
        OfficialBankWindow(bool isBusy,int id,User client);
    protected:
    private:
};

#endif // OFFICIALBANKWINDOW_H

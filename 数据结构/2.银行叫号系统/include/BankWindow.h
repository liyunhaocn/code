#ifndef BANKWINDOW_H
#define BANKWINDOW_H
#include"User.h"

class BankWindow
{
    public:
        bool isBusy;
        int id;
        User client;
        char * type;
        BankWindow();
	    BankWindow(bool isBusy,int id,User client,char *type);
        virtual ~BankWindow();
        void HandleUser();

    protected:
    private:
};

#endif // BANKWINDOW_H

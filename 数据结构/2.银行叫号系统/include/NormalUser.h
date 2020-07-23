#ifndef NORMALUSER_H
#define NORMALUSER_H
#include"User.h"

class NormalUser: public User
{
    public:
        NormalUser();
        virtual ~NormalUser();
        NormalUser(int id, int isWait,int arriveTime,int serveTime);
        void getServed();
    protected:
    private:
};

#endif // NORMALUSER_H

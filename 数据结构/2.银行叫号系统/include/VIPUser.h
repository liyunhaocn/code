#ifndef VIPUSER_H
#define VIPUSER_H
#include"User.h"

class VIPUser: public User
{
    public:
        VIPUser();
        virtual ~VIPUser();
	VIPUser(int id, int isWait,int arriveTime,int serveTime);
	void getServed();
    protected:
    private:
};

#endif // VIPUSER_H

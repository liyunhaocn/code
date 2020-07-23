#ifndef OFFICIALUSER_H
#define OFFICIALUSER_H
#include"User.h"

class OfficialUser : public User
{
    public:
    OfficialUser();
	OfficialUser(int id, int isWait,int arriveTime,int serveTime);
	void getServed();
	virtual ~OfficialUser();
    protected:
    private:
};

#endif // OFFICIALUSER_H

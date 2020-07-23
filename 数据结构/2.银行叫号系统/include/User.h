#ifndef USER_H
#define USER_H


class User
{
    public:
        int id;
        int isWait;
        int arriveTime;
        int serveTime;
        char * type;
        User();
        User(int id, int isWait,int arriveTime,int serveTime,char *type);
        virtual ~User();
        void getServed();
    protected:
    private:


};

#endif // USER_H

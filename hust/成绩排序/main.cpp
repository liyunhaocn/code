#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct stu{
    string name;
    int age;
    int score;
    stu(string name,int age,int score){
        this->name = name;
        this->age = age;
        this->score =  score;
    }
    stu(){}
};

bool cmp(stu a,stu b){
    if( a.score == b.score){
        if(a.name == b.name){
            return a.age < b.age;
        }else{
            return a.name < b.name;
        }
    }else{
        return a.score < b.score;
    }
}

int main()
{
    int N;
    while( scanf("%d",&N)!= EOF){
        vector<stu> stus;
        string name;
        int age;
        int score;
        for(int i = 0;i < N;i ++){
            cin>> name;
            cin>> age;
            cin>> score;
            stus.push_back( stu(name,age,score) );
        }
        sort(stus.begin(),stus.end(),cmp );
        for(int i=0;i<stus.size();i++){
            printf("%s %d %d\n",stus[i].name.c_str(),stus[i].age,stus[i].score );
        }
    }
    return 0;
}

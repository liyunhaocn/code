#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
using namespace std;
struct person{
    int age;
    int o_id;
    string name;
}P[100002];

bool cmp(person a,person b){
    if(a.age<b.age){
        return true;
    }else if(a.age==b.age){
        if(a.name<b.name){
            return true;
        }else if(a.name==b.name){
            if(a.o_id<b.o_id){
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }

    }else{
        return false;
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cin>>P[i].o_id;
        cin>>P[i].name;
        cin>>P[i].age;
    }

    sort(P+1,P+n+1,cmp);
    scanf("%d",&n);
    printf("%d\n",P[n].o_id);
    return 0;
}

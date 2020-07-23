#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
using namespace std;

int main()
{
    int T;
    string name;
    string sex;
    double height;
    double weight;
    double standerWeight;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        cin>>name;
        cin>>sex;
        scanf("%lf",&height);
        scanf("%lf",&weight);
        if(sex == "male"){
            standerWeight = (height - 80)* 0.7;
        }else{
            standerWeight = (height - 70)* 0.6;
        }
        weight -=standerWeight;
        weight /=standerWeight;

        if(-0.1 <= weight && weight <= 0.1){
            cout<<name<<" "<<sex<<" "<<"正常体重"<<endl;
        }else if(-0.2 <= weight && weight < -0.1){
            cout<<name<<" "<<sex<<" "<<"体重过轻"<<endl;
        }else if(0.1 < weight && weight <= 0.2){
            cout<<name<<" "<<sex<<" "<<"体重过重"<<endl;
        }else if(weight<-0.2){
            cout<<name<<" "<<sex<<" "<<"体重不足"<<endl;
        }else{
            cout<<name<<" "<<sex<<" "<<"肥胖"<<endl;
        }
    }
    return 0;
}

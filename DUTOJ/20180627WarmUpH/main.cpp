#include <iostream>
#include <stdio.h>
using namespace std;
int a[14];
int b[12];

bool printB(){
    for(int i=0;i<12;i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;
}


bool qidui(){
    for(int i=0;i<14;i+=2){
        if(a[i]!=a[i+1]){
            return false;
        }
        if( i<11 && a[i]==a[i+2]){
            return false;
        }
    }
    return true;
}

bool takeTwo(int n){
    int dex=0;
    for(int i=0;i<n;i++){
        b[dex++]=a[i];
    }
    for(int i=n+2;i<14;i++){
        b[dex++]=a[i];
    }
}

int zhong(int n){

    if(n<=9){
        return 1;
    }else if(n<=18){
        return 2;
    }else{
        return 3;
    }


}
bool shunzi(int n){
    if(n>9){
        return false;
    }else {
        int counter = 0;
        for(int i=n;i<n+3;i++){
            if(zhong(b[n])== zhong(b[n+1]) && zhong(b[n+1]) == zhong(b[n+2])){
                if(b[n]+1==b[n+1] && b[n+1]+1==b[n+2]){
                    return true;
                }
            }
        }
        return false;
    }
}
bool kezi(int n){

    if(n>9){
        return false;
    }else if(b[n]==b[n+1] && b[n+1]==b[n+2]){
        return true;
    }else
        return false;

}
bool san(int n){
    if(n>9){
        return false;
    }else if(shunzi(n)){
        return true;
    }else if(kezi(n)){
        return true;
    }else{
        return false;
    }
}
bool allsan(){
    for(int i=0;i<10;i+=3){
        if(!san(i)){
            return false;
        }
    }
    return true;
}

bool duanyaojiu(){
    for(int i=0;i<14;i++){
        if(a[i]==1 || a[i]==9 || a[i]==10 || a[i]==18 || a[i]==19 || a[i]==27){
            return false;
        }
        //cout<<"1"<<endl;
        return true;
    }
}
bool chunquan(int n){
    bool fal1=false;
    for(int i=n;i<n+2;i++){
        if(a[i]==1 || a[i]==9 || a[i]==10 || a[i]==18 || a[i]==19 || a[i]==27){
            fal1 = true;
        }
    }
    int k=0;
    for(int i= 0;i<10;i+=3){
        bool flg=false;
        for(int j=i;j<i+3;j++){
            if(b[j]==1 || b[j]==9 || b[j]==10 || b[j]==18 || b[j]==19 || b[j]==27){
                flg=true;
            }
        }
        if(flg)k++;
    }
    if(k==4&&fal1){
         //cout<<"2"<<endl;
         return true;

    }else
        return false;
}

bool pinghu(){
    for(int i=0;i<10;i+=3){
        if(!shunzi(i)){
            return false;
        }
    }
    //cout<<"3"<<endl;
    return true;
}

bool duiduihu(){
    for(int i=0;i<10;i+=3){
        if(!kezi(i)){
            return false;
        }
    }
    //cout<<"4"<<endl;
    return true;
}
bool hu(){
    if(qidui()){
        return true;
    }else{
        bool flag=false;
        int yigedui;

        for(int i=0;i<13;i++){
            takeTwo(i);
            if(allsan()){
                flag = true;
                yigedui = i;
                //cout<<"yigedui "<<yigedui<<endl;
                break;
            }
            //printB();
        }
        //cout<<"flag "<<flag<<endl;
       return (flag && duanyaojiu())||(flag && chunquan(yigedui))||(flag && pinghu())||(flag && duiduihu());


    }
}


int main()
{
    int t;
    scanf("%d",&t);
    int type;

    while(t--){
        for(int i=0;i<14;i++){
            scanf("%d",&a[i]);
        }
        printf("%d\n",hu());
    }
    return 0;
}

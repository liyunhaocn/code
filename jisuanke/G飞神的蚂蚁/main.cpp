#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int fang = 0;
    const int N = 10000;
    int i=5000,j=5000;
    int counter=0;
    long long int k = 0;
    int **a = new int* [N];
    for(int i=0;i<N;i++){
        a[i] = new int[N];
    }
    while(i< N && j< N && i>=0 && j>=0){
        //printf("%d %d\n",i,j);
        //printf("%d \n",a[i][j]);
        //printf("fang %d \n",fang);
        k++;
        if(a[i][j]%2==0){

            a[i][j]++;
            if(fang==0){
                j++;

            }else if(fang ==1){
                i++;
            }else if(fang ==2){
                j--;
            }else if(fang ==3){
                i--;
            }
            counter++;
            //printf("+1");
            fang++;
            fang %=4;
        }else{

            a[i][j]++;
            if(fang==0){
                j--;
            }else if(fang ==1){
                i--;
            }else if(fang ==2){
                j++;
            }else if(fang ==3){
                i++;
            }
            counter--;
            //printf("-1");
            fang--;
            fang =(fang+4)%4;
        }
        if( k >= 20007 && k<=20009){
            cout<<k<<" "<<counter<<endl;

        }

    }

    return 0;
}
//´ð°¸
//115384615384614953



#include <iostream>
#include <stdio.h>
#include <iostream>
#include <unordered_map>
using namespace std;
int a[52] = {1,2,3, 5, 8, 13, 20, 31, 47, 71, 107, 161, 242, 364, 547, 821, 1232, 1849, 2774, 4162, 6244, 9367, 14051, 21077, 31616, 47425, 71138, 106708, 160063, 240095, 360143, 540215, 810323, 1215485, 1823228, 2734843, 4102265, 6153398, 9230098, 13845148, 20767723, 31151585, 46727378, 70091068, 105136603, 157704905, 236557358, 354836038, 532254058, 798381088, 1197571633, 1796357450};
unordered_map<int,int>mp;
bool isshu(int temp){
    if(mp[temp]==1){
        return true;
    }else{
        return false;
    }
}
void init(){
    for(int i=0;i<52;i++){
        mp[a[i] ]=1;
    }
}
int main()
{
    int T;
    int temp;

    init();
    scanf("%d",&T);

    for(int i=0;i<T;i++){
        scanf("%d",&temp);
        if(isshu(temp) ){
            printf("Xiaoming\n");
        }else{
            printf("Xiaohong\n");
        }

    }

    return 0;
}

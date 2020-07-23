#include <iostream>
#include <algorithm>
using namespace std;
typedef struct{
    int a;
    int b;
} node;
node nodes[100001];
int b[100001];
bool com(node a,node b){
    return a.a>b.a;
}
int nums_ori[10001];
int findPosIndex(int * nums,int n, int target){

    for (int i = 0; i <= n - 1; i++){
        if (nums[i] == target){
            //cout << "pos: " << i << endl;
            return i;
        }
    }
return -1;
}

int sortWithLeastExchange1(int *nums,int n){
    for(int i=0;i<n;i++){
        nums_ori[i] = nums[i];
    }
    int count = 0;
    sort(nums, nums+n);

    for (int i = 0; i < n - 1; i++){
        int posIndex = findPosIndex(nums_ori, n,nums[i]);
        if (posIndex == i) continue;
        //cout << "exhange: " << nums_ori[i] << ":" << nums_ori[posIndex] << endl;
        swap(nums_ori[i], nums_ori[posIndex]);
        count++;
    }
    return count ;
}

int main()
{
    int n;
    int c[5]= {7,6,3,2,1};
    cout<<sortWithLeastExchange1(c,5)<<endl;


    cin>>n;


    for(int i=0;i<n;i++){
        cin>>nodes[i].a;
    }
    for(int i=0;i<n;i++){
        cin>>nodes[i].b;
    }
    sort(nodes,nodes+n,com);
    for(int i=0;i<n;i++){
        b[i]=nodes[i].b;
    }

    cout<<sortWithLeastExchange1(b,n)<<endl;
}

#include<stdio.h>
#include<string.h>
#include<iostream>
#include<climits>
using namespace std;

struct seg
{
    int l;
    int r;
    int n;
} T[350011];

void build(int l,int r,int k)
{
    int mid;
    if(l==r)
    {
        T[k].l=l;
        T[k].r=r;
        T[k].n=0;
        return ;
    }


    mid=(l+r)/2;
    T[k].l=l;
    T[k].r=r;
    T[k].n=0;
    build(l,mid,2*k);
    build(mid+1,r,2*k+1);
}


void insert(int n,int d,int k)
{
    int mid;
    if(T[k].l==T[k].r&&T[k].l==d)
    {
        T[k].n =n;
        return ;
    }
    mid=(T[k].l+T[k].r)>>1;
    if(d<=mid)	insert(n,d,2*k);
    else		insert(n,d,2*k+1);
    T[k].n = min(T[2*k].n,T[2*k+1].n);
}


int ans;
int search(int l,int r,int k)
{
    int mid;
    if(r<T[k].l ||l>T[k].r)return INT_MAX;
    //printf("l = %d,r = %d\n",l);
    mid=(T[k].l+T[k].r)>>1;
    if(T[k].l>=l&&T[k].r<=r){
        return T[k].n;
    }else{
        return min(search(l,r,2*k),search(mid+1,r,2*k+1));
    }

}


int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    build(1,n,1);
    printf("2222222\n");
    for(int i=1;i<=m;i++){
        int temp;
        printf("111111111\n");
        scanf("%d",&temp);
        insert(temp,i,1);
    }
    for(int i=0;i<n; i++)
    {
        int a ,b;
        scanf("%d%d",&a,&b);
        search(a,b,1);
        printf("%d\n",ans);

    }
    return 0;
}

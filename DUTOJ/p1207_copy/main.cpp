#include<bits/stdc++.h>
using namespace std;
long long num[5][2000100];
const int mod=1000000007;
long long pp(long long a,int k)
{
	long long now=a;
	for(int i=1;i<k;i++)
	{
		now*=a;
		now%=mod;
	}
	return now;
}
void yuchuli()
{
	for(int i=0;i<5;i++)
	{
		for(int j=1;j<2000010;j++)
		{
			num[i][j]=(num[i][j-1]+pp(j,i+1))%mod;
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	yuchuli();
	long long ans=0;
	int a,b,k;
	while(t--)
	{
		scanf("%d%d%d",&a,&b,&k);
		if(a>b) swap(a,b);
		ans+=num[k-1][b]-num[k-1][a-1];
		ans%=mod;
	}
	printf("%lld\n",(ans+mod)%mod);
}

#include<bits/stdc++.h>
using namespace std;
char a[1000005],b[1000005];
int p[1000005],n,m;

void pre()	//��p����
{
	p[1]=0;
	int j=0;
	for(int i=1;i<m;i++)
	{
		while(j>0&&b[j+1]!=b[i+1])j=p[j];
		if(b[j+1]==b[i+1])j++;
		p[i+1]=j;
	}
}
int kmp()
{
	int ans=0,j=0;
	for(int i=0;i<n;i++)
	{
		while(j>0&&b[j+1]!=a[i+1])j=p[j];
		if(b[j+1]==a[i+1])j++;
		if(j==m){
			ans++;
			//printf("! %d ",i+1-m);
			//j=0;	//��ͷ��ʼƥ�䱣֤���ص������������ص������Բ��ø�0
		}
	}
	return ans;
 }
int main()
{
	while(cin>>a+1)//��ʾ������ַ�������Ϊa[1]
	{
		scanf("%s",b+1);
		m=strlen(b+1);
		n=strlen(a+1);
		pre();
        for(int i=1;i<=m;i++){
            cout<<p[i];
        }
		printf("%d\n",kmp());

	}
	return 0;
}

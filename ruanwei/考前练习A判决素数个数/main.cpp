#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
#define LL long long

#define MAX_L 1000007
#define MAX_SORT_B 1000007

bool is_prime[MAX_L];
bool is_prime_small[MAX_SORT_B];

//������[a,b)�ڵ�����ִ��ɸ����isprime[i - a]=true <=> i������

void segment_sieve(LL a,LL b)
{
    for(int i=0; (LL)i*i < b; i++)is_prime_small[i]=true;
    for(int i=0; i<b-a; i++)is_prime[i]=true;
    for(int i=2; (LL)i * i<b; i++)
    {
        if(is_prime_small[i])
        {
            for(int j=2*i; (LL)j * j < b; j += i)
            {
                is_prime_small[j]=false;//ɸ[2,sqrt(b))
            }
            for(LL j=max(2LL, (a+i-1)/i)*i ; j<b; j+=i) //(a+i-1)/iΪ[a,b)�����ڵĵ�һ��������Ϊi�Ķ��ٱ�.
            {
                is_prime[j - a] =false;//ɸ[a,b)
            }
        }
    }
}

int main()
{
    long long a,b;
    while(~scanf("%lld %lld",&a,&b))
    {
        segment_sieve(a,b);
        int cnt=0;
        for(int j=0; j<b-a; j++)
        {
            if(is_prime[j])cnt++;
        }
        if(a==1)cnt--;
        printf("%d\n",cnt);
    }
    return 0;
}

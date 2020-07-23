#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;
const int maxn=405;

vector<int> a[maxn];
int p[maxn],q[maxn];
bool f[maxn][maxn],v[maxn];
int n,m,b,w,tot,mm;

void dfs(int x)
{
     int i,y;
     v[x]=true;
     if (x<=n) w++;
     else b++;
     for (i=0;i<a[x].size();i++)
     {
         y=a[x][i];
         if (v[y]) continue;
         dfs(y);
     }
}

int main()
{
    //freopen("pin.txt","r",stdin);
    //freopen("pou.txt","w",stdout);
    int i,j,k,cc;
    scanf("%d",&cc);
    while (cc--)
    {
          scanf("%d%d",&n,&m);
          for (i=0;i<=2*n;i++)
              a[i].clear();
          memset(f,0,sizeof(f));
          memset(v,0,sizeof(v));
          tot=0;
          for (i=1;i<=m;i++)
          {
              int x,y;
              scanf("%d%d",&x,&y);
              a[x].push_back(y+n);
              a[y+n].push_back(x);
          }
          for (i=1;i<=n+n;i++)
          if (!v[i])
          {
             b=w=0;
             dfs(i);
             p[++tot]=w;q[tot]=b;
          }
          f[0][0]=true;
          mm=0;
          for (i=1;i<=tot;i++)
          {
              for (j=n/2;j>=p[i];j--)
                  for (k=n/2;k>=q[i];k--)
                  {
                      if (f[j-p[i]][k-q[i]])
                         f[j][k]=true;
                  }
              mm=max(mm+p[i],mm+q[i]);
          }
          for (i=n/2;i>=0;i--)
              if (f[i][i]) break;
          cout << i << endl;
    }
    return 0;
}

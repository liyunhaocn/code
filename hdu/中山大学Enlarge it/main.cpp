#include <iostream>
#include <stdio.h>
using namespace std;

char a[101][101];

int main()
{
    int n,m,k;
    while( ~scanf("%d%d%d",&n,&m,&k)){
        getchar();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                scanf("%c",&a[i][j]);
            }
            getchar();
        }
        for(int i=0;i<n;i++){
            for(int i1 = 0; i1 < k;i1++){
                for(int j=0;j<m;j++){
                    for(int kk = 0;kk<k;kk++){
                        cout<<a[i][j]<<" ";
                    }

                }
                cout<<endl;
            }
        }
    }

    return 0;
}

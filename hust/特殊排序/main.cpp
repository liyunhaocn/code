#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;


int main()
{
    int n;
    vector<int> a;
    while( scanf("%d",&n) != EOF){
        int temp;
        for(int i=0;i<n;i++){
            scanf("%d",&temp);
            a.push_back(temp);
        }
        sort(a.begin(),a.end());
        int mmax = a.back();
        printf("%d\n",mmax);
        a.pop_back();

        if(a.size()==0){
            printf("-1\n");
        }else{
            for(int i=0;i<a.size();i++){
                printf("%d ",a[i]);
            }
            printf("\n");
        }
    }
    return 0;
}

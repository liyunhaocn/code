#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <stack>
#include <math.h>
#include <vector>

using namespace std;

using LL = long long;


#define debug(x) cout<<#x<<": "<<(x)<<endl;
#define out(x) cout<<#x<<": "<<(x)<<" ";

int p[16];
int k[16];

int main() {
    int n;
    scanf("%d",&n);
    LL maxL=1;
    for(int i=0;i<n;i++){
        scanf("%d", &p[i]);
        scanf("%d", &k[i]);
        maxL *= k[i] + 1;
    }
    vector<LL> ans;
    ans.reserve(maxL);
    ans.push_back(1);
    for(int i = 0;i < k[0];i ++){
        ans.push_back( ans[ans.size()-1] * p[0]);
    }
    for(int i=1;i<n;i++){
        int alen = ans.size();
        for(int j=0;j < k[i];j++){
            int aend = ans.size() -1;
            for(int k = 0; k < alen; k ++ ){
               ans.push_back( ans[aend-k] * p[i]);
            }
        }
    }
    for(LL a:ans){
        cout<<a<<endl;
    }
    return 0;
}

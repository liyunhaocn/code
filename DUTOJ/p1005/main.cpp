#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
using namespace std;
#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    int sum(vector<int>& A){
        int ret = 0;
        for(int i=0;i<A.size();i++){
            ret += A[i];
        }
        return ret;
    }
    int largestSumAfterKNegations(vector<int>& A, int K) {
        if(A.size() == 0){
            return 0;
        }
        sort(A.begin(),A.end());

        int i=0;
        for(i=0;i<A.size();i++){
            if(K>0 && A[i]<0){
                A[i] = -A[i];
                K--;
            }else{
                break;
            }
        }

        if(K>0){
            if(K%2==0){
                return sum(A);
            }else{
                int m = INT_MAX;
                int pos=0;
                for(int j=0;j<A.size();j++){
                    if(A[j]<m){
                        m = A[j];
                        pos = j;
                    }

                }
                A[pos] = -A[pos];
                return sum(A);
            }
        }else{
            return sum(A);
        }

    }
};

int main()
{
    Solution Solution1;
    vector<int> A = {-8,3,-5,-3,-5,-2};
    int K = 6;
    cout<<Solution1.largestSumAfterKNegations(A,K)<<endl;
    return 0;
}

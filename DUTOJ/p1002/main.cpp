#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> ret;
        vector<int>sum(26,0x3f3f3f3f);

        for(int i=0;i<A.size();i++){
            vector<int>tem(26,0);
            for(int j=0;j<A[i].size();j++){
                tem[A[i][j]-'a']++;
            }
            for(int j=0;j<26;j++){
                sum[j] = min(sum[j],tem[j]);
            }
        }
        for(int i=0;i<sum.size();i++){
            for(int j=0;j<sum[i];j++){
                string tt = string(1,i+'a');
                ret.push_back(tt);
            }
        }
        return ret;
    }
};

int main()
{
    Solution Solution1;
    vector<string>a = {"bella","label","roller"};
    Solution1.commonChars(a);

    return 0;
}

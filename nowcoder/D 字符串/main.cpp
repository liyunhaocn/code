#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <climits>
#include <algorithm>
#include <sstream>
#include <functional>
#include <bitset>
#include <numeric>
#include <cmath>
#include <regex>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;


class Solution
{
public:
    string removeDuplicateLetters(string s) {
        vector<int> vec(256,0);
        vector<bool> visited(256,0);
        for(char c : s)
            vec[c]++;
        string res = "";
        for(char c : s){
            vec[c]--;//ÿ�α���һ���ַ��ͽ������ֵĴ�����һ
            if(visited[c])//����Ƿ���ʹ�
                continue;
            while(vec[res.back()] && c < res.back()){
                visited[res.back()] = false;
                res.pop_back();
            }
            res += c;
            visited[c] = true;
        }
        return res;
    }
};

int main(){
    Solution Solution1;
    string s;
    cin>>s;
    cout<<Solution1.removeDuplicateLetters(s)<<endl;
return 0;
}

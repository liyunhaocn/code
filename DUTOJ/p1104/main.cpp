#include <iostream>
#include <vector>
#include <algorithm>
#include <regex>
#include <stdio.h>
using namespace std;
#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
	bool pat(string s1,string s2) {
		debug(s1);
		regex rule(s1);
		//cout << regex_match(s2, rule) << endl; //true
		//return regex_match(s2, rule);
	}
};

int main()
{
	Solution Solution1;
	string s1,s2;
	int T;
	scanf("%d",&T);
	getchar();
	for(int t=0;t<T;t++){
        char c;
        s1 = "";
        s2 = "";
        while( (c = getchar())!='\n'){
            if(c!='$'){
                s1.push_back(c);
            }else{
                s1 += "\\w";
            }
        }
        while( (c = getchar())!='\n'){
            s2.push_back(c);
        }
        Solution1.pat(s1,s2);
	}


	return 0;
}


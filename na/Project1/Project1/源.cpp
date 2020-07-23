#include <iostream>
#include <vector>
#include <algorithm>
#include <regex>
using namespace std;

class Solution {
public:
	bool isNumber(string s) {
		//string fronte = "\\s*\\-?\\+?(([0-9]+)|(([0-9]+[.][0-9]*)|([0-9]*[.][0-9]+)))";
		//string ab0 = "[1-9][0-9]*";
		//string epart = "(e[0-9]+)?\\s*";
		//string ret = fronte + epart;
		string ret = "[-+]?(\\d+\\.?|\\.\\d+)\\d*(e[-+]?\\d+)?";
		regex rule(ret);
		cout << regex_match(s, rule) << endl; //true
		return regex_match(s, rule);
	}
};

int main()
{
	Solution Solution1;
	string s;
	while(cin>>s)
	Solution1.isNumber(s);
	return 0;
}

//https://ac.nowcoder.com/acm/contest/551/C

#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
set<string> s[100];
string a, t;
int main() {
    ll n, m;
    cin >> n >> m >> a;
    ll lap = 0, ans = (n - m + 1) * (n - m + 2) / 2;
    for (int i = m; i <= min(n, 15LL); i++) {
        for (int j = 0; j <= a.size() - i; j++){
            t = a.substr(j, i);
            if (s[i].find(t) != s[i].end())
                lap++;
            else
                s[i].insert(t);
        }
    }
    printf("%lld", ans - lap);
    return 0;
}

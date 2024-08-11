#include<bits/stdc++.h>
using namespace std;
//#define int long long
bool check(string s)
{
    int n = s.size();
    if (n == 1) return 1;
    for (int i = 1; i < n - 1; i ++)
        if (s[i] == s[i + 1])
            return check(s.substr(0, i) + s.substr(i + 2, n - (i + 2)));
    return 0;
}
int main(){
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    string s; cin >> s;
    s = " " + s; int cnt = 0;
    for (int l = 1; l <= n; l ++)
    {
        string tmp = " ";
        for (int len = 2; l + len - 1 <= n; len += 2)
        {
            int r = l + len - 1;
            tmp += s[r - 1]; tmp += s[r];
            cnt += check(tmp);
        }
    }
    cout << cnt;

    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int n, cnt;
string s;
bool check(int l, int r) {
    string t = "";
    for(int i = l; i <= r; i++) t += s[i];
    while(1) {
        string tmp = "";
        for(int i = 0; i < t.length(); i++)
            if(i < t.length() - 1 && t[i] == t[i + 1]) i++;
            else tmp += t[i];
        if(t == tmp) break;
        t = tmp;
    }
    if(t.length()) return 0;
    return 1;
}
signed main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>s;
    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++)
            if(check(i, j)) cnt++;
    cout<<cnt<<endl;
    return 0;
}
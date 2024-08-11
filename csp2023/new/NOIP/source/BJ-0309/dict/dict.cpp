#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 3e3 + 5;
int n, m;
string s[maxn], r[maxn], l[maxn], mx, pre[maxn], suf[maxn], x, y;
int main(){
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    if(n == 1){
        cout << '1';
        return 0;
    }
    for(int i = 1; i <= n; ++i){
        cin >> s[i];
        x = s[i], y = s[i];
        sort(x.begin(), x.end(), greater<char>());
        sort(y.begin(), y.end());
        r[i] = x, l[i] = y;
        if(i == 1 || r[i] < mx) pre[i] = r[i], mx = r[i];
        else pre[i] = pre[i - 1];
    }
    for(int i = n; i >= 1; --i)
        if(i == n || r[i] < mx) suf[i] = r[i], mx = r[i];
        else suf[i] = suf[i + 1];
    if(l[1] < suf[2]) cout << '1';
    else cout << '0';
    for(int i = 2; i < n; ++i)
        if(l[i] < pre[i - 1] && l[i] < suf[i + 1]) cout << '1';
        else cout << '0';
    if(l[n] < pre[n - 1]) cout << '1';
    else cout << '0';
    return 0;
}
//hope:100pts
//O(nmlogm)
//but it spend 1.8s in codeblocks
//wish you can running faster

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e3 + 5;
int n; int m;
string ss[maxn];
int cnt[maxn];
string pf[maxn], ps[maxn];
int main(){
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> ss[i];
        for(int j = 0;j < 26;j++) cnt[j] = 0;
        for(auto t : ss[i]) cnt[t - 'a']++;
        int now = 0;
        for(int j = 25;j >= 0;j--){
            for(int k = now;k < now + cnt[j];k++) ss[i][k] = (char)(j + 'a');
            now += cnt[j];
        }
    }
    pf[1] = ss[1];
    for(int i = 2;i <= n;i++) pf[i] = min(pf[i - 1], ss[i]);
    ps[n] = ss[n];
    for(int i = n - 1;i >= 1;i--) ps[i] = min(ps[i + 1], ss[i]);
    for(int i = 1;i <= n;i++){
        string tp = ss[i]; reverse(tp.begin(), tp.end());
        bool fl = 1;
        if(i > 1) fl &= (tp < pf[i - 1]);
        if(i < n) fl &= (tp < ps[i + 1]);
        cout << fl;
    }
    cout << endl; return 0;
}

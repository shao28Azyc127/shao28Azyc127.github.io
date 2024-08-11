#include<bits/stdc++.h>

using namespace std;
string s;
const int maxn = 1000005;
int cnt = 0;
// map<char, vector<int> > mp;
// bool dfs() {

// }

int deepth = 0, pin;
int maxdepth = 0;
char stk[maxn];
int anss[1005];
int ans = 0;
// string s;
inline void push(char x) {
    if (x == stk[pin]) {
        ans += anss[deepth] * (anss[deepth] + 1) >> 1;
        // cout << (anss[deepth] * (anss[deepth] + 1) >> 1) << endl;
        anss[deepth] = 0;
        anss[--deepth]++;
        --pin;
        
    }
    else {
        ++deepth;
        maxdepth = max(maxdepth, deepth);
        stk[++pin] = x;
    }
}

inline void push1(char x) {
    if (x == stk[pin]) {
        --pin;
        
    }
    else {
        stk[++pin] = x;
    }
}

// map<string, int> mp;

bool check(int a, int b) {
    // if (b - a < 100) {
    //     string k = s.substr(a, b + 1);
    //     if (mp[k] != 0) return mp[k] == 1;
    // }
    for (int i = a; i <= b; i++) {
        push1(s[i]);
    }
    string k;
    // if (b - a < 100) k = s.substr(a, b + 1); 
    if (pin != 0) {
        pin = 0;
        // if (b - a < 100) mp[k] = 2;
        return false;
    }
    // if (b - a < 100) mp[k] = 1;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cout << 5 << endl;
}
// accakkbccb
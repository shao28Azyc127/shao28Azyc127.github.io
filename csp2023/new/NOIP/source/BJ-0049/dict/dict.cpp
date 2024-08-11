#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 3005
#define fopen(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout);

using namespace std;

int n, m, cnt[105], prem[maxn], sufm[maxn];

string a[maxn], b[maxn];

inline string str_sort(string &s) {
    string t = "";
    for(int i = 1; i <= 26; i++) cnt[i] = 0;
    for(char ch : s) cnt[ch - 96]++;
    for(int i = 1; i <= 26; i++) {
        while(cnt[i]--) t += (char)(i + 96);
    }
    return t;
}

inline bool str_cmp(string &a, string &b) { //a < b ?
    for(int i = 0; i < m; i++) {
        if(a[i] != b[i]) return a[i] < b[i];
    }
    return false;
}

int main() {
    fopen("dict")
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i] = str_sort(a[i]);
        reverse(a[i].begin(), a[i].end());
        if(i == 1) prem[i] = 1;
        else prem[i] = str_cmp(a[i], a[prem[i - 1]]) ? i : prem[i - 1];
    }
    for(int i = n; i >= 1; i--) {
        if(i == n) sufm[i] = n;
        else sufm[i] = str_cmp(a[i], a[sufm[i + 1]]) ? i : sufm[i + 1];
    }
    for(int i = 1; i <= n; i++) {
        int t = str_cmp(a[prem[i]], a[sufm[i]]) ? prem[i] : sufm[i];
        if(t == i || str_cmp(b[i], a[t])) {
            cout << "1";
        }
        else cout << "0";
    }
}
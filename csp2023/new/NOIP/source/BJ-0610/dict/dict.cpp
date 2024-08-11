#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

#define int long long

const int maxn = 3010;
int n, m;
string s[maxn];
int maxch[maxn], minch[maxn];
int maxcnt[maxn], mincnt[maxn];

signed main() {
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> s[i];
    }
    memset(maxch, 0, sizeof(maxch));
    memset(minch, 0x3f, sizeof(minch));
    for (int i = 1;i <= n;i++) {
        for (int j = 0;j < s[i].size();j++) {
            maxch[i] = max(maxch[i], (long long)s[i][j]);
            minch[i] = min(minch[i], (long long)s[i][j]);
        }
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 0;j < s[i].size();j++) {
            if (s[i][j] == maxch[i]) {
                maxcnt[i]++;
            }
            if (s[i][j] == minch[i]) {
                mincnt[i]++;
            }
        }
    }
    //for (int i = 1;i <= n;i++) {
        //cout << char(maxch[i]) << " max with times " << maxcnt[i] << "///";
        //cout << char(minch[i]) << " min with times " << mincnt[i] << endl;
    //}
    for (int i = 1;i <= n;i++) {
        bool nowans = true;
        for (int j = 1;j <= n;j++) {
            if (j != i) {
                if (minch[i] > maxch[j]) {
                    nowans = false;
                    //cout << "IF1: ";
                    break;
                }
                if ((minch[i] == maxch[j])) {
                    nowans = false;
                    //cout << "IF2: ";
                    break;
                }
            }
        }
        cout << nowans;
    }
    cout << endl;
    return 0;
}

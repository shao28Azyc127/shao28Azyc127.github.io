#include <algorithm>
#include <cstring>
#include <cstdio>
#include <iostream>

using namespace std;

typedef unsigned long long ULL;
const int MAXN = 3005;
const ULL B = 137;
const ULL MOD = 1e9 + 7;
int n, m;
char s[MAXN][MAXN];
char smax[MAXN][MAXN];
char smin[MAXN][MAXN];
ULL smaxn[MAXN][MAXN], sminn[MAXN][MAXN];

inline bool cmp(char a, char b) {
    return a > b;
}

int main() {
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> s[i];
        for(int j = 0; j < m; ++j) smax[i][j] = smin[i][j] = s[i][j];
        ULL base = 1;
        sort(smin[i], smin[i] + m);
        //cout << smin[i] << endl;
        //cout << i << "->" << endl;
        for(int j = 0; j < m; j++) {
            if(j == 0) sminn[i][j] = smin[i][j];
            else sminn[i][j] = (sminn[i][j - 1] + smin[i][j] * base) % MOD;
            //cout << sminn[i][j] << " ";
            base *= B;
            base %= MOD;
        }
        //cout << endl;
        sort(smax[i], smax[i] + m, cmp);
        //cout << smax[i] << endl;
        base = 1;
        for(int j = 0; j < m; ++j) {
            if(j == 0) smaxn[i][j] = smax[i][j];
            else smaxn[i][j] = (smaxn[i][j - 1] + smax[i][j] * base) % MOD;
            base *= B;
            base %= MOD;
        }
    }
    for(int i = 1; i <= n; i++) {
        bool flag = 0;
        for(int j = 1; j <= n; ++j) {
            if(i == j) continue;
            int l = 0, r = m - 1, mid;
            while(r - l > 10) {
                mid = (l + r) / 2;
                if(sminn[i][mid] == smaxn[j][mid]) l = mid + 1;
                else r = mid;
            }
            mid = -1;
            for(; l <= r; l++) {
                if(sminn[i][l] != smaxn[j][l]) {
                    mid = l;
                    break;
                }
            }
            if(smin[i][mid] > smax[j][mid]) {
                flag = 1;
                break;
            }
        }
        if(flag) printf("0");
        else printf("1");
    }
    return 0;
}

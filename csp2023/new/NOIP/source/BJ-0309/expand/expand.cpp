#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 5e5 + 5;
const int maxn2 = 2e3 + 5;
int C, n, m, q, kx, ky, p, v, a[maxn], b[maxn], c[maxn], d[maxn];
bool f[maxn2][maxn2];
int solve1(){
    int x = 1, y = 1, dir;
    if(a[1] > b[1] && a[n] > b[m]) dir = 1;
    else if(a[1] < b[1] && a[n] < b[m]) dir = 0;
    else return 0;
    if(dir){
        while(x <= n && y <= m){
            while(y <= m && a[x] > b[y]) y++;
            if(y > m){
                for(int i = x + 1; i <= n; ++i)
                    if(a[i] <= b[m]) return 0;
                return 1;
            }
            x++;
        }
        return 0;
    } else {
        while(x <= n && y <= m){
            while(y <= m && a[x] < b[y]) y++;
            if(y > m){
                for(int i = x + 1; i <= n; ++i)
                    if(a[i] >= b[m]) return 0;
                return 1;
            }
            x++;
        }
        return 0;
    }
}
int solve2(){
    int dir;
    if(a[1] > b[1] && a[n] > b[m]) dir = 1;
    else if(a[1] < b[1] && a[n] < b[m]) dir = 0;
    else return 0;
    if(dir){
        f[1][1] = 1;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j){
                if(i == 1 && j == 1) continue;
                f[i][j] = (a[i] > b[j]) && (f[i - 1][j] || f[i][j - 1]);
            }
        return f[n][m];
    } else {
        f[1][1] = 1;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j){
                if(i == 1 && j == 1) continue;
                f[i][j] = (a[i] < b[j]) && (f[i - 1][j] || f[i][j - 1]);
            }
        return f[n][m];
    }
}
int main(){
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    scanf("%d%d%d%d", &C, &n, &m, &q);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]), c[i] = a[i];
    for(int i = 1; i <= m; ++i) scanf("%d", &b[i]), d[i] = b[i];
    printf("%d", C > 7 ? solve1() : solve2());
    while(q--){
        memset(f, 0, sizeof(f));
        scanf("%d%d", &kx, &ky);
        for(int i = 1; i <= n; ++i) a[i] = c[i];
        for(int i = 1; i <= m; ++i) b[i] = d[i];
        while(kx--) scanf("%d%d", &p, &v), a[p] = v;
        while(ky--) scanf("%d%d", &p, &v), b[p] = v;
        printf("%d", C > 7 ? solve1() : solve2());
    }
    return 0;
}

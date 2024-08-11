#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 3010;
typedef long long ll;
typedef unsigned long long ull;
int c, q, n, m;
int xi[MAXN], yi[MAXN];
ll read()
{
    ll ans = 0;
    char inc = getchar();
    for(; inc < '0' || inc > '9'; ) inc = getchar();
    for(; inc >= '0' && inc <= '9'; ){
        ans = ans * 10 + inc - '0';
        inc = getchar();
    }
    return ans;
}
int ai[MAXN], bi[MAXN];
int d[MAXN][MAXN];
void work(int kx, int ky)
{
    for(int i = 1; i <= n; i++) ai[i] = xi[i];
    for(int i = 1; i <= m; i++) bi[i] = yi[i];
    for(int i = 1; i <= kx; i++) {
        int pi, vi;
        pi = read(), vi = read();
        ai[pi] = vi;
    }
    for(int i = 1; i <= ky; i++) {
        int pi, vi;
        pi = read(), vi = read();
        bi[pi] = vi;
    }
    int flag = 0;
    if(ai[n] > bi[m] && ai[1] > bi[1]) flag = 0;
    else if(ai[n] < bi[m] && ai[1] < bi[1]) flag = 1;
    else{
        printf("0");
        return;
    }
    d[0][0] = d[1][0] = d[0][1] = 1;
    for(int i = 1; i <= n; i++){
        fill(d[i], d[i] + m + 1, 0);
        for(int j = 1; j <= m; j++){
            if(flag == 0){
                if(ai[i] <= bi[j]) continue;
                d[i][j] = d[i - 1][j] | d[i][j - 1] | d[i - 1][j - 1];
            }
            else {
                if(ai[i] >= bi[j]) continue;
                d[i][j] = d[i - 1][j] | d[i][j - 1] | d[i - 1][j - 1];
            }
            //cout << d[i][j] << " ";
        }
       // cout << "\n";
    }
    printf("%d", d[n][m]);
    return;
}
int main()
{
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    c = read(), n = read(), m = read(), q = read();
    for(int i = 1; i <= n; i++) xi[i] = read();
    for(int i = 1; i <= m; i++) yi[i] = read();
    work(0, 0);
    while(q--){
        int kx, ky;
        kx = read(), ky = read();
        work(kx, ky);
    }
    return 0;
}
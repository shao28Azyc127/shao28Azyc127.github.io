#include<bits/stdc++.h>
#define ll long long
using namespace std;

template<typename T>
void read(T &a) {
    char ch;bool flag = a = 0;
    for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') flag = true;
    for(;ch>='0'&&ch<='9';a=a*10+ch-'0',ch=getchar());
    if(flag) a*=-1;
}

ll ans;
ll n;
ll a[10][10];
ll b[10];
bool vis[100010][10];
ll t[] = {0, 10000, 1000, 100, 10, 1};

int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    for(int i=0;i<=99999;i++) {
        vis[i][0] = true;
    }
    read(n);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=5;j++) {
            read(a[i][j]);
            b[i] *= 10;
            b[i] += a[i][j];
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=5;j++) {
            for(int k=0;k<=9;k++) {
                if(k == a[i][j]) continue;
                if(vis[b[i] - a[i][j] * t[j] + k * t[j]][i-1]) vis[b[i] - a[i][j] * t[j] + k * t[j]][i] = 1;
            }
        }
        for(int j=1;j<=4;j++) {
            for(int k=1;k<=9;k++) {
                ll finalj0 = (a[i][j] - k + 10) % 10;
                ll finalj1 = (a[i][j+1] - k + 10) % 10;
                if(vis[b[i] - a[i][j] * t[j]  - a[i][j+1] * t[j+1] + finalj0 * t[j] + finalj1 * t[j+1]][i-1]) vis[b[i] - a[i][j] * t[j]  - a[i][j+1] * t[j+1] + finalj0 * t[j] + finalj1 * t[j+1]][i] = 1;
            }
        }
    }
    for(int i=0;i<=99999;i++) {
        if(vis[i][n]) ans++;
    }
    printf("%lld", ans);
    return 0;
}

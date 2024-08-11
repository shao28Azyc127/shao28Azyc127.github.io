#include<bits/stdc++.h>
using namespace std;
const int maxn = 10;
int n;
int a[maxn],b[maxn],c[maxn],d[maxn],e[maxn];
bool can(int a1,int b1,int c1,int d1,int e1,int a2,int b2,int c2,int d2,int e2){
    int f[10];
    f[1] = a1 - a2;
    f[2] = b1 - b2;
    f[3] = c1 - c2;
    f[4] = d1 - d2;
    f[5] = e1 - e2;
    if(f[1] != 0 && f[2] == 0 && f[3] == 0 && f[4] == 0 && f[5] == 0) return true;
    if(f[1] == 0 && f[2] != 0 && f[3] == 0 && f[4] == 0 && f[5] == 0) return true;
    if(f[1] == 0 && f[2] == 0 && f[3] != 0 && f[4] == 0 && f[5] == 0) return true;
    if(f[1] == 0 && f[2] == 0 && f[3] == 0 && f[4] != 0 && f[5] == 0) return true;
    if(f[1] == 0 && f[2] == 0 && f[3] == 0 && f[4] == 0 && f[5] != 0) return true;
    if(f[1] != 0 && f[2] != 0 && f[3] == 0 && f[4] == 0 && f[5] == 0 && f[1] == f[2]) return true;
    if(f[1] == 0 && f[2] != 0 && f[3] != 0 && f[4] == 0 && f[5] == 0 && f[2] == f[3]) return true;
    if(f[1] == 0 && f[2] == 0 && f[3] != 0 && f[4] != 0 && f[5] == 0 && f[3] == f[4]) return true;
    if(f[1] == 0 && f[2] == 0 && f[3] == 0 && f[4] != 0 && f[5] != 0 && f[4] == f[5]) return true;
    return false;
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i] >> d[i] >> e[i];
    if(n == 1){
        cout << 81 << endl;
        return 0;
    }
    int na,nb,nc,nd,ne;
    na = a[1],nb = b[1],nc = c[1],nd = d[1],ne = e[1];
    int ans = 0;
    for(int i = 0; i <= 9; i++){
        if(i == a[1]) continue;
        na = i;
        for(int j = 2; j <= n; j++){
            if(can(na,nb,nc,nd,ne,a[j],b[j],c[j],d[j],e[j])) ans++;
        }
    }
    na = a[1];
    for(int i = 0; i <= 9; i++){
        if(i == b[1]) continue;
        nb = i;
        for(int j = 2; j <= n; j++){
            if(can(na,nb,nc,nd,ne,a[j],b[j],c[j],d[j],e[j])) ans++;
        }
    }
    nb = b[1];
    for(int i = 0; i <= 9; i++){
        if(i == c[1]) continue;
        nc = i;
        for(int j = 2; j <= n; j++){
            if(can(na,nb,nc,nd,ne,a[j],b[j],c[j],d[j],e[j])) ans++;
        }
    }
    nc = c[1];
    for(int i = 0; i <= 9; i++){
        if(i == d[1]) continue;
        nd = i;
        for(int j = 2; j <= n; j++){
            if(can(na,nb,nc,nd,ne,a[j],b[j],c[j],d[j],e[j])) ans++;
        }
    }
    nd = d[1];
    for(int i = 0; i <= 9; i++){
        if(i == e[1]) continue;
        ne = i;
        for(int j = 2; j <= n; j++){
            if(can(na,nb,nc,nd,ne,a[j],b[j],c[j],d[j],e[j])) ans++;
        }
    }
    ne = e[1];
    for(int i = 1; i <= 9; i++){
        na = (a[1] + i) % 10;
        nb = (b[1] + i) % 10;
        for(int j = 2; j <= n; j++){
            if(can(na,nb,nc,nd,ne,a[j],b[j],c[j],d[j],e[j])) ans++;
        }
    }
    na = a[1];
    nb = b[1];
    for(int i = 1; i <= 9; i++){
        nb = (b[1] + i) % 10;
        nc = (c[1] + i) % 10;
        for(int j = 2; j <= n; j++){
            if(can(na,nb,nc,nd,ne,a[j],b[j],c[j],d[j],e[j])) ans++;
        }
    }
    nb = b[1];
    nc = c[1];
    for(int i = 1; i <= 9; i++){
        nc = (c[1] + i) % 10;
        nd = (d[1] + i) % 10;
        for(int j = 2; j <= n; j++){
            if(can(na,nb,nc,nd,ne,a[j],b[j],c[j],d[j],e[j])) ans++;
        }
    }
    nc = c[1];
    nd = d[1];
    for(int i = 1; i <= 9; i++){
        nd = (d[1] + i) % 10;
        ne = (e[1] + i) % 10;
        for(int j = 2; j <= n; j++){
            if(can(na,nb,nc,nd,ne,a[j],b[j],c[j],d[j],e[j])) ans++;
        }
    }
    nd = d[1];
    ne = e[1];
    cout << ans << endl;
    return 0;
}
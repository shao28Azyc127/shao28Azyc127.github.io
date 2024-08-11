#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;
long long n,m,k,u[1000],v[1000],a[1000],vv[10000][10000],vis[10000+10],minn1,minn2,b[10000+10];
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf ("%lld %lld %lld", &n, &m, &k);
    for (int i=1;i<=m;i++){
        for (int j=1;j<=m;j++) vv[i][j] = 2147483647;
    }
    for (int i=1;i<=m;i++){
        scanf ("%lld %lld %lld", &u[i], &v[i], &a[i]);
        vv[u[i]][v[i]] = 1;
        if (a[i]){
            printf ("-1");
            return 0;
        }
    }
    vis[1] = 1;
    for (int i=2;i<=m;i++){
        b[i] = vv[1][i];
    }
    for (int i=2;i<=m;i++){
        minn1 = minn2 = 2147483647;
        for (int j=1;j<=m;j++){
            if (!vis[j]&&minn1>b[j]){
                minn1 = b[j];
                minn2 = j;
            }
        }
        if (minn1==2147483647) break;
        vis[minn2] = 1;
        for (int j=1;j<=m;j++){
            if (!vis[j]&&b[j]>vv[j][minn2]+b[minn2]) b[j] = vv[j][minn2]+b[minn2];
        }
    }
    printf ("%lld\n", k+b[n]);
    return 0;
}

//rp++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++,you know?
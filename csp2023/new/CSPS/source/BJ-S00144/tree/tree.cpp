#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

const int N=1e5+5;

long long n,a[10005][10005],u,v,x,ok,pos=1,g[N],m;

struct plc{
    long long a,b,c,now;
}pl[N];

int main() {
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin >> n;
    for(long long i=1;i<=n;i++) {
        cin >> pl[i].a >> pl[i].b >> pl[i].c;
        pl[i].now=0;
    }
    for(long long i=1;i<n;i++) {
        cin >> u >> v;
        a[u][v]=1;
        a[v][u]=1;
    }
    while(ok<=n) {
        x++;
        g[x]=pos;
        for(long long i=1;i<=x;i++) {
            long long p1=pl[i].b+x*pl[i].c,p2=1;
            pl[i].now+=max(p1,p2);
            if(pl[i].now>=pl[i].a) ok++;
        }
        for(long long i=1;i<=n;i++) {
            if(a[pos][i]) {
                long long p1=pl[i].b+x*pl[i].c,p2=1;
                long long p3=max(p1,p2);
                m=max(m,p3);
            }
        }
        pos=m;
    }
    cout << x;
    return 0;
}

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cmath>
#define int long long
#define ull unsigned long long
using namespace std;
const int N=500005;
int c,m,n,q;
int x[N],y[N],tpx[N],tpy[N];
signed main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    scanf("%lld%lld%lld%lld",&c,&m,&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%lld",&x[i]);
        tpx[i]=x[i];
    }
    for(int i=1;i<=m;i++){
        scanf("%lld",&y[i]);
        tpy[i]=y[i];
    }
    int j=2;
    bool flag1=false;
    if(x[1]<=y[1])flag1=true;
    for(int i=1;i<=n;i++){
        if(x[i]<=y[j]){
            flag1=true;
            break;
        }
        while(x[i+1]<=y[j]&&j<=m)j++;
    }
    if(x[n]<=y[m])flag1=true;
    j=2;
    bool flag2=false;
    if(y[1]<=x[1])flag2=true;
    for(int i=1;i<=m;i++){
        if(y[i]<=x[j]){
            flag2=true;
            break;
        }
        while(y[i+1]<=x[j]&&j<=n)j++;
    }
    if(y[n]<=x[m])flag2=true;
    if(!flag1||!flag2)putchar('1');
    else putchar('0');
    while(q--){
        int kx,ky;
        for(int i=1;i<=n;i++)x[i]=tpx[i];
        for(int i=1;i<=m;i++)y[i]=tpy[i];
        scanf("%lld%lld",&kx,&ky);
        for(int i=1;i<=kx;i++){
            int p,v;
            scanf("%lld%lld",&p,&v);
            x[p]=v;
        }
        for(int i=1;i<=ky;i++){
            int p,v;
            scanf("%lld%lld",&p,&v);
            y[p]=v;
        }
        int j=2;
        bool flag1=false;
        if(x[1]<=y[1])flag1=true;
        for(int i=1;i<=n;i++){
            if(x[i]<=y[j]){
                flag1=true;
                break;
            }
            while(x[i+1]<=y[j]&&j<=m)j++;
        }
        if(x[n]<=y[m])flag1=true;
        j=2;
        bool flag2=false;
        if(y[1]<=x[1])flag1=true;
        for(int i=1;i<=m;i++){
            if(y[i]<=x[j]){
                flag2=true;
                break;
            }
            while(y[i+1]<=x[j]&&j<=n)j++;
        }
        if(y[n]<=x[m])flag2=true;
        if(!flag1||!flag2)putchar('1');
        else putchar('0');
    }
    return 0;
}

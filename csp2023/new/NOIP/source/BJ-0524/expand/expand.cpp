#include <bits/stdc++.h>
#define ll long long
#define db double
#define MAXN 100000
#define P 998244353

using namespace std;


int c,n,m,q;
ll x[MAXN+5];
ll y[MAXN+5];
int idx[MAXN+5];
int idy[MAXN+5];

bool chk(int p,int q){
    return x[1]>y[1]&&p<q||x[1]<y[1]&&p>q||x[1]==y[1]||p==q;
}

int main(){

    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);

    scanf("%d%d%d%d",&c,&n,&m,&q);
    for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
    for(int i=1;i<=m;i++) scanf("%lld",&y[i]);

    printf("%d",!chk(x[n],y[m]));

    ll x1[MAXN+5],y1[MAXN+5];
    for(int i=1;i<=n;i++) x1[i]=x[i];
    for(int i=1;i<=m;i++) y1[i]=y[i];

    while(q--){
        int kx,ky;
        int a,b;

        scanf("%d%d",&kx,&ky);
        for(int i=1;i<=n;i++) x[i]=x1[i];
        for(int i=1;i<=m;i++) y[i]=y1[i];

        for(int i=1;i<=kx;i++) {scanf("%d%d",&a,&b); x[a]=b;}
        for(int i=1;i<=ky;i++) {scanf("%d%d",&a,&b); y[a]=b;}

        printf("%d",!chk(x[n],y[m]));
    }
    printf("\n");
    return 0;
}

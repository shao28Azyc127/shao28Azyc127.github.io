#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5005;

ll rd() {
    ll s=0, f=1;
    char ch=getchar();
    for(; !isdigit(ch); ch=getchar())
        if(ch=='-') f=-1;
    for(; isdigit(ch); ch=getchar())
        s=(s<<1)+(s<<3)+(ch^48);
    return s*f;
}

ll c, n, m, q, ans[N];
ll x[N], y[N], xx[N], yy[N];

bool f[N][N];

bool check() {

    memset(f, 0, sizeof f);

    if(x[1]>y[1]) {// x>y
        f[1][1]=1;

        for(ll i=1; i<=m; i++)
            if(x[1]>y[i]) f[1][i]=1;
            else break;
        for(ll i=1; i<=n; i++)
            if(x[i]>y[1]) f[i][1]=1;
        else break;

   //     for(ll i=1; i<=n; i++, cout << endl)
     //       for(ll j=1; j<=m; j++) cout << f[i][j]<<" ";

        for(ll i=2; i<=n; i++)
            for(ll j=2; j<=m; j++) {
                if(f[i][j-1] && x[i]>y[j]) f[i][j]=1;
                if(f[i-1][j-1] && x[i]>y[j]) f[i][j]=1;
                if(f[i-1][j] && x[i]>y[j]) f[i][j]=1;
            }

     //   for(ll i=1; i<=n; i++, cout << endl)
      //      for(ll j=1; j<=m; j++) cout << f[i][j]<<" ";

    } else if(x[1]<y[1]) {
        f[1][1]=1;

        for(ll i=1; i<=m; i++)
            if(x[1]<y[i]) f[1][i]=1;
            else break;
        for(ll i=1; i<=n; i++)
            if(x[i]<y[1]) f[i][1]=1;
            else break;

    //    for(ll i=1; i<=n; i++, cout << endl)
       //     for(ll j=1; j<=m; j++) cout << f[i][j]<<" ";

        for(ll i=2; i<=n; i++)
            for(ll j=2; j<=m; j++) {
                if(f[i][j-1] && x[i]<y[j]) f[i][j]=1;
                if(f[i-1][j-1] && x[i]<y[j]) f[i][j]=1;
                if(f[i-1][j] && x[i]<y[j]) f[i][j]=1;
            }

     //   for(ll i=1; i<=n; i++, cout << endl)
        //    for(ll j=1; j<=m; j++) cout << f[i][j]<<" ";
    }

    if(f[n][m]) return 1;
    return 0;
}

void work() {
    ll a=rd(), b=rd(), u=0, v=0;

        for(ll i=1; i<=a; i++) {
            scanf("%lld %lld", &u, &v);
            x[u]=v;
        }

        for(ll i=1; i<=b; i++) {
            scanf("%lld %lld", &u, &v);
            y[u]=v;
        }

        if(check()) printf("1");
        else printf("0");

        for(ll i=1; i<=n; i++) x[i]=xx[i];
        for(ll i=1; i<=n; i++) y[i]=yy[i];
}

int main() {
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);

    scanf("%lld %lld %lld %lld", &c, &n, &m, &q);

    for(ll i=1; i<=n; i++) scanf("%lld", &x[i]), xx[i]=x[i];
    for(ll i=1; i<=m; i++) scanf("%lld", &y[i]), yy[i]=y[i];

    if(check()) printf("1");
    else printf("0");

    while(q--) {
        work();
    }

    return 0;
}






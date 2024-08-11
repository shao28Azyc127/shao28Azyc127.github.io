#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1000005;

ll rd() {
    ll s=0, f=1;
    char ch=getchar();
    for(; !isdigit(ch); ch=getchar())
        if(ch=='-') f=-1;
    for(; isdigit(ch); ch=getchar())
        s=(s<<1)+(s<<3)+(ch^48);
    return s*f;
}

ll C, T, n, m;

struct que{
    ll v, x1, x2;
};
que c[N];

ll w[N], b[N], ans;

bool check() {
    for(ll i=1; i<=n; i++) b[i]=w[i];
    for(ll i=1; i<=m; i++) {
        if(c[i].v==1) {
            if(w[c[i].x2]==3) w[c[i].x1]=3;
            else if(w[c[i].x2]==5) w[c[i].x1]=4;
            else if(w[c[i].x2]==4) w[c[i].x1]=5;
        } else if(c[i].v==2) {
            w[c[i].x1]=w[c[i].x2];
        } else if(c[i].v==3) {
            w[c[i].x1]=3;
        } else if(c[i].v==4) {
            w[c[i].x1]=4;
        } else if(c[i].v==5) {
            w[c[i].x1]=5;
        }
    }
    ll f=1;
    for(ll i=1; i<=n; i++) {
        if(b[i]!=w[i]) {
            f=0;
        }
        w[i]=b[i];
    }
    return f;
}

void dfs(ll p, ll s) {
//    cout << p <<" " <<s <<endl;
    if(p>=n+1) {
        if(check()) {
            ans=min(ans, s);
            //for(ll i=1; i<=n; i++)
        }
        return;
    }
    w[p]=3;
    dfs(p+1, s+1);
    w[p]=4;
    dfs(p+1, s);
    w[p]=5;
    dfs(p+1, s);
}

void work() {
    scanf("%lld %lld", &n, &m);

    memset(w, 0, sizeof w);
    ans=n;

    for(ll i=1; i<=m; i++) {
    //        cout << i <<endl;
        char ch;
        cin>>ch;
        if(ch=='-') {
            ll u=rd(), v=rd();
            c[i]=(que) {1, u, v};
        } else if(ch=='+') {
            ll u=rd(), v=rd();
            c[i]=(que) {2, u, v};
        } else if(ch=='U') {
            ll u=rd();
            c[i]=(que) {3, u, 0};
            w[u]=3;
        } else if(ch=='T') {
            ll u=rd();
            c[i]=(que) {4, u, 0};
        } else if(ch=='F') {
            ll u=rd();
            c[i]=(que) {5, u, 0};
        }
    }

    dfs(1, 0);

    printf("%lld\n", ans);

}

int main() {
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    scanf("%lld %lld", &C, &T);
    while(T--) work();
    return 0;
}


/*

struct edge {
    ll Next, to, w;
} e[N];
ll head[N], cnt=1;
void add(ll u, ll v, ll w) {
    e[++cnt]=(edge) {head[u], v, w};
    head[u]=cnt;
}

*/

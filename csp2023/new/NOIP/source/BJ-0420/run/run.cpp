#include<bits/stdc++.h>
using namespace std;
struct run{
    long long x, y, v;
};
struct node{
    long long l, r, maxx, lazy;
};
long long n, m, k, d;
node p[40010];
long long f[1010][1010];
vector<run> ask[10010];
void push_down(long long x) {
    p[x<<1].maxx = max(p[x<<1].maxx, p[x].lazy);
    p[x<<1].lazy = max(p[x<<1].lazy, p[x].lazy);
    p[x<<1|1].maxx = max(p[x<<1|1].maxx, p[x].lazy);
    p[x<<1|1].lazy = max(p[x<<1|1].lazy, p[x].lazy);
    p[x].lazy = 0;
}
void push_up(long long x) {
    p[x].maxx = max(p[x<<1].maxx, p[x<<1|1].maxx);
}
void build(long long x, long long l, long long r) {
    p[x].l=l, p[x].r=r;
    p[x].maxx = p[x].lazy = 0;
    if(l==r) return ;
    long long mid = (l+r)>>1;
    build(x<<1, l, mid), build(x<<1|1, mid+1, r);
}
void update(long long x, long long s, long long t, long long v) {
    long long l=p[x].l, r=p[x].r;
    if(l==s && r==t) {
        p[x].maxx = max(p[x].maxx, v);
        p[x].lazy = max(p[x].lazy, v);
        return ;
    }
    if(p[x].lazy) push_down(x);
    long long mid = (l+r)>>1;
    if(t<=mid) update(x<<1, s, t, v);
    else if(s>mid) update(x<<1|1, s, t, v);
    else update(x<<1, s, mid, v), update(x<<1|1, mid+1, t, v);
    push_up(x);
}
long long getmax(long long x, long long s, long long t) {
    long long l=p[x].l, r=p[x].r;
    if(l==s && r==t) return p[x].maxx;
    if(p[x].lazy) push_down(x);
    long long mid = (l+r)>>1;
    if(t<=mid) return getmax(x<<1, s, t);
    if(s>mid) return getmax(x<<1|1, s, t);
    return max(getmax(x<<1, s, mid), getmax(x<<1|1, mid+1, t));
}
int main() {
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    long long opt, T;
    cin >> opt >> T;
    if(opt==17 || opt==18) {

        while(T--) {
            cin >> n >> m >> k >> d;
            long long ans = 0;
            for(long long i=1; i<=m; ++i) {
                long long x, y, v;
                cin >> x >> y >> v;
                if(y*d<v && y<=k && x-y>=0) ans += v-y*d;
            }
            cout << ans << '\n';
        }
        return 0;
    }
    //cout << "reach" << '\n';
    while(T--) {
        memset(f, 0, sizeof(f));
        cin >> n >> m >> k >> d;
        for(long long i=1; i<=n; ++i) ask[i].clear();
        //cout << "reach" << '\n';
        build(1, 0, n);
        for(long long i=1; i<=m; ++i) {
            long long x, y, v;
            cin >> x >> y >> v;
            ask[x].push_back(run{x, y, v});
        }
        //cout << "reach" << '\n';
        for(long long i=1; i<=n; ++i) {
            for(long long j=0; j<=min(i, k); ++j) {
                if(i-j>0) f[i][j] = getmax(1, 0, i-j-1)-d*j;
                else f[i][j] = -d*j;
                for(long long ij=i-j+1; ij<=i; ++ij) {
                    for(long long k=0; k<ask[ij].size(); ++k) {
                        if(ij-i+j>=ask[ij][k].y) f[i][j] += ask[ij][k].v;
                    }
                }
                update(1, i, n, f[i][j]);
            }
            //cout << "reach" << '\n';
        }
        cout << getmax(1, 1, n) <<'\n';
    }
    return 0;
}

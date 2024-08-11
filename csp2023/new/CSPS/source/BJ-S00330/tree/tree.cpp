#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,t[100010],r,bb,x,l,h[100010],minn[100010],ans=-1;
struct node {
    int u,v,next;
}edge[100010];
void ae(int a,int u,int v) {
    edge[a].u=u;
    edge[a].v=v;
    edge[a].next=h[u];
    h[u]=a;
}
void dfs(int u) {
    for (int a=h[u];a;a=edge[a].next) {
        int v=edge[a].v;
        if (minn[v]) continue;
        minn[v]=minn[u]+1;
        dfs(v);
    }
    return;
}
signed main () {
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    ios::sync_with_stdio(false);
    cin >>n;
    for (int a=1;a<=n;a++) {
        //cout <<a<<endl;
        cin >>r>>bb>>x;
        if (x==0) {
            t[a]=r/bb;
            if (r%bb) t[a]++;
            continue;
        }
        if (r<=bb+x) {
            t[a]=1;
            continue;
        }
        if (x<0) {
            int mt=(1-bb)/(x),l=(bb+x+bb+x*mt)*mt/2;
            if (l<r) {
                t[a]=mt;
                t[a]+=r-l;
                continue;
            }
        }
        t[a]=0;
        l=0;
        while (l<r) {
            t[a]++;
            if (1<bb+x*t[a]) l+=(bb+x*t[a]);
            else {
                t[a]+=(r-l-1);
                break;
            }
        }
    }
    for (int a=1;a<n;a++) {
        int u,v;
        cin >>u>>v;
        ae(a*2-1,u,v);
        ae(a*2,v,u);
    }
    minn[1]=1;
    dfs(1);
    for (int a=1;a<=n;a++) {
        ans=max(ans,minn[a]+t[a]);
    }
    cout <<ans-1;
    return 0;
}

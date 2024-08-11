//40pts
#include<bits/stdc++.h>
#define ll long long
#define mkp(x,y) make_pair(x,y);
using namespace std;
const int N=1e5+5;
const int M=1e6+5;
const int INF=2e9+5;
int c,t,n,m,tot,ans,vis[N],res[20],now[20];
struct Q {
    int x,y,op;
}q[N];
bool check() {
    for(int i=1;i<=n;i++)now[i]=res[i];
    for(int i=1;i<=tot;i++) {
        if(q[i].op==0) {
            now[q[i].x]=q[i].y;
        }
        else if(q[i].op==1) {
            now[q[i].x]=now[q[i].y];
        } else {
            now[q[i].x]=-now[q[i].y];
        }
    }
    for(int i=1;i<=n;i++)if(now[i]!=res[i])return 0;
    return 1;
}
void dfs1(int dep,int sum) {
    if(dep>n) {
        if(check()) {
            ans=min(ans,sum);
        }
        return;
    }
    else  {
        res[dep]=1;
        dfs1(dep+1,sum);
        res[dep]=-1;
        dfs1(dep+1,sum);
        res[dep]=0;
        dfs1(dep+1,sum+1);
    }
}
void solve1() {
    scanf("%d%d",&n,&m);
    tot=0;ans=INF;
    while(m--) {
        char v;
        int x,y;
        cin>>v;
        if(v=='T'||v=='F'||v=='U') {
            scanf("%d",&x);
            if(v=='T')q[++tot]={x,1,0};
            if(v=='F')q[++tot]={x,-1,0};
            if(v=='U')q[++tot]={x,0,0};
        } else if(v=='+') {
            scanf("%d%d",&x,&y);
            q[++tot]={x,y,1};
        } else if(v=='-') {
            scanf("%d%d",&x,&y);
            q[++tot]={x,y,2};
        }
    }
    dfs1(1,0);
    printf("%d\n",ans);
}
void solve2() {
    scanf("%d%d",&n,&m);ans=0;
    memset(vis,0,sizeof(vis));
    while(m--) {
        char v;
        int x;
        cin>>v;
        scanf("%d",&x);
        if(v=='T') {
            vis[x]=1;
        } else if(v=='F') {
            vis[x]=2;
        } else {
            vis[x]=3;
        }
    }
    for(int i=1;i<=n;i++)if(vis[i]==3)ans++;
    printf("%d\n",ans);
}

void solve3() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)vis[i]=0;ans=tot=0;
    while(m--) {
        char v;
        int x,y;
        cin>>v;
        if(v=='U') {
            scanf("%d",&x);
            vis[x]=1;
        } else {
            scanf("%d%d",&x,&y);
            vis[x]=vis[y];
        }
    }
    for(int i=1;i<=n;i++)if(vis[i]==3)ans++;
    printf("%d\n",ans);
}

int dfs2(int dep,int now,int sum) {
    if(dep>n)return (sum%2==0?1:2);
    for(int i=dep;i<=tot;i++) {
        if(q[i].op==0&&q[i].x==now)return q[i].y;
        if(q[i].op==1&&q[i].x==now) {
            return dfs2(dep+1,q[i].y,sum);
        }
        if(q[i].op==2&&q[i].x==now) {
            return 4-dfs2(dep+1,q[i].y,sum+1);
        }
        if(i==tot)return (sum%2==0?1:2);
    }
}
void solve5() {
    scanf("%d%d",&n,&m);
    memset(vis,0,sizeof(vis));ans=tot=0;
    while(m--) {
        char v;
        int x,y;
        cin>>v;
        if(v=='T'||v=='F'||v=='U') {
            scanf("%d",&x);
            if(v=='T')q[++tot]={x,1,0};
            if(v=='F')q[++tot]={x,3,0};
            if(v=='U')q[++tot]={x,2,0};
        } else if(v=='+') {
            scanf("%d%d",&x,&y);
            q[++tot]={x,y,1};
        } else if(v=='-') {
            scanf("%d%d",&x,&y);
            q[++tot]={x,y,2};
        }
    }
    reverse(q+1,q+tot+1);
    for(int i=1;i<=n;i++) {
        if(!vis[i])vis[i]=dfs2(1,i,0);
        if(vis[i]==2)ans++;
    }
    printf("%d\n",ans);
}

int main() {
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--) {
       // solve5();
        if(c==1||c==2)solve1();
        if(c==3||c==4)solve2();
        if(c==5||c==6)solve3();
        if(c==9||c==10)solve5();
    }
    return 0;
}

#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
inline ll read(){
    ll f=1,s=0;char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') f=-1;ch=getchar(); }
    while(ch>='0'&&ch<='9'){ s=s*10+ch-'0';ch=getchar(); }
    return s*f;
}
struct area{
    ll a,b,c;
} tree[100010];
ll tr[100010];
bool vis[100010];
vector<int> g[100010];
priority_queue<pair<ll,int> > q;
bool operator <(const pair<ll,int> a , const pair<ll,int> b){
    return a.first<b.first;
}

ll maxn=-1;
void bfs(){
    ll day=0;
    while(!q.empty()){
        day++;
        ll cur=q.top().second;
        maxn=max(tr[cur]+day,maxn);
        q.pop();
        for(auto i:g[cur]){
            if(vis[i]) continue;
            vis[i]=1;
            q.push({tr[i],i});
        }
    }
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    int u,v;
    for(int i=1;i<=n;i++){
        tree[i].a=read();tree[i].b=read();tree[i].c=read();
        tr[i]=tree[i].a/tree[i].b+((tree[i].a%tree[i].b)?1:0);
    }
    for(int i=1;i<n;i++){
        u=read();v=read();
        g[u].push_back(v);
        g[v].push_back(u);
    }
    q.push({tr[1],1});
    vis[1]=1;
    bfs();
    cout<<maxn<<endl;
    return 0;
}

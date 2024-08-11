#include<bits/stdc++.h>
//#pragma GCC optmize(2)
#define int long long
using namespace  std;
int n,tot;
int a[100005];
int b[100005];
int c[100005];
struct edge{
    signed v,next;
}e[200005];
int h[100005];
void addedge(int u,int v){
    e[++tot].v=v;
    e[tot].next=h[u];h[u]=tot;
}
__int128 get_hight(int l,int r,int x){
    if(c[x]>=0)return __int128(r-l+1)*b[x]+__int128(c[x])*(l+r)*(r-l+1)/2;
    else {
        int hhh=(b[x]-1)/(-c[x]);
        if(l>hhh)return r-l+1;
        if(r<=hhh)return __int128(r-l+1)*b[x]+__int128(c[x]*(l+r)*(r-l+1)/2);
        else return (r-hhh)+(__int128(hhh-l+1)*b[x]+__int128(c[x])*(l+hhh)*(hhh-l+1)/2);
    }
    /*__int128 ans=0;
    for(int i=l;i<=r;i++)ans+=max((b[i]+i*c[i]),1LL);
    return ans;*/
}
inline int get_tim(int x,int tim){
    int l=1,r=tim,ans=-1;
    while(l<=r){
        int mid=(l+r)>>1;
        //assert(get_hight(mid,tim,x)>=0);
        if(get_hight(mid,tim,x)<a[x]){
           r=mid-1;
        }
        else{
            ans=mid;
            l=mid+1;
        }
    }
    return ans;
}
int tim[100005];
vector<int>hh[100005];
int hh2[100005];
//vector<int>hh2;
void dfs(int fa,int u){
    hh[u].clear();
    //cout<<u<<"dsaf"<<endl;
    //hh[u].insert(tim[u]);
    int Min=0x3f3f3f3f3f3f3f3f;
    for(int i=h[u];i;i=e[i].next){
        int v=e[i].v;
        if(v==fa)continue;
        dfs(u,v);
        //int now=tim[v];
        hh[u].push_back(tim[v]);
    }
    sort(hh[u].begin(),hh[u].end());
    int r=-1;
    for(int i=hh[u].size()-1;i>=0;i--){
        int val=hh[u][i];
        while(r>=0 &&hh2[r]>val)r--;
        int now=val;
        while(r>=0 && hh2[r]==now)r--,now--;
        hh2[++r]=now;
    }
    if(r==-1)return ;
    tim[u]=min(hh2[0]-1,tim[u]);
}
struct node{
    int u;int tim;
};
bool operator <(node a,node b){
    return a.tim>b.tim;
}
bool vis[100005];
bool check(int x){
   //cout<<x<<endl;
    for(int i=1;i<=n;i++){
            tim[i]=get_tim(i,x)/*,cout<<x<<" "<<i<<" "<<tim[i]<<endl*/;
            if(tim[i]==0)return 0;
    }
    dfs(0,1);
    //for(int i=1;i<=n;i++)cout<<x<<" "<<i<<" "<<tim[i]<<endl;
    //if(x==1e9)cout<<"asdf";
    if(tim[1]<1)return 0;
    priority_queue<node>q;
    memset(vis,0,sizeof(vis));
    int Tim=1;
    q.push(node{1,tim[1]});
    while(!q.empty()){
        node temp=q.top();
        q.pop();
        if(temp.tim<Tim){return 0;}
        Tim++;
        int u=temp.u;
        vis[u]=1;
        for(int i=h[u];i;i=e[i].next){
            int v=e[i].v;
            if(vis[v])continue;
            else q.push(node{v,tim[v]});
        }
    }
    return 1;
}
signed main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        addedge(u,v);
        addedge(v,u);
    }
    int l=n,r=1e9,ans=0;
    //check(1e9);
    while(l<=r){
        int mid=(l+r)>>1;
        //cout<<mid<<endl;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    cout<<ans;
}

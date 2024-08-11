#include<bits/stdc++.h>
using namespace std;
const int NR=1e5+10;
#define int long long
int n,a[NR],b[NR],c[NR],maxt[NR],fa[NR][20],lg[NR],depth[NR],flag[NR];
vector<int>g[NR];
#define pb push_back

void dfs(int id,int fath){
    depth[id]=depth[fath]+1;
    fa[id][0]=fath;
    for(int i=1;i<=lg[depth[id]];i++)fa[id][i]=fa[fa[id][i-1]][i-1];
    for(int x:g[id])
        if(x!=fath)dfs(x,id);
}

int cal(int l,int r){return (r-l+1)*(l+r)/2;}
int calc(int idx,int x){
    if((!c[idx]||a[idx]/c[idx]>cal(1,x))&&c[idx]*cal(1,x)+b[idx]*x<a[idx])return -1;
    int l=1,r=x,res=0;
    while(l<=r){
        int mid=(l+r)>>1;
        if(c[idx]*cal(mid,x)+b[idx]*(x-mid+1)>=a[idx])res=mid,l=mid+1;
        else r=mid-1; 
    }
    return res;
}
struct task{
    int v,id;
    bool operator <(const task &T)const{
        return v<T.v;
    }
}t[NR];
int find(int id,int x){
    if(flag[id])return id;
    int now=id;
    for(int i=lg[depth[id]];i>=0;i--)
        if(fa[now][i]&&!flag[fa[now][i]])now=fa[now][i];
    return fa[now][0];
}
bool check(int x){
    // printf("check:%lld\n",x);
    for(int i=1;i<=n;i++){
        maxt[i]=calc(i,x);
        // printf("i:%lld %lld\n",i,maxt[i]);
        if(maxt[i]==-1)return 0;
        t[i]=(task){maxt[i],i};
    }
    sort(t+1,t+1+n);
    memset(flag,0,sizeof(flag));
    int cnt=0;
    for(int i=1,j;i<=n;i=j+1){
        j=i;
        while(j<n&&t[j+1].v==t[i].v)j++;
        for(int k=i;k<=j;k++){
            int tar=find(t[k].id,x),now=t[k].id;
            while(now!=tar)flag[now]=1,cnt++,now=fa[now][0];
        }
        if(t[i].v<cnt)return 0;
        // printf("val:%lld cnt:%lld\n",t[i].v,cnt);
    }
    return 1;
}

signed main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
    for(int i=1,x,y;i<n;i++)
        scanf("%lld%lld",&x,&y),g[x].pb(y),g[y].pb(x);
    for(int i=1;i<=n;i++)lg[i]=lg[i>>1]+1;
    dfs(1,0);
    int l=0,r=1e9,res=0;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid))res=mid,r=mid-1;
        else l=mid+1;
    }
    cout<<res<<endl;
    return 0;
}
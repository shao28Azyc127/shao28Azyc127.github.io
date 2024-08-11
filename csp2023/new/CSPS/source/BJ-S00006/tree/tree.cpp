#include<cstdio>
#include<algorithm>
#include<vector>
#define ll long long
#define lll __int128
using namespace std;
const int MAXN=1e5+10;
ll h[MAXN];int b[MAXN],c[MAXN];
int n,fa[MAXN],vis[MAXN];
struct Node{int id,tm;}lst[MAXN];
vector<int> e[MAXN];
ll read(){
    ll num=0,sign=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')sign=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')num=num*10+ch-'0',ch=getchar();
    return num*sign;
}
void dfs(int u){
    for(int k=0;k<e[u].size();k++){
        int v=e[u][k];
        if(v==fa[u]) continue;
        fa[v]=u;dfs(v);
    }
}
bool cmp(Node aa,Node bb){return aa.tm<bb.tm;}
bool check(int m){
    for(int i=1;i<=n;i++){
        lst[i].id=i;
        if(c[i]>=0){
            int l=1,r=m,mid,t=0;
            while(l<=r){
                mid=(l+r)>>1;
                if((lll)c[i]*m*(m+1)/2+(lll)b[i]*m-(lll)c[i]*mid*(mid-1)/2-(lll)b[i]*(mid-1)>=h[i]) l=mid+1,t=mid;
                else r=mid-1;
            }
            if(!t) return 0;
            lst[i].tm=t;
        }
        else{
            int tt=(c[i]<0)?((b[i]-1)/(-c[i])):0,tmpm=m;ll tmph=h[i];
            if(m>tt){
                if(h[i]<=m-tt){lst[i].tm=m-h[i]+1;continue;}
                h[i]-=(m-tt);
            }
            m=min(tt,m);
            int l=1,r=m,mid,t=0;
            while(l<=r){
                mid=(l+r)>>1;
                if((lll)c[i]*m*(m+1)/2+(lll)b[i]*m-(lll)c[i]*mid*(mid-1)/2-(lll)b[i]*(mid-1)>=h[i]) l=mid+1,t=mid;
                else r=mid-1;
            }
            if(!t) return 0;
            lst[i].tm=t;h[i]=tmph,m=tmpm;
        }
    }
    int ds=0;
    sort(lst+1,lst+n+1,cmp);
    for(int i=1;i<=n;i++) vis[i]=0;
    for(int i=1;i<=n;i++){
        int p=lst[i].id,t=lst[i].tm;
        while(!vis[p]) vis[p]=1,ds++,p=fa[p];
        if(ds>t) return 0;
    }
    return 1;
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++) h[i]=read(),b[i]=read(),c[i]=read();
    for(int i=1;i<n;i++){
        int u=read(),v=read();
        e[u].push_back(v),e[v].push_back(u);
    }
    dfs(1);vis[0]=1;
    int l=1,r=1e9,mid,ans=1e9;
    while(l<=r){
        mid=(l+r)>>1;
        if(check(mid)) r=mid-1,ans=mid;
        else l=mid+1;
    }
    printf("%d\n",ans);
    return 0;
}
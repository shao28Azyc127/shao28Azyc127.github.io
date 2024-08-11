#include<bits/stdc++.h>
using namespace std;
int n;
long long a[100005];
long long b[100005];
long long c[100005];
struct node{
    long long x;
    int id;
};
inline bool cmp(const node &x,const node &y){
    return x.x<y.x;
}
node tar[100005];
int fa[100005];
bool vis[100005];
vector<int> g[100005];
void dfsfa(int x){
    for(int i=0;i<g[x].size();i++){
        if(fa[x]==g[x][i])continue;
        fa[g[x][i]]=x;
        dfsfa(g[x][i]);
    }
    return;
}
long long l,r,ans,mid,adsfjkh;
inline long long cal(long long x,long long a,long long b,long long c){
    if(c==0)return x-(a-1)/b;
    if(c>0){
        adsfjkh=(-b)/c+1;
        if(adsfjkh>0&&(adsfjkh*c+b+b+x*c)<(a*2-1)/(x-adsfjkh+1)+1){
            a-=(adsfjkh*c+b+b+x*c)*(x-adsfjkh+1)/2;
            return adsfjkh-a;
        }
        l=max(adsfjkh,1ll),r=x,ans=-1,mid;
        while(l<=r){
            mid=(l+r)>>1;
            if((mid*c+b+b+x*c)<(a*2-1)/(x-mid+1)+1){
                r=mid-1;
            }else{
                ans=mid;
                l=mid+1;
            }
        }
        return ans;
    }
    if(c<0){
        adsfjkh=(b-1)/(-c)+1;
        if(adsfjkh>x)adsfjkh=x+1;
        if(x-adsfjkh+1>=a){
            return x-a+1;
        }
        a-=x-adsfjkh+1;
        l=1,r=adsfjkh-1,ans=-1,mid;
        while(l<=r){
            mid=(l+r)>>1;
            if((mid*c+b+b+(adsfjkh-1)*c)<(a*2-1)/(adsfjkh-mid)+1){
                r=mid-1;
            }else{
                ans=mid;
                l=mid+1;
            }
        }
        return ans;
    }
}
inline bool check(long long x){
    for(int i=1;i<=n;i++){
        tar[i].x=cal(x,a[i],b[i],c[i]);
        tar[i].id=i;
        if(tar[i].x<1)return 0;
    }
    memset(vis,0,sizeof(vis));
    sort(tar+1,tar+1+n,cmp);
    int ue=0;
    for(int i=1;i<=n;i++){
        int now=tar[i].id;
        while(now&&!vis[now]){
            vis[now]=1;
            ue++;
            now=fa[now];
        }
        if(ue>tar[i].x)return 0;
    }
    return 1;
}
int main(){
//    cout<<3*sizeof(a)/1024.0/1024.0<<endl;
//    while(1){
//        int x,a,b,c;
//        cin>>x>>a>>b>>c;
//        cout<<cal(x,a,b,c)<<endl;
//    }
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(fa,0,sizeof(fa));
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfsfa(1);
    long long l2=1,r2=1e9+5,ans2=-1,mid2=0;
    while(l2<=r2){
        mid2=(l2+r2)>>1;
        if(check(mid2)){
            ans2=mid2;
            r2=mid2-1;
        }else l2=mid2+1;
    }
    cout<<ans2<<endl;
    return 0;
}

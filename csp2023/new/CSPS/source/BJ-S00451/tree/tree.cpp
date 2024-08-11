#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,ans;
bool f1=1,f2=1,f3=1;
long long a[maxn],b[maxn],c[maxn];
bool vis[maxn];
vector<int> e[maxn];
int fa[maxn],w[maxn];
void s1(){
    int d=0;
    priority_queue<pair<long long,int>> q;
    q.push({(a[1]+b[1]-1)/b[1],1});
    while(q.size()){
        pair<long long,int> x=q.top();q.pop();
        if(x.first+d>ans) ans=x.first+d;
        for(int nxt:e[x.second]) q.push({(a[nxt]+b[nxt]-1)/b[nxt],nxt});
        d++;
    }
    cout<<ans<<endl;
}
void s2(){
    for(int i=1;i<=n;i++){
        int x=0;
        long long res=0;
        while(res<a[i]){
            ++x;
            if(b[i]+c[i]*x<=1){
                x+=a[i]-res-1;
                break;
            }
            res+=b[i]+c[i]*x;
        }
        ans=max(ans,x+i-1);
    }
    cout<<ans<<endl;
}
void so(int x,int mn){
    if(mn>ans) return;
    if(x==n+1){
        ans=min(ans,mn);
        return;
    }
    for(int nxt=1;nxt<=n;nxt++){
        if(!vis[nxt]&&vis[fa[nxt]]){
            vis[nxt]=1;
            w[x]=nxt;
            int d=x-1;
            long long res=0;
            while(res<a[nxt]){
                ++d;
                if(b[nxt]+c[nxt]*d<=1){
                    d+=a[nxt]-res-1;
                    break;
                }
                res+=b[nxt]+c[nxt]*d;
            }
            //cout<<"x:"<<x<<" nxt:"<<nxt<<" mn:"<<d+x-1<<endl;
            so(x+1,max(mn,d));
            vis[nxt]=0;
        }
    }
}
void s3(){
    ans=2e9;
    so(1,0);
    cout<<ans<<endl;
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
        if(c[i]!=0) f1=0;
    }
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        e[u].push_back(v);
        fa[v]=u;
        if(u!=v-1) f2=0;
        if(u!=1) f3=0;
    }
    fa[1]=0;
    vis[0]=1;
    if(n<=20) s3();
    else if(f1) s1();
    else if(f2) s2();
    else s3();
    return 0;
}


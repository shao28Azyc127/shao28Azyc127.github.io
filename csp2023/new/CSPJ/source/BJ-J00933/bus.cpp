#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e4+5;
int n,m,k,u,v,a,dis[maxn],vis[maxn],ans=1e18;
vector<int> vec[maxn],t[maxn];
struct node{
    int p,len;
    bool operator<(const node&d)const{
        return len>d.len;
    }
};
priority_queue<node> q;
void bfs(){
    q.push({1,0});
    while(!q.empty()){
        int x=q.top().p,len=q.top().len;
        q.pop();
        if(vis[x]) continue;
        vis[x]=1;
        for(int i=0;i<vec[x].size();i++){
            int y=vec[x][i],w=t[x][i];
            if(len<w){
                int tmp=(w-len)/k;
                if((w-len)%k) ++tmp;
                len+=tmp*k;
            }
          //  cout<<x<<" "<<y<<" "<<w<<" "<<len<<endl;
            if(len+1<dis[y]){
                dis[y]=len+1;
            //    cout<<"here "<<dis[y]<<endl;
                if(y==n&&dis[y]%k==0) ans=min(ans,dis[y]);
                q.push({y,dis[y]});
           }
        }
    }
}
signed main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=m;i++){
        scanf("%lld%lld%lld",&u,&v,&a);
        vec[u].push_back(v);
        t[u].push_back(a);
    }
    memset(dis,0x3f,sizeof(dis));
    dis[1]=0;
    bfs();
    if(ans==1e18) cout<<-1;
    else cout<<ans;
    return 0;
}

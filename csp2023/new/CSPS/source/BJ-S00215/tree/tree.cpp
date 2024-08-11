#include<bits/stdc++.h>
using namespace std;
namespace SOLUTION{
    typedef long long ll;
    typedef pair<int,int> PII;
    const int N=100010;
    int n,b[N],c[N];ll a[N];
    int head[N],tot,x,y;
    bool vis[N];
    struct Edge{int nxt,ver;}e[N<<1];
    vector<int> v[N];
    void subtask1(){
        for(int i=1;i<=n;i++)   a[i]=ceil((long double)a[i]/b[i]);
        ll ans=LLONG_MAX;
        while(clock()*1.0/CLOCKS_PER_SEC<0.85){
            priority_queue<PII> q;
            memset(vis,0,sizeof(vis));
            for(int i=1;i<=n;i++)   random_shuffle(v[i].begin(),v[i].end());
            ll cnt=0;int d=1;q.push({a[1],1});
            while(q.size()){
                int res=q.top().second;q.pop();
                if(vis[res]) continue;
                vis[res]=1,cnt=max(cnt,d+a[res]-1),d++;
                for(auto y:v[res])if(!vis[y])q.push({a[y],y});
            }ans=min(ans,cnt);
        }cout<<ans;
    }
    void subtask2(){
        ll ans=0;
        for(int i=1;i<=n;i++){
            ll nw=0;
            if(c[i]==0) nw=i+ceil(a[i]*1.0/b[i])-1;
            else{
                int d=b[i]/c[i];
                if(i>d) nw=a[i];
                else{
                    ll lst=b[i]*(i-1LL)-((i-1LL)*i*c[i]>>1);
                    ll res=max(d-i+1LL,(ll)b[i]*d-((d+1LL)*d*c[i]>>1)-lst);
                    if(res<=a[i])   nw=d+a[i]-res;
                    else{
                        int l=1,r=d;
                        while(l<r){
                            int d=l+r>>1;
                            res=(ll)b[i]*d-((d+1LL)*d*c[i]>>1)-lst;
                            if(d<a[i])  l=d+1;
                            else    r=d;
                        }nw=l;
                    }
                }
            }ans=max(ans,nw);
        }cout<<ans;
    }
    int main(){
        srand(time(0));
        cin>>n;
        for(int i=1;i<=n;i++)   cin>>a[i]>>b[i]>>c[i];
        bool flag=1;
        for(int i=1;i<n;i++){
            cin>>x>>y;
            if(x+1!=y)  flag=0;
            v[x].push_back(y),v[y].push_back(x);
        }
        if(flag)   subtask2();
        else    subtask1();
        return 0;
    }
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    return SOLUTION::main();
}
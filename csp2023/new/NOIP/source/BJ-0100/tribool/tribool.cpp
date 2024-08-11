#include<bits/stdc++.h>
#define int long long
using namespace std;
bool flag,vis[100001];
int t,n,m,x,y,ans,p1[100001],p2[100001],col[100001];
char opt;
vector<int>s;
vector<pair<int,int> >g[100001];
void dfs(int v,int c){
    if(col[v]!=2&&col[v]!=c){
        flag=1;
        return;
    }
    if(vis[v]){
        return;
    }
    vis[v]=1;
    col[v]=c;
    s.push_back(v);
    for(auto&it:g[v]){
        dfs(it.first,c*it.second);
    }
}
signed main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>t>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            p1[i]=1;
            p2[i]=i;
            vis[i]=0;
            g[i].clear();
        }
        while(m--){
            cin>>opt;
            switch(opt){
            case'+':
                cin>>x>>y;
                p1[x]=p1[y];
                p2[x]=p2[y];
                break;
            case'-':
                cin>>x>>y;
                p1[x]=-p1[y];
                if(p1[x]){
                    p2[x]=p2[y];
                }else{
                    p2[x]=-p2[y];
                }
                break;
            case'T':
                cin>>x;
                p1[x]=0;
                p2[x]=1;
                break;
            case'F':
                cin>>x;
                p1[x]=0;
                p2[x]=-1;
                break;
            case'U':
                cin>>x;
                p1[x]=0;
                p2[x]=0;
                break;
            }
        }
        for(int i=1;i<=n;i++){
            if(p1[i]){
                g[i].push_back(make_pair(p2[i],p1[i]));
                g[p2[i]].push_back(make_pair(i,p1[i]));
                col[i]=2;
            }else{
                col[i]=p2[i];
            }
        }
        for(int i=1;i<=n;i++){
            flag=0;
            s.clear();
            dfs(i,1);
            if(!flag){
                continue;
            }
            for(auto&it:s){
                if(p1[it]){
                    col[it]=2;
                }else{
                    col[it]=p2[it];
                }
                vis[it]=0;
            }
            flag=0;
            s.clear();
            dfs(i,-1);
            if(!flag){
                continue;
            }
            for(auto&it:s){
                col[it]=0;
            }
        }
        ans=0;
        for(int i=1;i<=n;i++){
            ans+=col[i]==0;
        }
        cout<<ans<<endl;
    }
}

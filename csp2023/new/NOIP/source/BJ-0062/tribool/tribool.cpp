#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int id,T;
int n,m;
pair<int,int> f[N];
vector<int> e[N],IEE[N];
int s;
bool fl[N],vis[N];
bool ch(int no,pair<int,int> nk){
    if(nk.first==2)return nk.second==2;
    if(vis[no])return 0;
    if(nk.first==0&&nk.second==no)return 1;
    vis[no]=1;
    for(int i=0;i<e[no].size();++i){
        int to=e[no][i];
        int tw=IEE[no][i];
        if(ch(to,{nk.first^1^tw,nk.second}))return 1;
    }
    return 0;
}
void dfs(int no,int nk){
    if(fl[no])return;
    s+=nk;
    fl[no]=1;
    for(int to:e[no])dfs(to,nk);
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>id>>T;
    while(T--){
        cin>>n>>m;s=0;
        for(int i=1;i<=n;++i){
            f[i]={1,i};e[i].clear();
            IEE[i].clear();
            fl[i]=0;vis[i]=0;
        }
        for(int i=1;i<=m;++i){
            char op;
            cin>>op;
            if(op=='+'){
                int x,y;
                cin>>x>>y;
                f[x]=f[y];
            }
            else if(op=='-'){
                int x,y;
                cin>>x>>y;
                if(f[y].first!=2){
                    f[x]={f[y].first^1,f[y].second};
                }
                else{
                    if(f[y].second!=2){
                        f[x]={f[y].first,f[y].second^1};
                    }
                    else f[x]=f[y];
                }
            }
            else{
                int x;
                cin>>x;
                if(op=='T')f[x]={2,1};
                else if(op=='F')f[x]={2,0};
                else f[x]={2,2};
            }
        }
        for(int i=1;i<=n;++i){
            if(f[i].first!=2){
                e[f[i].second].push_back(i);
                IEE[f[i].second].push_back(f[i].first);
            }
        }
        for(int i=1;i<=n;++i){
            if(fl[i])continue;
            if(ch(i,f[i])){
                dfs(i,1);
            }
        }cout<<s<<'\n';
    }
    return 0;
}


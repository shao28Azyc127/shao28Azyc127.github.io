#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=100005;
int T,n,m,bas[maxn],qf[maxn],col[maxn];
vector<pair<int,int> > tree[maxn];
pair<int,int> dfs(int s){
    int sz=1,res=0;
    if(bas[s]==-1)res=1;
    for(int j=0;j<tree[s].size();++j){
        int s_=tree[s][j].first;
        int tr=col[s];if(tree[s][j].second)tr=-tr;
        if(col[s_]){
            if(col[s_]!=tr)res=1;
            continue;
        }
        col[s_]=tr;
        pair<int,int> tmp=dfs(s_);
        sz+=tmp.second;
        if(tmp.first)res=1;
    }
    return make_pair(res,sz);
}
signed main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>T;cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;++i)bas[i]=i,qf[i]=col[i]=0,tree[i].clear();
        for(int i=1;i<=m;++i){
            char ch;cin>>ch;
            if(ch=='T'||ch=='F'){
                int x;cin>>x;
                bas[x]=0;
            }
            else if(ch=='U'){
                int x;cin>>x;
                bas[x]=-1;
            }
            else if(ch=='+'){
                int x,y;cin>>x>>y;
                if(bas[y]==0)bas[x]=0;
                else if(bas[y]==-1)bas[x]=-1;
                else{
                    bas[x]=bas[y];
                    qf[x]=qf[y];
                }
            }
            else if(ch=='-'){
                int x,y;cin>>x>>y;
                if(bas[y]==0)bas[x]=0;
                else if(bas[y]==-1)bas[x]=-1;
                else{
                    bas[x]=bas[y];
                    qf[x]=1-qf[y];
                }
            }
        }
        for(int i=1;i<=n;++i)if(bas[i]>0){
            tree[i].push_back(make_pair(bas[i],qf[i]));
            tree[bas[i]].push_back(make_pair(i,qf[i]));
        }
        int ans=0;
        for(int i=1;i<=n;++i)if(col[i]==0){
            col[i]=1;
            pair<int,int> tmp=dfs(i);
            if(tmp.first)ans+=tmp.second;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
vector<long long> v[100005];
bool vis[100005];
long long f[100005]={0};
void dfs(int now,int cnt){
    f[now]=cnt;
    vis[now]=1;
    for(int i=0;i<v[now].size();i++){
        if(vis[v[now][i]]==0){
            vis[v[now][i]]=1;
            dfs(v[now][i],cnt+1);
        }
    }
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    ios::sync_with_stdio(0);
    int n;cin>>n;
    long long a[100005],b[100005],c[100005];
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
        if(a[i]%b[i]==0)a[i]/=b[i];
        else a[i]=a[i]/b[i]+1;
    }


    for(int i=1;i<n;i++){
        int u,vv;cin>>u>>vv;v[u].push_back(vv);
        v[vv].push_back(u);
    }
    for(int i=2;i<=n;i++){
            bool g=0;
        for(int j=0;j<v[i].size();j++){
            if(v[i][j]==1){
                g=1;
            }
        }
        if(g)dfs(i,1);
    }
    long long maxn=-9000000000000000001;
    for(int i=1;i<=n;i++){
        maxn=max(maxn,a[i]+f[i]);
    }
    cout<<maxn<<endl;
}

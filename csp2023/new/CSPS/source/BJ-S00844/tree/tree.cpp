#include<bits/stdc++.h>
using namespace std;

int n,a[30],b[30],c[30],ans=INT_MAX,l[30];
vector<int>e[30];
map<string,int>mp;
bool f[30];
void dfs(int k){
    bool fl=1;
    for(int i=1;i<=n;i++)fl&=f[i];
    if(k>n||fl){
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(l[i]<a[i])cnt+=(a[i]-l[i]-1)/b[i]+1;
        }
        ans=min(ans,cnt);
        return;
    }
    for(int i=1;i<=n;i++)if(f[i])l[i]+=b[i];
    for(int i=1;i<=n;i++){
        if(!f[i])continue;
        for(auto u:e[i]){
            if(!f[u]){
                f[u]=1;
                l[u]+=b[u];
                dfs(k+1);
                f[u]=0;
                l[u]-=b[u];
            }
        }
    }
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    if(n<=20){
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
        }
        for(int i=1,x,y;i<n;i++){
            cin>>x>>y;
            e[x].push_back(y);
            e[y].push_back(x);
        }
        f[1]=1;
        dfs(1);
        cout<<ans;
    }
    else cout<<n;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
const int inf=0x3f3f3f3f;
int n,ans;
int a[N],b[N],c[N];
vector<int> ve[N];
void dfs(int id,int day,int sum,bool vis[N]){
    // cout<<sum<<"s"<<endl;
    // cout<<day<<"d"<<endl;
    if(day==n){
        ans=min(ans,sum);
        return;
    }
    for(auto x:ve[id]){
        if(!vis[x]){
            int tmp=day,high=0;
            while(high<a[x]){
                high+=max(b[x]+tmp*c[x],1);
                tmp++;
            }
            sum=max(sum,tmp);
            vis[x]=true;
            dfs(x,day+1,sum,vis);
            vis[x]=false;
        }
    }
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    ans=inf;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
    }
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        ve[u].push_back(v);
        ve[v].push_back(u);
    }
    bool v[N];
    memset(v,false,sizeof v);
    int tmp=0,high=0;
    while(high<a[1]){
        high+=max(b[1]+tmp*c[1],1);
        tmp++;
    }
    int sum=tmp;
    dfs(1,1,sum,v);
    printf("%d\n",ans);
    return 0;
}
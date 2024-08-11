#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long a[N];
int n,b[N],c[N],dp[N],g[N],ans;
vector<int> v[N];
bool f[N];
void add(int x,int y){
    v[x].push_back(y);
}
void dfs(int x,int y){
    int len=0;
    for(int i=0;i<v[x].size();i++){
        if(v[x][i]==y)continue;
        int to=v[x][i];
        dfs(to,x);
        g[++len]=dp[to];
    }
    int res;
    if(a[x]%b[x]==0)res=a[x]/b[x];
    else res=a[x]/b[x]+1;
    sort(g+1,g+len+1);
    for(int i=len;i>=1;i--){
        res=max(res,g[i]+(len-i));
    }
    dp[x]=res;
}
int calc(int x,int y){
    int l=x,r=1e9;
    while(l<=r){
        long long mid=(l+r)>>1;
        long long t=mid*(b[x])+mid*(mid+1)/2*c[x]-(y-1)*(b[x])+y*(y-1)/2*c[x];
        if(t>=a[x])r=mid-1;
        else l=mid+1;
    }
    return l;
}
void df(int x,int y){
    if(x==n){
        ans=min(ans,y);
        return;
    }
    for(int i=1;i<=n;i++){
        if(f[i]){
            for(int j=0;j<v[i].size();j++){
                if(!f[v[i][j]]){
                    f[v[i][j]]=1;
                    df(x+1,max(y,calc(v[i][j],x+1)));
                    f[v[i][j]]=0;
                }
            }
        }
    }
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    bool o=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld%d%d",&a[i],&b[i],&c[i]);
        if(c[i]>0)o=1;
    }

    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y),add(y,x);
    }
    if(!o){
        dfs(1,0);
        cout<<dp[1];
    }else if(n<=20){
        f[1]=1;
        cout<<calc(1,1);
        df(1,calc(1,1));
    }

    return 0;
}


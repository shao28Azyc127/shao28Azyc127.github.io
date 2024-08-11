#include<bits/stdc++.h>
using namespace std;
long long dp[100010],mind[100010],a[100010],c[100010],ans=1e18;
int n,b[100010];
vector<int>t[100010];
vector<int>k[100010];
bool ct=true,vis[100010]={},ok=false;
void df(int now,int cnt){
    cnt++;
    if(cnt==n){
        ok=true;
        return;
    }
    for(int i=0;i<t[now].size();i++){
        if(!vis[t[now][i]]){
            vis[t[now][i]]=true;;
            k[now].push_back(t[now][i]);
            df(t[now][i],cnt);
            if(ok==true)return;
        }
    }
}
void dfs(int now,int day,long long cnt){
    if(now==1)cnt=mind[1];
    if(day==n){
        ans=min(ans,cnt);
        return;
    }
    for(int i=0;i<k[now].size();i++){
        long long f=cnt;
        day++;
        cnt=max(cnt,mind[k[now][i]]+day-2);
        dfs(k[now][i],day,cnt);
        cnt=f;
    }
}
int main(){
    vis[1]=true;
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld%d%lld",&a[i],&b[i],&c[i]);
        if(c[i]!=0)ct=false;
    }
    for(int i=1;i<=n-1;i++){
        int u,v;scanf("%d%d",&u,&v);
        t[u].push_back(v);t[v].push_back(u);
    }
    df(1,0);
    if(ct==true){
        for(int i=1;i<=n;i++){
            mind[i]=(a[i]-1)/(long long)max(b[i],1)+1;
        }
        dfs(1,1,0);
        printf("%lld",ans);
    }
    return 0;
}

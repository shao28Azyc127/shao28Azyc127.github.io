#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=10;
int n,a[MAXN][MAXN],cg[MAXN],ans;
bool check(){
    for(int i=1;i<=n;i++){
        int fl=0;
        for(int j=1;j<=5;j++){
            if(a[i][j]!=cg[j]){
                if(fl)if((a[i][j-1]-cg[j-1]+10)%10!=(a[i][j]-cg[j]+10)%10)return 0;
                fl++;
                if(fl>2)return 0;
            }
        }
        if(!fl)return 0;
    }
    return 1;
}
bool vis[400010];
void dfs(int now,int sum){
    if(now==6){
        if(vis[sum])return;
        vis[sum]=1;
        if(check())ans++;
        return;
    }
    for(int i=0;i<=9;i++){
        cg[now]=i;
        dfs(now+1,sum*10+i);
        cg[now]=0;
    }
}
signed main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            scanf("%lld",&a[i][j]);
        }
    }
    dfs(1,0);
    printf("%lld",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//zycakioi!!
//lylakioi!!

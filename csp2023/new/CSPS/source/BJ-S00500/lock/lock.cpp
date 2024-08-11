#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[10][10],i,j,ans,b[10],cnt;
ll vis[10][10][10][10][10];
ll l(ll x,ll y){return (x-y+10)%10;}
ll r(ll x,ll y){return (x+y)%10;}
bool chk(){
    ll x;
    for(x=0;x<=9;x++){
        vis[x][b[2]][b[3]][b[4]][b[5]]=cnt;
    }
    for(x=0;x<=9;x++){
        vis[b[1]][x][b[3]][b[4]][b[5]]=cnt;
    }
    for(x=0;x<=9;x++){
        vis[b[1]][b[2]][x][b[4]][b[5]]=cnt;
    }
    for(x=0;x<=9;x++){
        vis[b[1]][b[2]][b[3]][x][b[5]]=cnt;
    }
    for(x=0;x<=9;x++){
        vis[b[1]][b[2]][b[3]][b[4]][x]=cnt;
    }
    for(x=0;x<=9;x++){
        vis[l(b[1],x)][l(b[2],x)][b[3]][b[4]][b[5]]=cnt;
        vis[r(b[1],x)][r(b[2],x)][b[3]][b[4]][b[5]]=cnt;
    }
    for(x=0;x<=9;x++){
        vis[b[1]][l(b[2],x)][l(b[3],x)][b[4]][b[5]]=cnt;
        vis[b[1]][r(b[2],x)][r(b[3],x)][b[4]][b[5]]=cnt;
    }
    for(x=0;x<=9;x++){
        vis[b[1]][b[2]][l(b[3],x)][l(b[4],x)][b[5]]=cnt;
        vis[b[1]][b[2]][r(b[3],x)][r(b[4],x)][b[5]]=cnt;
    }
    for(x=0;x<=9;x++){
        vis[b[1]][b[2]][b[3]][l(b[4],x)][l(b[5],x)]=cnt;
        vis[b[1]][b[2]][b[3]][r(b[4],x)][r(b[5],x)]=cnt;
    }
    for(x=1;x<=n;x++){
        if(b[1]==a[x][1]&&b[2]==a[x][2]&&b[3]==a[x][3]&&b[4]==a[x][4]&&b[5]==a[x][5]) return false;
    }
    for(x=1;x<=n;x++){
        if(vis[a[x][1]][a[x][2]][a[x][3]][a[x][4]][a[x][5]]!=cnt) return false;
    }
    return true;
}
void dfs(ll cur){
    if(cur>5){
        cnt++;
        if(chk()) ans++;
        return;
    }
    ll x;
    for(x=0;x<=9;x++){
        b[cur]=x;
        dfs(cur+1);
    }
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=5;j++){
            scanf("%lld",&a[i][j]);
        }
    }
    dfs(1);
    printf("%lld",ans);
    return 0;
}

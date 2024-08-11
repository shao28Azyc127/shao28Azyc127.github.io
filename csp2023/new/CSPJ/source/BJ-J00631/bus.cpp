#include <bits/stdc++.h>
using namespace std;
int n,m,k,lasttime;
int mapn[10005][10005];
bool vis[10005];
int dfs(int x,int nowtime){
    if(x==n){
        if(nowtime%k==0) return nowtime;
        else return 15038505;
    }
    else{
    for(int i=1;i<=n;i++){
        if(mapn[x][i]==-1) continue;
        if(vis[i]==true) continue;
        if(nowtime<mapn[x][i]) continue;
        vis[i]=true;
        dfs(i,nowtime+1);
        vis[i]=false;
    }
    }


}

void coutut(){
    for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                cout<<mapn[i][j]<<" ";

            }
            cout<<endl;
        }

return ;
}

int main(){

freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);

    memset(mapn,-1,sizeof(mapn));
    memset(vis,false,sizeof(vis));
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        int s,e,last;
        cin>>s>>e>>last;
        mapn[s][e]=last;
        lasttime=max(last,lasttime);
    }



    if(n<=10){
        int minn=15055606;
    for(int i=1;i<=lasttime;i++){
        int st=k*i;
        vis[1]=true;
        memset(vis,false,sizeof(vis));
        minn=min(minn,dfs(1,st));
    }
    cout<<minn+1<<endl;
    }
    return 0;
}


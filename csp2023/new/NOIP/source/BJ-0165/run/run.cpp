#include<bits/stdc++.h>
using namespace std;
struct IO{
    IO(){
        freopen("run.in","r",stdin);
        freopen("run.out","w",stdout);
    }
    ~IO(){
        fclose(stdin);
        fclose(stdout);
    }
}io;
const int N=1e3+7;
int c,t;
int n,m,k,d;
int f[N][N];
int sts[N][N];
struct bonus{
    int x,y,v;
}duck[N];
int ans=0;
void dfs(int day,int cont,int curans){
    if(cont==k+1){
        return;
    }
    curans+=sts[day][cont];
    if(day==n){
        ans=max(ans,curans);
        return;
    }
    dfs(day+1,cont+1,curans-d);
    dfs(day+1,0,curans);
}
int main(){
    cin>>c>>t;
    while(t--){
        ans=0;
        memset(sts,0,sizeof(sts));
        cin>>n>>m>>k>>d;
        for(int i=1;i<=m;i++){
            cin>>duck[i].x>>duck[i].y>>duck[i].v;
            for(int j=duck[i].y;j<=k;j++){
                sts[duck[i].x][j]=max(sts[duck[i].x][j],duck[i].v);
            }
        }
        dfs(0,0,0);
        cout<<ans<<'\n';
    }
    return 0;
}

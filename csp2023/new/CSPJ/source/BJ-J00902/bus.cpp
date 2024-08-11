#include <iostream>
using namespace std;
int sq[10030][10030];
bool sqb[10030][10030];
int vis[10030];
int r=0;
void dfs(int time,int now,int n,int k){
    if(r)return;
    if(now==n&&time%k==0){
        cout<<time<<endl;
        r=1;
        return;
    }
    vis[now]++;
    for(int i=1;i<=n;i++){
        if(sqb[now][i]&&sq[now][i]<=time&&vis[n]<=1000){
            dfs(time+1,i,n,k);
        }
    }
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        sqb[x][y]=1;
        sq[x][y]=z;
    }
    for(int k1=0;k1<10000*k;k1+=k){
        if(r)break;
        dfs(k1,1,n,k);
    }
    if(!r)cout<<-1<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
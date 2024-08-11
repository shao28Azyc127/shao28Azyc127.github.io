#include<iostream>
#include<cstdio>
using namespace std;
int n,m,k,mn=1e9;
int a[10010][10010];
void dfs(int x,int t){
    if(x==n){
        if(t%k==0)mn=min(mn,t);
    }
    for(int i=1;i<=n;i++){
        if(a[x][i]>=0&&a[x][i]<=t){
            dfs(i,t+1);
        }
    }
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[i][j]=-1;
        }
    }
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        a[x][y]=z;
    }
    for(int i=0;i<=1e6;i+=k){
        dfs(1,i);
    }
    if(mn<1e9)cout<<mn;
    else cout<<-1;
    return 0;
}

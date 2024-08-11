#include <bits/stdc++.h>
using namespace std;
int n,m,k,ans;
int edge[20005][20005]={};
int dfs(int t,int x){
   if(x==n&&t%k==0){
        return t;
   }
   else if(x==n)
        return -1;
   for(int i=0;i<m;i++){
        if(edge[x][i]*-1+1>=0){
            if(t>=edge[x][i]*-1-1){
                dfs(t+1,i);
            }
            else
                return -1;
        }
   }
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    int j=0;
    for(int i=1;i<=m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        edge[a][b]=c;
        j=max(j,c);
    }
    for(int i=0;i<=k;i++){
        int b;
 //       b=dfs(i,0);
        if(b>0)
            ans=min(ans,b);
    }
    j+=k-j%k;

    cout<<j;
    return 0;
}

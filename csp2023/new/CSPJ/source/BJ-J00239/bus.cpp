#include<bits/stdc++.h>
#define INF 99999999
using namespace std;
bool book[20005],f2[10005][10005];
int f[10005][10005];
int n,m,k1;
long long ans=INF;
void bfs(int k,long long t){
    //cout<<k<<" ";
    if(k==n){
      if(t%k1==0)
        ans=min(ans,t);
        return ;}
    for(int i=1;i<=n;i++){
        if(!book[i] and f2[k][i] and f[k][i]<=t){
        bfs(i,t+1);
        }
    }

}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k1;
    for(int i=1;i<=m;i++){
        int a1,a2,a3;
        scanf("%d%d%d",&a1,&a2,&a3);
        f[a1][a2]=a3;
        f2[a1][a2]=1;
    }
    bfs(1,k1);
    if(ans==INF) cout<<-1;
    else cout<<ans;



    return 0;
}
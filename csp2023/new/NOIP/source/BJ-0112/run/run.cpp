#include<cstring>
#include<iostream>
using namespace std;

#define ll long long
const int maxn=1e3+10;
const ll inf=1e18;
int n,m,k,c,t;
ll dp[maxn][maxn],gift[maxn][maxn],ans,d;

int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);

    cin>>c>>t;
    while(t--){
        cin>>n>>m>>k>>d;
        ans=0;
        if(c==17||c==18){
            for(int i=1;i<=m;i++){
                int u,v,w; cin>>u>>v>>w;
                if(v<=k&&v<=u&&w>d*v)ans+=w-d*v;
            }
            cout<<ans<<endl;
        }else{
            memset(gift,0,sizeof(gift));
            for(int i=1;i<=m;i++){
                int u,v,w; cin>>u>>v>>w;
                for(int j=v;j<=min(k,u);j++)gift[u][j]+=w;
            }
            for(int i=0;i<=n+1;i++)for(int j=1;j<=k;j++)dp[i][j]=-inf;
            for(int i=0;i<=n+1;i++)dp[i][0]=0;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=k;j++){
                    dp[i][j]=dp[i-1][j-1]-d+gift[i][j];
                    dp[i+1][0]=max(dp[i+1][0],dp[i][j]);
                }
                dp[i+1][0]=max(dp[i+1][0],dp[i][0]);
            }
            for(int i=1;i<=n;i++)dp[n+1][0]=max(dp[n+1][0],dp[i][0]);
            cout<<dp[n+1][0]<<endl;
        }
    }
}
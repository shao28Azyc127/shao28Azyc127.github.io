#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int maxm=1e5+10;
const ll INF=1e18;

ifstream fin("run.in");
ofstream fout("run.out");

int c,t;
int n,m,k,d;
ll dp[2][maxn];
int x[maxm],y[maxm],v[maxm];
vector <int> ch[maxn];

int main(){
    ios::sync_with_stdio(0);
    fin>>c>>t;
    while(t--){
        fin>>n>>m>>k>>d;
        for(int i=1;i<=n;i++)
            ch[i].clear();
        for(int i=1;i<=m;i++){
            fin>>x[i]>>y[i]>>v[i];
            ch[x[i]].push_back(i);
        }
        for(int j=1;j<=k;j++)
            dp[0][j]=dp[1][j]=-INF;
        dp[0][0]=0;
        for(int i=1;i<=n;i++){
            dp[i&1][0]=-INF;
            for(int j=0;j<=k;j++)
                dp[i&1][0]=max(dp[i&1][0],dp[(i&1)^1][j]);
            for(int j=1;j<=min(k,i);j++){
                dp[i&1][j]=dp[(i&1)^1][j-1]-d;
                for(int t:ch[i]){
                    if(y[t]<=j)
                        dp[i&1][j]+=v[t];
                }
            }
            // for(int j=0;j<=k;j++)
                // fout<<dp[i&1][j]<<' ';
            // fout<<endl;
        }
        ll ans=0;
        for(int j=0;j<=k;j++){
            ans=max(dp[n&1][j],ans);
        }
        fout<<ans<<endl;
    }

    return 0;
}
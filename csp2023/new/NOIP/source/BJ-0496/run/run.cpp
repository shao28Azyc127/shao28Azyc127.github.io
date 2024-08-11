#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t; int n,m,k,d;
int dp[1005][1005];
int maxdp[1005];
struct gift{
	int y; int v;
};

signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m>>k>>d;
		vector <gift> g[100000+5];
		
		for(int i=1;i<=m;i++){
			int x,y,v; cin>>x>>y>>v;
			g[x].push_back((gift){y,v});
		}
//		cout<<g[1].size();
		if(	k>=n*d ){
			cout<<'!';
			int ans=0;
			for(int i=1;i<=n;i++){
				ans-=d;
				for(int j=0;j < g[i].size();j++){
					if(g[i][j].y<=i){
						ans+=g[i][j].v;
					}
				}
			}
			cout<<ans<<endl;
			continue;
		}
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
				dp[i][j]=0;
			}
		}
		for(int i=0;i<=n;i++){
			maxdp[i]=0;
		}
		dp[0][0]=0; maxdp[0]=0;
		for(int i=1;i<=n;i++){
			maxdp[i]=dp[i][0]=maxdp[i-1];
			for(int j=1;j<=k;j++){
				dp[i][j]=dp[i-1][j-1]-d;
				for(int x=0;x<g[i].size();x++){
					if(j>=g[i][x].y){
						dp[i][j]+=g[i][x].v;
					}
				}
				maxdp[i]=max(maxdp[i],dp[i][j]);
			}
		}
		cout<<maxdp[n]<<endl;
	}
	return 0;
}

#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1005;
LL n,m,k,d;
LL dp[1005][1005];
vector<pair<int,int>> y[1005];
void solve1(){
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++) y[i].clear();
	for(int i=1;i<=m;i++){
		int x,a,b;
		cin>>x>>a>>b;
		y[x].push_back({a,b});
	}
	long long maxdp=0;
	for(int i=1;i<=n;i++){
		dp[i][0]=maxdp;
		for(int j=1;j<=k;j++){
			int l=i-j+1,r=i;
			if(l<1) continue;
			dp[i][j]=dp[i-1][j-1]-d;
			for(auto yy:y[i]){
				dp[i][j]+=(j>=yy.first?yy.second:0);
			}
			maxdp=max(maxdp,dp[i][j]);
		}
	}
	cout<<maxdp<<endl;
}
void solve2(){
	LL ans=0;
	for(int i=1;i<=m;i++){
		LL x,a,b;
		cin>>x>>a>>b;
		if(b>a*d&&a<=k&&x-a+1>=1){
			ans+=b-a*d;
		}
	}
	cout<<ans<<endl;
}	
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>m>>k>>d;
		if(c<=8){
			solve1();
		}else if(c==15||c==16){
			solve2();
		}
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+5,M=1e5+5;
ll n,m,k,d,ans;
struct node{
	ll x,y,v;
}c[M];
bool cmp(node a,node b){
	if(a.x==b.x)return a.y<b.y;
	return a.x<b.x;
}
bool cmp1(node a,node b){
	return a.x<b.x;
}
ll dp[N][N];

int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int C,T;
	cin>>C>>T;
	while(T--){
		cin>>n>>m>>k>>d;
		for(int i=1;i<=m;i++){
			ll x,y;
			cin>>x>>y>>c[i].v;
			c[i].x=x,c[i].y=y;
		}
		memset(dp,-0x3f,sizeof(dp));ans=0;
		for(int i=0;i<=n;i++)dp[i][0]=0;
		sort(c+1,c+m+1,cmp);
		for(int i=1;i<=n;i++){
			for(int j=0;j<=min((ll)(i-1),k);j++){
				dp[i][0]=max(dp[i][0],dp[i-1][j]);
				ans=max(ans,dp[i][0]);
			}
			node t={i,0};
			ll val=0,p=lower_bound(c+1,c+m+1,t,cmp1)-c;
			if(c[p].x==i){
				for(int j=1;j<=min((ll)i,k);j++){
					while(c[p].x==i&&p<=m&&j>=c[p].y)val+=c[p].v,p++;
					dp[i][j]=dp[i-1][j-1]-d+val;
					ans=max(ans,dp[i][j]);
				}
			}
			else{
				for(int j=1;j<=min((ll)i,k);j++){
					dp[i][j]=dp[i-1][j-1]-d;
					ans=max(ans,dp[i][j]);
				}
			}
			
		}
		cout<<ans<<endl;
	}
	return 0;
}

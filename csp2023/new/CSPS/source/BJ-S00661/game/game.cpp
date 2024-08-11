#include<bits/stdc++.h>
using namespace std;
#define int long long
int n; char a[2000000+5];
bool dp[10000][10000];
bool vis[10000][10000];
bool dfs(int l,int r){
	if(vis[l][r]){
		return dp[l][r];
	}
	if(l==r)return 0;
	if(l==r+1) return 1;
	if(l==r-1){
		if(a[l]==a[r]){
			dp[l][r]=1; vis[l][r]=1; return dp[l][r];
		}
	}
	if(a[l]==a[r]){
		dp[l][r]|=(dfs(l+1,r-1));
		vis[l][r]=1;
		return dp[l][r];
	}
	for(int k=l;k<=r-1;k++){
		dp[l][r]|=(dfs(l,k)&dfs(k+1,r));
	}
	vis[l][r]=1;
	return dp[l][r];
	
}
signed main(){
	freopen("game.in","r",stdin);
	
	freopen("game.out","w",stdout);
	cin>>n;
	 for(int i=1;i<=n;i++) cin>>a[i];
//	cout<<dfs(1,n);
	int ans=0;
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			ans+=dfs(l,r);
		}
	}
	cout<<ans;
	return 0;
}
//dp[l][r]=dp[l][k]+dp[k+1][r];

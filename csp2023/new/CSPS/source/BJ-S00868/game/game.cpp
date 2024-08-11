#include<bits/stdc++.h>
using namespace std;
string s;
int ans=0,n,dp[9005][9005],vis[9005][9005];
bool solve(int l,int r){
	if(vis[l][r])return dp[l][r];
	if(r-1==l)dp[l][r]=(s[l]==s[r]);
	else if(l==r)dp[l][r]=0;
	else if((l-r+1)&1)dp[l][r]=0;
	else if(s[l]==s[r])dp[l][r]=solve(l+1,r-1);
	else{
		for(int i=l+1;i<r;i+=2){
			if(solve(l,i)&&solve(i+1,r))dp[l][r]=1;
		}
	}
	vis[l][r]=1;
	return dp[l][r];
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;
	cin>>s;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(vis[i][j])ans+=dp[i][j];
			else solve(i,j);
		}
	}
	cout<<ans;
}
//kkkbaoyou,dpbiegua
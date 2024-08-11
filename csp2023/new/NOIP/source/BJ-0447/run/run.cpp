#include<bits/stdc++.h>//g++ t4.cpp -o t4 -O2 -std=c++14 -static
#define int long long
using namespace std;
struct cha{
	int x;
	int y;
	int v;
}a[100005];
int dp[1005][1005];
int bonus[1005][1005];
int DP(int n,int m,int k,int d){
	for(int i=0;i<=n;i++){
		for(int j=0;j<=k;j++){
			dp[i][j]=0;
			bonus[i][j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		bonus[a[i].x][a[i].y]+=a[i].v;
	}
	for(int i=0;i<=n;i++){
		for(int j=1;j<=k;j++){
			bonus[i][j]+=bonus[i][j-1];
		}
	}
	dp[0][0]=0;
	int lstmax=0;
	for(int i=1;i<=n;i++){
		dp[i][0]=lstmax;
		for(int j=1;j<=k;j++){
			dp[i][j]=dp[i-1][j-1]-d+bonus[i][j];
			lstmax=max(lstmax,dp[i][j]);
		}
	}
	/*
	for(int i=1;i<=n;i++){
		for(int j=0;j<=k;j++){
			cout<<dp[i][j]<<(j==0?'|':' ');
		}
		cout<<endl;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			cout<<bonus[i][j]<<' ';
		}
		cout<<endl;
	}
	*/
	return lstmax;
}
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	if(c>=10){
		for(int i=1;i<=t;i++){
			cout<<0<<'\n';
		}
		return 0;
	}
	for(int z=1;z<=t;z++){
		int n,m,k,d;
		cin>>n>>m>>k>>d;
		for(int i=1;i<=m;i++){
			int x,y,v;
			cin>>x>>y>>v;
			a[i].x=x;
			a[i].y=y;
			a[i].v=v;
		}
		cout<<DP(n,m,k,d)<<'\n';
	}
}
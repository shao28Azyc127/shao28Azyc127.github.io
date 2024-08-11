#include<bits/stdc++.h>
using namespace std;
int dp[100005],w[100005],v[100005];
int main(){
	freopen("road.in","r",stdout);
	freopen("road.out","w",stdout);
	int n,r;
	cin>>n>>r;
	for(int i=1;i<n;i++) cin>>w[i];
	for(int i=1;i<n;i++) cin>>v[i];
	int minv=1e9;
	for(int i=1;i<n;i++) minv=min(minv,v[i]);
	if(minv==v[1]){
		long long sum=0;
		for(int i=1;i<n;i++) sum+=w[i];
		cout<<sum*v[1];
		return 0;
	}
	int x=v[1],ans=0;
	double oil=0;
	for(int i=1;i<n;i++){
		if(v[i]<x) x=v[i];
		if(oil){
			int needoil=ceil(w[i]/(r+0.0)-oil);
			ans+=needoil*x;
			oil=ceil(w[i]/(r+0.0)-oil)-(w[i]/(r+0.0)-oil);
		}else{
			ans+=ceil(w[i]/(r+0.0))*x;
			oil=ceil(w[i]/(r+0.0))-(w[i]/(r+0.0));
		}
	}
	cout<<ans;
	return 0;
}
/*
5 4
10 10 10 10
9 8 9 6 5
*/
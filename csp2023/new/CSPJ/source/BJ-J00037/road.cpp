#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long long n,d,dp[100005];
int v[100005],a[100005],f[100005];
double y[100005];
//dp[i]:来到第i站的最小花费
//从第i站到第j站，最少花费ceil(1.0*(f[j]-f[i])/d)*a[i];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> d;
	for(int i = 1;i < n;i++){
		cin >> v[i];
		f[i+1] = f[i]+v[i];
	}
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 2;i <= n;i++){
		dp[i] = 2e9;
		for(int j = 1;j < i;j++){
			long long Use;
			Use = (ceil(1.0*(f[i]-f[j])/d-y[j]))*a[j];
			//cout << Use << ' ';
			if(dp[i] >= dp[j]+Use){
				dp[i] = dp[j]+Use;	
				y[i] = max(y[i],ceil(1.0*(f[i]-f[j])/d-y[j])-1.0*(f[i]-f[j])/d-y[j]);
			}
		}
		//cout << dp[i] << " ";
	}
	cout << dp[n];
}
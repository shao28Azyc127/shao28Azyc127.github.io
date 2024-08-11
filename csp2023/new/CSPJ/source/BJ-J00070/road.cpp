#include <iostream>
#include <cstdio>
using namespace std;
const int N=1e5+7;
typedef long long ll;
int n;ll d;
ll len[N];//pre为本站到起点的距离
ll v[N], mv[N], dp[N];
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin>>n>>d;
	for(int i=1;i<n;i++)
		cin>>len[i];
	v[0]=1e17;
	for(int i=1;i<=n;i++){
		cin>>v[i];
		mv[i]=(v[mv[i-1]]<=v[i]?mv[i-1]:i);
	}
	ll sum=0;
	for(int i=1;i<n;i++){
		if(v[mv[i-1]]<=v[i]){//用以前的
			dp[i]=dp[i-1]+len[i]/d*v[mv[i-1]];
			if(len[i]%d>0 && (sum%d+len[i]%d>d || sum%d==0)){
				dp[i]+=v[mv[i-1]];
			}
		}else{
			dp[i]=dp[i-1]+len[i]/d*v[i];
			if(len[i]%d>0 && (sum%d+len[i]%d>d || sum%d==0)){
				dp[i]+=v[i];
			}
		}
		sum+=len[i];
	}
	cout<<dp[n-1]<<endl;
	return 0;
}
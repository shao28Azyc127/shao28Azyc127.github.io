#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
long long n,d,ans=9999999;
long long v[100005],a[100005];
void dfs(long long s,long long y,long long sum){
	if(s==n){
		ans=min(ans,sum);
		return;
	}
	if(sum>=ans)return;
	if(y*d>=v[s]-v[s-1])
		dfs(s+1,y-(v[s]-v[s-1])/d,sum);
	for(int i=(v[n-1]-v[s])/d;i>=(v[s]-v[s-1])/d;i--)
		dfs(s+1,y+i-(v[s]-v[s-1])/d,sum+a[s]*i);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	for(int i=1;i<n;i++){
		scanf("%lld",&v[i]);
		v[i]+=v[i-1];
	}
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	dfs(1,0,0);
	cout<<ans;
	return 0;
}

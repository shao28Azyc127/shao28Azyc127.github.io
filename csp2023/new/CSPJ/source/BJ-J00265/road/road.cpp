#include<bits/stdc++.h>
using namespace std;
int n,d;
int a[10005];
int v[10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	for(int i=1;i<=n-1;i++) cin>>v[i];
	for(int i=1;i<=n;i++) cin>>a[i];
	int ans=0;
	int k=0;
	for(int i=1;i<=n-1;i++){
		int minx=1e9;
		for(int j=1;j<=i;j++){
			minx=min(a[j],minx);
		}
		int sum=0;
		for(int j=1;j<=i;j++){
			sum+=v[i];
		}
		sum-=k;
		if((sum/d)*d<sum)
		k+=(sum/d+1)*d;
		else k+=(sum/d)*d;
		if((sum/d)*d<sum)
		ans+=(sum/d+1)*minx;
		else ans+=(sum/d)*minx;
	}
	cout<<ans;
	return 0;
}
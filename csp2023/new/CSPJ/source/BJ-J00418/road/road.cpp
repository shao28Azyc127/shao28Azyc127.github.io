#include <bits/stdc++.h>
using namespace std;
int n,minn;
long long ans;
double sum;
int v[100005],w[100005],t,g,d;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	for(int i=1;i<=n-1;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	minn=v[1];
	for(int i=1;i<=n-1;i++){
		if(v[i]<minn) minn=v[i];
		t=sum*d;
		if((w[i]-t)%d==0) g=(w[i]-t)/d;
		else g=(w[i]-t)/d+1;
		sum+=g-(w[i]*1.0/d);
		ans+=g*minn;
	}
	cout<<ans;
	return 0;
}

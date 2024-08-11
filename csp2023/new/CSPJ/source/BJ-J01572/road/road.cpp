#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,d;
	cin>>n>>d;
	
	int v[100005];
	int a[100005];
	int tmp=0;
	for(int i=1;i<n;i++){
		cin>>v[i];
		tmp+=v[i];
	}
	int minn=1e9+7;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		minn=min(a[i],minn);
	}
	int ans;
	if(minn==a[1]){
		ans=tmp/d;
		if(tmp%d!=0){
			ans++;
			cout<<ans*a[1];
			return 0;
		}
		else{
			cout<<ans*a[1];
			return 0;
		}
	}
	else{
		int f[100005];
		for(int i=1;i<n;i++){
			f[i]=f[i-1]+min(v[i]/d*a[i]+v[i+1]/d*a[i],v[i]/d*a[i]+v[i+1]/d*a[i+1]);
		}
		cout<<f[n-1];
	}
	return 0;
}

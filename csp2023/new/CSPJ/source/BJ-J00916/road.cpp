#include<bits/stdc++.h>
using namespace std;

long long n,m,c,w,ans,v[100100],a[100100];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<n;++i){
		cin>>v[i];
	}
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	c=a[1];
	for(int i=1;i<n;++i){
		c=min(c,a[i]);
		w=(v[i]+v[i-1])/m;
		v[i]=(v[i]+v[i-1])%m;
		if(v[i]>0){
			v[i]-=m;
			++w;
		}
		ans+=c*w;
	}
	cout<<ans;
	
	
	return 0;
}

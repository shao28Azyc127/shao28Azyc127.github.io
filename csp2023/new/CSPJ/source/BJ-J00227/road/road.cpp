#include<bits/stdc++.h>
using namespace std;
long long n,d,v[100010],a[100010],s[100010],ans=0,cnt=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	for(int i=1;i<n;i++){
		cin>>v[i];
	}
	s[0]=2e9;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=min(s[i-1],a[i]);
	}
	for(int i=1;i<n;i++){
		long long vv=v[i]-cnt;
		long long x=vv/d;
		if(vv%d!=0) x++;
		ans=ans+x*s[i];
		cnt=x*d-vv;
	}
	cout<<ans;
	return 0;
}

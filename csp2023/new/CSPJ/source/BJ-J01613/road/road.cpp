#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long v[100005];
long long w[100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<n;i++)cin>>v[i];
	for(int i=1;i<=n;i++)cin>>w[i];
	long long ans=0,x=w[1],s=0;
	for(int i=1;i<n;i++){
		v[i]-=s;
		if(v[i]<=0)s=abs(v[i]);
		else{
			int q=(v[i]+k-1)/k;
			s=q*k-v[i];
			ans+=x*q;
		}
		x=min(x,w[i+1]);
		//cout<<ans<<' ';
	}
	cout<<ans;
	return 0;
}

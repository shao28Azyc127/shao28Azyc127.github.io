#include<iostream>
#include<cmath>
using namespace std;
#define int long long
int v[100005],d[100005];
int s[100005];

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,r;
	cin>>n>>r;
	s[1]=0;
	for(int i=2;i<=n;i++){
		cin>>v[i];
		s[i]=s[i-1]+v[i];
	}
	for(int i=1;i<=n;i++) cin>>d[i];
	int cur=1,ans=0,less=0;
	for(int i=2;i<=n;i++){
		if(d[i]<d[cur]){
			ans+=(int)ceil((s[i]-s[cur]-less)*1.0/r)*d[cur];
			less=(int)ceil((s[i]-s[cur]-less)*1.0/r)*r-(s[i]-s[cur]-less);
			cur=i;
		}
	}
	cout<<ans+(int)ceil((s[n]-s[cur]-less)*1.0/r)*d[cur];
	return 0;
}	

#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5;
ll a[N],p[N],c[N],n,b[N];
ll find(ll st,ll x){
	ll l,r,mid,ans=-1;
	l=st;
	r=n;
	while(l<=r){
		mid=(l+r)/2;
		if(p[mid]<=x){
			r=mid-1;
			ans=mid;
		}
		else l=mid+1;
	}
	if(ans==-1) ans=n;
	return ans;
}
int main(){
	ll i,d,Min=0x3f3f3f3f,s=0,ans=0,dis;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n-1;i++){
		cin>>a[i];
		s+=a[i];
	}
	for(i=1;i<=n;i++){
		cin>>p[i];
		Min=min(Min,p[i]);
	}
	if(Min==p[1]){
		if(s%d!=0) cout<<(s/d+1)*Min;
		else cout<<s/d*Min;
		return 0;
	}
	b[1]=1;
	for(i=2;i<=n;i++){
		b[i]=b[i-1]+a[i-1];
	}
	c[1]=1;
	for(i=1;i<=n;i++){
		c[i]=find(i+1,p[i]);
	}
	i=1;
	dis=0;
	while(i<n){
		if((b[c[i]]-b[i]-dis)%d!=0){
			ans+=((b[c[i]]-b[i]-dis)/d+1)*p[i];
			dis+=((b[c[i]]-b[i]-dis)/d+1)*d;
		}
		else{
			ans+=(b[c[i]]-b[i]-dis)/d*p[i];
			dis+=(b[c[i]]-b[i]-dis);
		}
		dis-=b[c[i]]-b[i];
		i=c[i];
		//cout<<ans<<" ";
	}
	cout<<ans;
	return 0;
}
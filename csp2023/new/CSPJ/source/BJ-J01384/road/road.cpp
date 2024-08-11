#include <bits/stdc++.h>
#define ll long long
#define N 100010
using namespace std;
ll n,d;
ll k,i=1,ltemp=0,ans=0,L=0;
ll v[N],s[N],a[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld",&n,&d);
	s[1]=0;
	for(ll i=2;i<=n;i++){
		cin>>v[i];
		s[i]=s[i-1]+v[i];
	}
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(k=2;k<=n;k++){
		if(a[k]<a[i]){
			ltemp=(s[k]-s[i])/d;
			if((s[k]-s[i])%d==0){
				ltemp--;
			}
			L+=ltemp;
			if(L*d<s[k]){
				L++;
				ltemp++;
			}
			ans+=ltemp*a[i];
			i=k;
		}
		if(k==n){
			ltemp=(s[k]-s[i])/d;
			if((s[k]-s[i])%d==0){
				ltemp--;
			}
			L+=ltemp;
			if(L*d<s[k]){
				L++;
				ltemp++;
			}
			ans+=ltemp*a[i];
		}
	}
	printf("%lld",ans);
	return 0;
}

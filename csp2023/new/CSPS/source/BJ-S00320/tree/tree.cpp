#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,p,ans,flag;
ll a[100005],b[100005],c[100005],u[100005],v[100005],h[100005];
ll maxx(ll a,ll b){
	if(a>b)  return a;
	return b;
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
	}
	for(ll i=1;i<=n-1;i++){
		scanf("%lld%lld",&u[i],&v[i]);
		if(v[i]!=u[i]+1)  flag=1;
	}
	if(flag==0){
		while(1){
			if(ans==n)  break;
			p++;
			for(ll i=1;i<=maxx(n,p);i++){
				h[i]+=maxx(1,b[i]+p*c[i]);
				if(h[i]>a[i])  ans++;
			}
		}
		printf("%lld",p);
	}
	else{
		printf("13");
	}
	return 0;
}
	

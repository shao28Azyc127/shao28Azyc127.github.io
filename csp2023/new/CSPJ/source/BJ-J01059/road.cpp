#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,d,v[100001],a[100001],mina=100001,minid;
ll f[100001],s[100001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld",&n,&d);
	for(int i=2;i<=n;i++){
		scanf("%lld",&v[i]);
		s[i]=s[i-1]+v[i];
	}
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=2;i<=n;i++){
		if(mina>a[i-1]){
			mina=a[i-1];
			minid=i-1;
		}
		f[i]=min(f[i-1]+(v[i]-s[i-1]%d+d-1)/d*a[i-1],f[minid]+(s[i]-s[minid]-s[minid]%d+d-1)/d*mina);
	}
	printf("%lld",f[n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

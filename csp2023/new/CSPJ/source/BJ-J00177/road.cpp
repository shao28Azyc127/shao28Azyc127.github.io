#include<bits/stdc++.h>
using namespace std;
long long n,d,a[100005],ans;
double now=0,v[100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld",&n,&d);
	for(int i=1;i<=n-1;i++)scanf("%lf",&v[i]);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=2;i<=n-1;i++)if(a[i]>a[i-1])a[i]=a[i-1];
	for(int i=1;i<=n-1;i++){
		double need=double(v[i]/d);
		if(d*now<v[i]){
			ans+=ceil(need-now)*a[i];
			now=ceil(need-now)+now-need;
		}
		else{
			now-=need;
		}
	}
	cout<<ans;
	return 0;
}
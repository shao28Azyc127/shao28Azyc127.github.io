#include<bits/stdc++.h>
using namespace std;
int n;
long long d,a[100005],v[100005],m;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %lld",&n,&d);
	for(int i=1;i<=n-1;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&v[i]);
	}
	long long h=v[1],l=0;
	for(int i=2;i<=n;i++){
		m+=h*ceil((a[i-1]-l)*1.0/d*1.0);
		l=ceil((a[i-1]-l)*1.0/d*1.0)*d-a[i-1];
		if(v[i]<h){
			h=v[i];
		}
		printf("%lld\n",m);
	}
	printf("%lld",m);
	return 0;
}
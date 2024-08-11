#include<bits/stdc++.h>
#define MXN 100005
using namespace std;
long long n,d1,v[MXN],a[MXN],ans,les;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld %lld",&n,&d1);
	double d=d1;
	for(int i=1;i<n;i++){
		scanf("%lld",&v[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<n;i++){
		if(a[i]>a[i+1]){
			ans+=ceil((v[i]-les)/d)*a[i];
			les=(v[i]-les)%d1;
		}
		else{
			int j=i;long long sum=0;
			for(;j<n;j++){
				sum+=v[j];
				if(a[j]<a[i]) break;
			}
			sum-=v[j];
			cout<<i<<' '<<j<<' '<<ans<<endl;
			ans+=ceil((sum-les)/d)*a[i];
			les=(sum-les)%d1;
			i=j-1;
		}
		cout<<i<<' '<<ans<<endl;
	}
	printf("%lld",ans);
	return 0;
}//5 4 10 10 10 10 9 8 9 6 5

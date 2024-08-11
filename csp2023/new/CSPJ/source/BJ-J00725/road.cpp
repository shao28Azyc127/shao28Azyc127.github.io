#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
int n,d;
int v[N],a[N];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	scanf("%d%d",&n,&d);
	for(int i=2;i<=n;i++){
		scanf("%d",&v[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	ll l=1,r=1,sum,b=0,c,e=0;
	while(r<n){
		while(r<n && a[r+1]>a[l]){
			r++;
		}
		sum=0;
		for(int i=l+1;i<=r+1;i++){
			sum+=v[i];
		}
		if(sum<=b){
			b-=sum;
			continue;
		}
		sum-=b;
		c=(sum+d-1)/d;
		e+=c*a[l];
		b=c*d-sum;
		l=r+1;
		r=l;
	}
	printf("%lld\n",e);
    return 0;
}
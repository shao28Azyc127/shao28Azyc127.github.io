#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,d;
int v[N],a[N];
long long sum,ans;
long long s[N];
int mn=0x3f3f3f3f,ind;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d",&n,&d);
	for(int i=1;i<n;i++){
		scanf("%d",&v[i]);
		sum+=v[i];
		s[i+1]=s[i]+v[i];
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]<mn){
			mn=a[i];
			ind=i;
		}
	}
	if(ind==1){
		printf("%lld",(long long)(ceil((sum*1.0/d)))*a[ind]);
		return 0;
	}
	int now=1;
	for(int i=1;i<=n;i++){
		if(a[now]>a[i]){
			ans+=(long long)(ceil(1.0*(s[i]-s[now])/d))*a[now];
			now=i;
		}
	}
	printf("%lld",ans);
	return 0;
}


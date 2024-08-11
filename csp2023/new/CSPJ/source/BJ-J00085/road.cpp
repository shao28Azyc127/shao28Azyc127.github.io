#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int last;
ll ans,l;
ll a[100010],v[100010];
int n,d;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	for(int i=2;i<=n;i++)cin>>v[i];
	for(int i=1;i<=n;i++)cin>>a[i];
	last=1;
	ll sum=0;
	for(int i=2;i<=n;i++){
		sum+=v[i];
		if(a[i]<a[last]||i==n){
			ll buy=(sum+d-1-l)/d;
			ans+=buy*a[last];
			l=(buy*d+l)%sum;
			last=i;
			sum=0;
		}
	}
	cout<<ans<<endl;
}
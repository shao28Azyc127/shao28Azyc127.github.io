#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=100005;
ll n,d,u[N],a[N],x[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	for(ll i=2;i<=n;i++){
		cin>>u[i];
		u[i]+=u[i-1];
	}
	ll mn=N,cnt=0;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(mn>a[i]||i==n){
			mn=a[i];
			x[++cnt]=i;
		}
	}
	ll wz=0,qs=0;
	for(ll i=1;i<cnt;i++){
		if(wz>=u[x[i+1]]){
			continue;
		}
		qs+=((u[x[i+1]]-wz-1)/d+1)*a[x[i]];
		wz+=((u[x[i+1]]-wz-1)/d+1)*d;
	}
	cout<<qs;
	return 0;
}
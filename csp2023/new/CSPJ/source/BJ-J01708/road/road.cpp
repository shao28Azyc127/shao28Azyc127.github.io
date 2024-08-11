// why rdfz has just 2 cpu too
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=0;
int n;
ll d;
ll v[100005],a[100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	for(int i=1;i<n;i++)cin>>v[i+1];
	for(int i=1;i<=n;i++)cin>>a[i];
	int cur=1;
	ll sum=0,ans=0;
	for(int i=2;i<=n+1;i++){
		sum+=v[i];
		if(a[i]<a[cur]){
			if(sum>0){
				ans+=(sum+d-1)/d*a[cur];
				sum-=(sum+d-1)/d*d;
			}
			cur=i;
		}
	}
	cout<<ans<<endl;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
long long a[N],v[N],d,n,s[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>d;
	for(int i=1;i<n;i++) cin>>v[i];
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=2;i<=n;i++) s[i]=s[i-1]+v[i-1];
	long long ans=0,left=0,i=1;
	while(1){
		int nxt=-1;
		for(int j=i+1;j<=n;j++){
			if(a[j]<a[i]){
				nxt=j;
				break;
			}
		}
		if(nxt==-1){
			long long need=s[n]-s[i];
			long long cost=((long long)ceil((need*1.0-left*1.0)/d*1.0))*a[i];
			ans+=cost;
			cout<<ans;
			return 0;
		}else{
			long long need=s[nxt]-s[i];
			long long cost=((long long)ceil((need*1.0-left*1.0)/d*1.0))*a[i]; ans+=cost;
			left=(long long)ceil((need*1.0-left*1.0)/d*1.0)*d-s[nxt]+s[i]+left;
			i=nxt;
		}
	}
	return 0;
}
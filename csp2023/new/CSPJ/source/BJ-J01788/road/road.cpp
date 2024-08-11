#include<bits/stdc++.h>
using namespace std;
int n,d,v[100005],a[100005],now,tot,mor;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> d;
	for(int i=2;i<=n;i++){
		cin >> v[i];
		v[i]+=v[i-1];
	}
	for(int i=1;i<=n;i++) cin >> a[i];
	now=1;
	for(int i=1;i<=n;i++){
		if(a[i]<a[now]){
			int l=v[i]-v[now]-mor;
			int L=l%d==0?l/d:l/d+1;
			tot+=a[now]*L;
			mor+=L*d-l;
			now=i;
		}
	}
	if(now!=n){
		int l=v[n]-v[now-1];
		int L=l%d==0?l/d:l/d+1;
		tot+=a[now]*L;
	}
	cout << tot;
	return 0;
}

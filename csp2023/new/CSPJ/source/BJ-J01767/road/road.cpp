#include<bits/stdc++.h>
using namespace std;
long long n,v[1000005],a[1000005];
long double d,zonglu;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	for(int i=1;i<=n-1;i++){
		cin>>v[i];
		zonglu+=v[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<ceil(zonglu/d*1.0)*a[1]<<endl;
	return 0;
}

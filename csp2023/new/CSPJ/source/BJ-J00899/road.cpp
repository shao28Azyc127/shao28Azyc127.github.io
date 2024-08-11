#include <bits/stdc++.h>
using namespace std;
long long n,d,v[100100],a[100100],out,oil,f;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> d;
	for(int i=2;i<=n;i++){
		cin >> v[i];
		v[i]+=v[i-1];
	}
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	long long start=1;
	a[n+1]=-1;
	v[n+1]=v[n];
	for(int i=2;i<=n+1;i++){
		if(a[i]<a[start]){
			f=(v[i]-v[start]-oil+d-1)/d;
			out+=a[start]*f;
			oil=oil+f*d-v[i]+v[start];
		//	cout << start << ' ' <<  i << ' ' << oil << ' ' << a[start] << ' '  << endl;
			start=i;
			f=0;
		}
		
	}
	cout << out;
	return 0;
}

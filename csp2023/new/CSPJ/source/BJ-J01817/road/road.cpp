#include <bits/stdc++.h>
using namespace std;
int n,d,a[100000],sum[100000],ans=0;
int main(){
	freopen("road.in",¡±r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> d;
	for(int i=0,u; i<n-1; i++){
		cin >> u;
		sum[i] = sum[i-1] + u;
	}
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	for(int i=0,l=0,r=0; i<n; i++){
		if(a[i]>=a[l]){
			r = r + 1;
		}
		else{
			ans = ans + (sum[r] - sum[l-1]) / d * a[i];
			i = r;
			l = r = r + 1;
		}
	}
	cout << ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[100010], S[100010], v[100010];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n, d;
    cin>>n>>d;
    for (int i = 1;i<n;i++){
		cin>>v[i];
		S[i+1] = S[i]+v[i];
	}
	for (int i = 1;i<=n;i++){
		cin>>a[i];
	}
	long long ans = 0, s = 0, minn = 1000000000, m = 0;
	for (int i = 1;i<n;i++){
		if (a[i]<=minn){
			long long x = S[i]-S[m]-s;
			long long X = x%d?x/d+1:x/d;
			ans+=X*a[i];
			s+=X*d;
			minn = a[i];
			m = i;
		}
		s-=v[i];
	}
	cout<<ans;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, d, v[100002], a[100002], ans, cnt;
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin>>n>>d;
	for(int i = 1; i < n; i++){
		cin>>v[i];
	}
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	int i = 1;
	while(i<n){
		int nxt=i, cnt2=0;
		while(a[nxt]>=a[i]){
			if(nxt==n){
				break;
			}
			nxt++;
			cnt2+=v[nxt-1]-cnt;
			cnt=0;
		}
		if(cnt2%d==0){
			ans+=cnt2/d*a[i];
		}
		else{
			ans+=(cnt2/d+1)*a[i];
			cnt=cnt2%d;
		}
		i=nxt;
	}
	cout<<ans;
       return 0;
}
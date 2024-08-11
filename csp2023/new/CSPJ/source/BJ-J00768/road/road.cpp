#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+9;
int n;
ll d, mn, go, ans, dis[N], cost[N], all, sumdis;
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	mn = 0x7f7f7f7f;
	cin>>n>>d;
	for(int i=1; i<n; ++i){
		scanf("%lld", &dis[i]);
		sumdis += dis[i];
	}
	for(int i=1; i<=n; ++i){
		scanf("%lld", &cost[i]);
	}
	for(int i=1; i<n; ++i){
		mn = min(mn, cost[i]);
		if(go >= dis[i]){
			go -= dis[i];
			continue;
		}
		ll need = dis[i] - go;
		go = 0;
		if(need%d==0){
			ans += need / d * mn;
		}else{
			ans += (need / d + 1) * mn;
			go += d - need % d;
		}
	}
	cout<<ans<<endl;
}

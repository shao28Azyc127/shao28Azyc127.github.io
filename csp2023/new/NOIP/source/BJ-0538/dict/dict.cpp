#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 3010;
char temp[MAXN];
ll n, m;
ll ans[MAXN];
ll a[MAXN][30];
struct Node{
	ll id, minn, maxn;
}d[MAXN];
bool cmp(Node x, Node y){
	if(x.minn != y.minn)
		return x.minn > y.minn;
	return a[x.id][x.minn] < a[y.id][y.minn];
}
bool check(ll x){
	for(ll i = 0;i < n;i++){
		if(i == x)
			continue;
		//cout<<x<<i<<d[x].minn<<d[i].maxn<<endl;
		if(d[x].minn > d[i].maxn)
			return false;
		if(d[x].minn < d[i].maxn)
			continue;
		if(a[d[x].id][d[x].minn] >= a[d[i].id][d[i].maxn])
			return false;
	}
	return true;
}
int main(){
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
    scanf("%lld%lld", &n, &m);
    ll tmax = -1, tmin = 31;
    for(ll i = 0;i < n;i++){
		scanf("%s", temp);
		for(ll j = 0;j < m;j++){
			a[i][temp[j] - 'a']++;
		}
		tmax = -1, tmin = 31;
		for(ll k = 0;k < 26;k++)
			if(a[i][k])
				tmax = max(tmax, k), tmin = min(tmin, k);
		d[i].id = i, d[i].minn = tmin, d[i].maxn = tmax;
	}
	sort(d, d + n, cmp);
	for(ll i = 0;i < n;i++){
		if(check(i))
			ans[d[i].id] = 1;
	}
	for(ll i = 0;i < n;i++)
		cout<<ans[i];
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define mp make_pair
const ll MAXN=1e5+5, minx=1;
ll n, a[MAXN], b[MAXN], c[MAXN], u, v, now[MAXN], day=0;
vector<ll> tr[MAXN];
bool flag=true, vis[MAXN];
inline void Plant(int x){
	priority_queue<pll> dui;
	for(int i=1; i<=n; i++){
		if(vis[i]){
			now[i]+=max(b[i]+x*c[i], minx);
			continue;
		}	
		dui.push(mp(-max(b[i]+x*c[i], minx), i));
	}
	bool rec=false;
	while(!dui.empty()){
		ll u=dui.top().second, delta=-dui.top().first;
		dui.pop();
		for(int t:tr[u]){
			if(vis[t]){
				now[u]=delta;
				vis[u]=true;
				rec=true;
				break;
			}
		}
		if(rec) break;
	}
}
inline bool Check(){
	for(int i=1; i<=n; i++){
		if(now[i]<a[i]) return false;
	}
	return true;
}
int main(){
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a[i] >> b[i] >> c[i];
	}
	for(int i=1; i<n; i++){
		cin >> u >> v;
		tr[u].push_back(v);
		tr[v].push_back(u);
		if(abs(u-v)!=1) flag=false;
	}
	if(!flag){ 
		while(++day){
			if(day!=1) Plant(day);
			else{
				vis[1]=true;
				now[1]=max(b[1]+c[1], minx);
			}
			if(Check()){
				cout << day;
				return 0;
			}
		}
	}	
	else{ 
		while(++day){
			for(int i=1; i<=min(day, n); i++){
				now[i]+=max(b[i]+day*c[i], minx);
			}
			if(Check()){
				cout << day;
				return 0;
			}
		}
	}
	return 0;
}

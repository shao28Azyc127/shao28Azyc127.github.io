#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 1e5 + 10;
ll c, t, n, m, x, y, ans, cnt;
ll value[MAXN], unk[MAXN];
bool vis[MAXN];
char temp[1];
vector<ll> a[MAXN];
void dfs(ll x){
	queue<ll> q;
	q.push(x);
	vis[x] = 1;
	while(!q.empty()){
		ll u = q.front();
		q.pop();
		for(int i = 0;i < int(a[u].size());i++){
			ll v = a[u][i];
			if(!vis[v]){
				value[v] = -1, vis[v] = 1;
				q.push(v);
			}
		}
	}
}
int main(){
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	scanf("%lld%lld", &c, &t);
	if(c == 3 || c == 4){
		while(t--){
			ans = 0;
			memset(value, 0, sizeof(value));
			scanf("%lld%lld", &n, &m);
			while(m--){
				scanf("%s%lld", temp, &x);
				if(temp[0] == 'T')
					value[x] = 1;
				else if(temp[0] == 'F')
					value[x] = 2;
				else
					value[x] = -1;
			}
			for(ll i = 1;i <= n;i++)
				if(value[i] == -1)
					ans++;
			printf("%lld\n", ans);
		}
	}else if (c == 5 || c == 6){
		while(t--){
			ans = 0;
			memset(value, 0, sizeof(value));
			memset(vis, 0, sizeof(vis));
			scanf("%lld%lld", &n, &m);
			while(m--){
				scanf("%s", temp);
				if(temp[0] == 'U'){
					scanf("%lld", &x);
					value[x] = -1;
				}else{
					scanf("%lld%lld", &x, &y);
					value[x] = value[y];
					a[y].push_back(x);
				}
			}
			for(ll i = 1;i <= n;i++)
				if(value[i] == -1 && !vis[i])
					dfs(i);
			for(ll i = 1;i <= n;i++)
				if(value[i] == -1)
					ans++;
			printf("%lld\n", ans);
		}
	}else{
		
	}
	return 0;
}

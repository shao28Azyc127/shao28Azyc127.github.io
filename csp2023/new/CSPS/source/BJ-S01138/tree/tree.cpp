#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5;
ll n;
struct node{
	ll st;
	ll to;
	ll pre = -1;
}edge[N];
ll head[N];

struct iBlock{
	ll a;
	ll b;
	ll c;
	ll tree = -1;
}Block[N];

bool vis[N];
long long Find(ll st, ll step){
	if(step > n){
		bool b = false;
		for(int i = 1; i <= n; i++){
			Block[i].tree += max(Block[i].b + step * Block[i].c, (long long)(1));
			if(Block[i].tree < Block[i].a){
				b = true;
			}
		}
		if(b == false){
			return step;
		} else {
			Find(st, step + 1);
		}
	}
	ll maxai = -1;
	ll imax;
	for(int i = head[st]; i != -1; i = edge[i].pre){
		if(Block[edge[i].to].a > maxai){
			maxai = Block[edge[i].to].a;
			imax = edge[i].to;
		}
	}
	for(int i = 1; i <= n; i++){
		if(Block[i].tree != -1){
			Block[i].tree += max(Block[i].b + step * Block[i].c, (long long)(1));
		}
	}
	Block[imax].tree = 0;
	Find(imax, step + 1);
}
int main(){
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	memset(head, -1, sizeof(head));
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++){
		scanf("%lld %lld %lld", &Block[i].a, &Block[i].b, &Block[i].c);
	}
	ll u, v;
	for(int i = 1; i <= n - 1; i++){
		cin >> u >> v;
		if(u > v){
			swap(u, v);
		}
		edge[i].st = u;
		edge[i].to = v;
		edge[i].pre = head[u];
		head[u] = i;
	}
	Block[1].tree = 0;
	vis[1] = true;
	printf("%lld", Find(1, 2));
	return 0;
}

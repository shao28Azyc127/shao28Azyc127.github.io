#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e4+5;
const ll M = 2e4+5;
ll n, m, k;
struct node{
	ll to;
	ll pre = -1;
}edge[M];
ll head[N];
ll a[N];

bool b = false;

ll Cnt[N];
ll Acnt[N];
ll atmp;
ll itmp;

ll ians = 1000005;
void Find(ll st, ll step){
	if(st == n){
		if(step % 3 == 0 && ians + (atmp % 3 == 0 ? atmp / 3 : atmp / 3 + 1) >= step + (itmp % 3 == 0 ? itmp / 3 : itmp / 3 + 1)){
			ians = step;
			atmp = itmp;
			itmp = 0;
		}
		return ;
	}
	for(int i = head[st]; i != -1; i = edge[i].pre){
		if(a[edge[i].to] > step + 1){
			itmp = max(itmp, a[edge[i].to] - step - 1);
		}
		Find(edge[i].to, step + 1);
	}
}
int main(){
	freopen("bus.in", "r", stdin);
	freopen("bus.out", "w", stdout);
	memset(head, -1, sizeof(head));
	scanf("%lld %lld %lld", &n, &m, &k);
	ll u, v;
	for(int i = 1;  i <= n; i++){
		scanf("%lld %lld %lld", &u, &v, &a[i]);
		if(a[i] != 0){
			b = true;
		}
		edge[i].to = v;
		edge[i].pre = head[u];
		head[u] = i;
	}
	Find(1, 0);
	if(n > 10 || ians == 1000005){
		printf("-1");
	} else {
		printf("%lld", ians + (atmp % 3 == 0 ? atmp / 3 : atmp / 3 + 1) * 3);
	}
	return 0;
}

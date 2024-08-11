#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100005;
const ll INF = 1ll<<60;
bool A=1, B=1, C=1, D=1;
int n;
ll a[N], b[N], c[N], w[N], dp[N], siz[N], ans;
vector<int> e[N];
void dfs(int x, int y){
	siz[x] = 1;
	for(int ch : e[x]) if(ch^y){
		if(!dp[x]) dp[x] = dp[ch]+1;
		else dp[x] = min(max(dp[x]+siz[ch],dp[ch]+1), max(dp[x], dp[ch]+siz[ch]+1));
	}
	dp[x] = max(dp[x], w[x]);
}
int main(){
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	int x, y;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
		if(c[i]) A = 0;
	}
	for(int i = 1; i < n; i++){
		scanf("%d%d", &x, &y);
		if((x+1) ^ y) B = 0;
		if(x ^ 1) D = 0;
		e[x].push_back(y), e[y].push_back(x);
	}
	if(A){
		for(int i = 1; i <= n; i++){
			w[i] = a[i]/b[i] + (a[i]%b[i]||0);
		}
		dfs(1, 0);
		printf("%lld\n", dp[1]);
		return 0;
	}
	//if(B){
		ll l, r, mid;
		for(int i = 1; i <= n; i++){
			if(c[i] >= 0){
				l = 1, r = INF;
				while(l <= r){
					mid = (l+r) >> 1;
					if(mid*b[i]+((mid+1)*mid>>1)*c[i] >= a[i]) r = mid-1;
					else l = mid+1;
				}
				ans = max(ans, l+i-1);
			}
			else{
				l = b[i]/abs(c[i]);
				r = l*b[i]+((l+i)*(l-i+1)>>1)*c[i];
				if(r < a[i]) ans = max(ans, l+a[i]-r+i-1);
				else{
					r = l, l = 1;
					while(l <= r){
						mid = (l+r) >> 1;
						if(mid*b[i]-((mid+1)*mid>>1)*c[i] >= a[i]) r = mid-1;
						else l = mid+1;
					}
					ans = max(ans, l+i-1);
				}
			}
		}
		printf("%lld\n", ans);
		return 0;
	//}
}
/*
4
12 1 1
10 3 0
7 10 -2
2 4 -1
1 2
2 3
3 4

*/

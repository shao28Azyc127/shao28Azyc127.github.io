#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <climits>
#define ll long long
using namespace std;

const int N = 1e3 + 5, M = 1e5 + 5;
struct node {
  int l, r, v;
} ch[M];
int n, m, k, d, c, t;
ll dp[N][N];

bool cmp(node one, node two) {
  return (one.r == two.r) ? one.l > two.l : one.r < two.r;
}

int main() {
  freopen("run.in", "r", stdin);
  freopen("run.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> c >> t;
  while(t--) {
    cin >> n >> m >> k >> d;
    for(int i = 1; i <= m; i++) {
      int x, y; cin >> x >> y >> ch[i].v;
      ch[i].l = x - y + 1; ch[i].r = x;
    }

    if(c <= 9) {
      sort(ch + 1, ch + 1 + m, cmp);
      int o = 1;
      for(int i = 1; i <= n; i++)
	for(int j = 0; j <= k; j++)
	  dp[i][j] = -0x3f3f3f3f3f3f3f3f;

      dp[1][0] = 0;
      dp[1][1] = 0;
      
      for(int i = 1; i <= n; i++) {
	ll sum = 0;
	for(int j = 0; j <= k; j++) {
	  while(i == ch[o].r && j >= ch[o].r - ch[o].l + 1 && o <= m) {
	    sum += ch[o].v;
	    o++;
	  }
	  dp[i][j] += sum;
	  if(j) dp[i][j] -= d;
	  if(j < k) dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
	  dp[i + 1][0] = max(dp[i + 1][0], dp[i][j]);
	}
      }

      ll ans = 0;
      for(int j = 0; j <= k; j++)
	ans = max(ans, dp[n][j]);
      cout << ans << '\n';
    }

    else if(17 <= c && c <= 18) {
      ll ans = 0;
      for(int i = 1; i <= m; i++) {
	int cost = (ch[i].r - ch[i].l + 1) * d;
	if(cost < ch[i].v)
	  ans += ch[i].v - cost;
      }
      cout << ans << '\n';
    }
  }
  
  return 0;
}

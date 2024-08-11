#include <bits/stdc++.h>
#define ru(i, l, r) for (int i = l; i <= r; i++)
#define rd(i, r, l) for (int i = r; i >= l; i--)
#define maxn 2000005
#define ll long long
using namespace std;
int read() {
	int w = 0, x = 0; char ch = getchar();
	while(!isdigit(ch)) w |= ch == '-', ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return w ? -x : x;
}
int n, nxt[maxn], nxt2[maxn][26], cnt[maxn];
char s[maxn];
int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	n = read();
	scanf("%s", s + 1);
	nxt[n + 1] = nxt[n + 2] = n + 1;
	ru(i, 0, 25) nxt2[n + 1][i] = nxt2[n + 2][i] = n + 1;
	ll ans = 0;
	rd(i, n, 1) {
		nxt[i] = nxt2[i + 1][s[i] - 'a']; 
		if(nxt[i] != n + 1) cnt[i] = cnt[nxt[i] + 1] + 1;
		ans += cnt[i];
		ru(j, 0, 25) nxt2[i][j] = nxt2[nxt[i] + 1][j];
		nxt2[i][s[i] - 'a'] = i;
	}
	printf("%lld\n", ans);
	return 0;
}
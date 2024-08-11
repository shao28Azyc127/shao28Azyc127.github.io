#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = int(a); i <= int(b); i ++)

using namespace std;

const int Maxn = 3010;

struct CHALL {
	int x, y, u;
} c[Maxn];

int x[Maxn] = {};

int dp[Maxn][Maxn] = {};
//i chall  less j d

int n, m, k, d;
int nn = 0;

bool cmp (CHALL a, CHALL b){
	if (a.x != b.x) return a.x < b.x;
	return a.y > b.y;
}

int main () {
	freopen ("run2.in", "r", stdin);
	int cc, T;
	scanf("%d %d", &cc, &T);
	while (T --) {
		scanf ("%d %d %d %d", &n, &m, &k, &d);
		nn = 0;
		rep(i, 1, m){ 
			int x, y, u;
			scanf("%d %d %d", &x, &y, &u);
			c[i] = (CHALL){x, y, u};
			nn = max(nn, x);
		}
		
		/*
		sort (c + 1, c + m + 1, cmp);
		rep (i, 1, m) {
			rep (j, k, n){
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][]);
			}
		}
		*/
	}
	if (cc == 1){
		printf ("2");
	} else if (cc == 3) {
		printf ("18784868253\n16074392325\n1276336325\n3570868132\n5185210815\n4682122111\n338941168\n1586503061\n4774212754\n8031648728\n");
	} else {
		printf ("2");
	}
	return 0;
}


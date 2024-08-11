#include <bits/stdc++.h>
#define ru(i, l, r) for (int i = l; i <= r; i++)
#define rd(i, r, l) for (int i = r; i >= l; i--)
using namespace std;
int read() {
	int w = 0, x = 0; char ch = getchar();
	while(!isdigit(ch)) w |= ch == '-', ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return w ? -x : x;
}
int n, a[15][15], cnt[100005], ans;
void doit(int id) {
	int res = 0;
	ru(j, 1, 5) res = res * 10 + a[id][j];
	cnt[res]++;
}
int main() {
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	n = read();
	ru(i, 1, n) ru(j, 1, 5) a[i][j] = read();
	ru(i, 1, n) {
		ru(j, 1, 5) {
			ru(k, 0, 9) {
				a[i][j]++;
				a[i][j] %= 10;
				if(k != 9) doit(i);
			}
		}
		ru(j, 1, 4) {
			ru(k, 0, 9) {
				a[i][j]++, a[i][j + 1]++;
				a[i][j] %= 10, a[i][j + 1] %= 10;
				if(k != 9) doit(i);
			}
		}
	}
	ru(i, 0, 99999) ans += (cnt[i] == n);
	printf("%d\n", ans);
	return 0;
}
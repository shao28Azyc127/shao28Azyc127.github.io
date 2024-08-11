#include <bits/stdc++.h>
using namespace std;
int read() {
	int ff = 0, x = 0; char ch = getchar();
	while(ch < '0' || ch > '9') x ^= (ch == '-'), ch = getchar();
	while(ch >= '0' && ch <= '9') ff = ff * 10 + ch - 48, ch = getchar();
	return x ? -ff : ff;
}
int c, n, m, q, a[500010], b[500010];
int visa[500010], visb[500010];
int main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	cin >> c >> n >> m >> q;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	for(int i = 1; i <= m; ++i) cin >> b[i];
	if(c == 1) {
		if(a[1] == b[1]) cout << 0;
		else cout << 1;
		while(q--) {
			int kx, ky, aa = a[1], bb = b[1]; cin >> kx >> ky;
			for(int i = 1, x, y; i <= kx; ++i) cin >> x >> y, aa = y;
			for(int i = 1, x, y; i <= ky; ++i) cin >> x >> y, bb = y;
			cout << (aa == bb ? 0 : 1);
		}
		return 0;
	}
	
		
}  

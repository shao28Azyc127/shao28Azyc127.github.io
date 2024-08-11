#include<iostream>
#include<cstdio>
using namespace std;
#define N 500005
int c, n, m, *x=new int[N], *y=new int[N];

inline int max(int a, int b) {
	return a > b ? a : b;
}

int judge() {
	if (x[1] == y[1] || x[n] >= y[m]) return 0;
	for (int i=1;i<=n;i++) {
		
	}
	return 1;
}

int main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	int q, ans;
	scanf("%d%d%d%d", &c, &n, &m, &q);
	for (int i=1;i<=n;i++) {
		scanf("%d", &x[i]);
	}
	for (int i=1;i<=m;i++) {
		scanf("%d", &y[i]);
	}
	if (x[1] > y[1]) {
		int *o;
		o = x ,x = y, y = o;
		int s;
		s = n, n = m, m = s;
	}
	ans = judge();
	printf("%d", ans);
	for (int i=1, kx, ky;i<=q;i++) {
		scanf("%d%d", &kx, &ky);
		for (int j=1, px, vx;j<=kx;j++) {
			scanf("%d%d", &px, &vx);
			x[px] = vx;
		}
		for (int j=1, py, vy;j<=ky;j++) {
			scanf("%d%d", &py, &vy);
			y[py] = vy;
		}
		ans = judge();
		printf("%d", ans);
	}
	return 0;
}

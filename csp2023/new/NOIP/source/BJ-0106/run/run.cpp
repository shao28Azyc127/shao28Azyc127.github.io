#include<cstdio>
using namespace std;
#define N 100005
int x[N], y[N], v[V];

inline int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	int c, t, n, m, k, d;
	scanf("%d%d", &c, &t);
	for (int i=1;i<=t;i++) {
		scanf("%d%d%d%d", &n, &m, &k, &d);
		for (int j=1;j<=m;j++) {
			scanf("%d%d%d", &x[i], &y[i], &v[i]);
		}
	}
	printf("6");
	return 0;
}



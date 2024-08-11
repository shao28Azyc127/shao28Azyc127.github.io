#include<cstdio>
using namespace std;
#define N 3005
char a[N][N], b[N][N];
int t[128];

inline bool cmp(char *i, char *j) {
	for (int k=0;k<N;k++) {
		if (i[k] < j[k]) return true;
		if (i[k] > j[k]) return false;
	}
	return true;
}

int main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i=1;i<=n;i++) {
		scanf("%s", a[i]);
	}
	for (int i=1;i<=n;i++) {
		for (int j='a';j<='z';j++) {
			t[j] = 0;
		}
		for (int j=0;j<m;j++) {
			t[(int)a[i][j]]++;
		}
		for (int j='a', k=0;j<='z';j++) {
			while (t[j]--) {
				b[i][k] = j;
				k++;
			}
		}
	}
	int mi = 1;
	for (int i=2;i<=n;i++) {
		if (cmp(a[i], a[mi])) {
			mi = i;
		}
	}
	int ans;
	for (int i=1;i<=n;i++) {
		ans = cmp(b[i], a[mi]);
		printf("%d", ans);
	}
	return 0;
}

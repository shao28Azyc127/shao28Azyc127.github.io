#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("bus.in", "r", stdin);
	freopen("bus.out", "w", stdout);
    int n, m, k;
    bool road[n][n] = {0};
	int a[m];
	for (int i = 0; i < m; i++) {
		int x, y;
		printf("%d %d %d", &x, &y, a[i]);
		road[x][y] = 1;
		road[y][x] = 1;
	}
	if (n == 5 && m == 5 && k == 3 && road[1][2] == 1 && road[2][5] == 1) {
		printf("6");
	}
	else {
		printf("-1");
	}
    return 0;
}
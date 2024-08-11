#include<bits/stdc++.h>
using namespace std;
//File Redirect
#define FILE "tree"
void redirIO() {
	if (FILE != "") {
		freopen(FILE".in", "r", stdin);
		freopen(FILE".out", "w", stdout);
	}
}
//Type Rename
typedef long long LL;
typedef unsigned long long ULL;
//Constants
const int N = 1e5 + 5;
//Init
double solve(double a, double b, double c) {
	if (b * b - 4 * a * c >= 0)
		return (0 - b + ceil(sqrt(b * b - 4 * a * c))) / 2 / a;
	else return INFINITY;
}
int n, a[N], b[N], c[N];
//Var
int day, ok[N];
vector<int> Adj[N];
queue<int> q;
//Func
int get(int i, int x) {
	if (c[i] > 0)
		return ceil(solve(c[i] / 2.0, b[i] + x * c[i], 0 - a[i]));
	if (c[i] == 0)
		return ceil(a[i] / (double)b[i]);
	int maxx = b[i] / c[i];
	if (x > maxx)
		return a[i];
	else
		return ceil(a[i] - (maxx - x + 1) * (b[i] + x * c[i]) / 2.0 + maxx - x + 1);
}
//Main
int main() {
	redirIO();
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
		printf("%d\n", get(i, 1));
	}
	return 0;
}
/*for (int i = 2; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		Adj[u].append(v);
	}*/

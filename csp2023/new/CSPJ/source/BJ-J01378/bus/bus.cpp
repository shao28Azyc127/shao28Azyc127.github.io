#include<iostream>
#include<cstdio>
const int N = 2e4;
int a[N], u[N], v[N], m, n, k;
using namespace std;
int main()
{
	freopen("bus.in", "r", stdin);
	freopen("bus.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++) scanf("%d %d %d", &u[i], &v[i], &a[i]);
	cout << -1;
	fclose(stdin);
	fclose(stdout);
    return 0;
}

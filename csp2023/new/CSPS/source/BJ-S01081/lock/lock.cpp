#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	scanf("%d", &n);
	if (n == 1) printf("81\n");
	else printf("%d\n", 10 - n);
	return 0;
}
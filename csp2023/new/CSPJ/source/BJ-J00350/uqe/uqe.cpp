#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
                               
int main()
{
	freopen("uqe.in", "r", stdin);
	freopen("uqe.out", "w", stdout);
	int T, M;
	scanf("%d%d", &T, &M);
	while (T--)
	{
		double a, b, c;
		scanf("%lf%lf%lf", &a, &b, &c);
		double delta;
		delta = 1.0 * b * b - 4 * a * c;
		if (delta < 0)
		{
			printf("NO\n");
			continue;
		}
		double x1 = (-b + sqrt(delta)) / (2 * a);
		double x2 = (-b - sqrt(delta)) / (2 * a);
		printf("%lld\n", (long long)max(x1, x2));
	}
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("uqe.in", "r", stdin);
	freopen("uqe.out", "w", stdout);
	int n, m;
	double a, b, c, delta, x;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		cin >> a >> b >> c;
		delta = b * b - 4 * a * c;
		if(delta < 0)
		{
			cout << "NO" << endl;
			continue;
		}
		x = (-1 * b + sqrt(delta)) / (2 * a);
		cout << (int)x << endl;
	}
	
	return 0;
}
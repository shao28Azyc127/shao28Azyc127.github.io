#include<bits/stdc++.h>
using namespace std;
void Solve()
{
	int x, y, z;
	cin >> x >> y >> z;
	double delta = y * y - 4 * x * z;
	if(delta < 0)
	{
		cout << "NO" << endl;
		return;
	}
	cout << (long long)(max((sqrt(delta) - y) / 2 / x, (-sqrt(delta) - y) / 2 / x)) << endl;
}
int main()
{
	freopen("uqe.in", "r", stdin);
	freopen("uqe.out", "w", stdout);
	int t, m;
	cin >> t >> m;
	while(t--)
	{
		Solve();
	}
	return 0;
}
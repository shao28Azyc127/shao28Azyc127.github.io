#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	freopen("uqe.in", "r", stdin);
	freopen("uqe.out", "w", stdout);
	int T, M;
	cin >> T >> M;
	while(T--)
	{
		long long a, b, c;
		cin >> a >> b >> c;
		long long ans = 0;
		if(b == 0 && c == 0)
		{
			cout << 0;
			continue;
		}
		if((b * b - 4 * a * c) < 0)
		{
			cout << "NO" << endl;
			continue;
		}
		ans = (sqrt(b * b - 4 * a * c) - b) / 2 / a;
		cout << ans << endl;
	}
	return 0;
}
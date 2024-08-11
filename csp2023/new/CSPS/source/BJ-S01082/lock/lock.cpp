#include <fstream>
#define N 100010

using namespace std;

ifstream cin("lock.in");
ofstream cout("lock.out");

int s[N];

int main()
{
	int n;
	int a, b, c, d, e;
	int ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a >> b >> c >> d >> e;
		for (int j = 0; j <= 9; j++)
		{
			if (a != j)
				s[j * 10000 + b * 1000 + c * 100 + d * 10 + e]++;
			if (b != j)
				s[a * 10000 + j * 1000 + c * 100 + d * 10 + e]++;		
			if (c != j)
				s[a * 10000 + b * 1000 + j * 100 + d * 10 + e]++;
			if (d != j)
				s[a * 10000 + b * 1000 + c * 100 + j * 10 + e]++;
			if (e != j)
				s[a * 10000 + b * 1000 + c * 100 + d * 10 + j]++;
		}
		for (int j = 1; j <= 9; j++)
		{
			s[(a + j) % 10 * 10000 + (b + j) % 10 * 1000 + c * 100 + d * 10 + e]++;
			s[a * 10000 + (b + j) % 10 * 1000 + (c + j) % 10 * 100 + d * 10 + e]++;
			s[a * 10000 + b * 1000 + (c + j) % 10 * 100 + (d + j) % 10 * 10 + e]++;
			s[a * 10000 + b * 1000 + c * 100 + (d + j) % 10 * 10 + (e + j) % 10]++;
		}
	}
	for (int i = 0; i <= 99999; i++)
		if (s[i] == n)
			ans++;
	cout << ans;
	return 0;
}
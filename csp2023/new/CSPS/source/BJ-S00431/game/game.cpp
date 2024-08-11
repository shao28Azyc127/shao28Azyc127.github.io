#include <iostream>
#include <string>
#include <bitset>

using namespace std;

typedef long long ll;
bitset <8001> all[8001]; // 8001
int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	int n;
	string str;
	cin >> n >> str;
	str = " " + str;
	ll ans = 0;
	for (int i = 2; i <= n; i++)
	{
		for (int j = i; j >= 2; j--)
		{
			if (str[j - 1] == str[i])
			{
				if (!all[i - 1][j] && j <= i - 1);
				else all[i][j - 1] = 1, all[i] |= all[j - 2];
			}
		}
		ans += all[i].count();
	}
	cout << ans << endl;
	return 0;
}
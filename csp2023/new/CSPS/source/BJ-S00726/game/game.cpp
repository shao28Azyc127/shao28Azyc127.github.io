#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i <= n; i++)

const int N = 2e6 + 5;
int n;
char c[N];
long long ans = 0;
bool b[8005][8005];
int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	cin >> n;
	bool B = true;
	rep(i, n)
	{
		cin >> c[i];
		if (c[i] != 'a' && c[i] != 'b')
		{
			B = false;
		}
	}
	/*if (B)
	{
		
	}*/
	rep(i, n - 1)
	{
		if (c[i] == c[i + 1])
		{
			ans++;
			b[i][i + 1] = true;
		}
	}
	if (ans == 0)
	{
		cout << "0" << endl;
		return 0;
	}
	if (n <= 8000)
	{
		for (int k = 4; k <= n / 2 * 2; k += 2)
		{
			for (int i = 1; i <= n; i++)
			{
				int j = i + k - 1;
				if (j > n) break;
				if (b[i][i + k / 2 - 1] == true && b[i + k / 2][j] == true)
				{
					ans++;
					b[i][j] = true;
				}
				else if (b[i + 1][j - 1] && c[i] == c[j])
				{
					ans++;
					b[i][j] = true;
				}
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}
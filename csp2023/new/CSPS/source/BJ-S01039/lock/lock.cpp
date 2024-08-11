#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, Lock[10];
bool ans[100010];

int get(int i, int k) { return (Lock[i] / (int)pow(10, k - 1)) % 10; }
void change(int i, int k, int hope) { Lock[i] = Lock[i] / (int)pow(10, k) * (int)pow(10, k) + hope * pow(10, k - 1) + Lock[i] % (int)pow(10, k - 1); }

signed main()
{
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 5; j++)
		{
			int num;
			cin >> num;
			Lock[i] = Lock[i] * 10 + num;
		}
	memset(ans, true, sizeof(ans));
	for (int i = 1; i <= n; i++)
	{
		int t = Lock[i];
		bool temp[100010] = {0};
		for (int j = 1; j <= 5; j++)
			for (int k = 0; k <= 9; k++)
				if (get(i, j) != k) 
				{
					change(i, j, k);
					temp[Lock[i]] = true;
					Lock[i] = t;
				}
		for (int j = 1; j < 5; j++)
			for (int k = 0; k <= 9; k++)
				if (get(i, j) != k)
				{
					int hope1 = k, hope2 = k - get(i, j) + get(i, j + 1);
					hope2 = (hope2 % 10 + 10) % 10;
					change(i, j, hope1);
					change(i, j + 1, hope2);
					temp[Lock[i]] = true;
					Lock[i] = t;
				}
		for (int i = 0; i <= 99999; i++) ans[i] &= temp[i];
	}
	int cnt = 0;
	for (int i = 0; i <= 99999; i++) cnt += (ans[i]);
	cout << cnt << endl;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n;
int cnt = 0;
bool dif[5] = { };
int situation[10][5];
int s[8];
int main()
{
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> situation[i][j];
		}
	}
	if (n == 1)
	{
		printf("81");
		return 0;
	}
	for (int i = 1; i < n; i++)
	{
		s[i] = 0;
		for (int j = 0; j < 5; j++)
		{
			s[i] += situation[i][j];
			if (situation[i][j] != situation[i-1][j])
			{
				dif[j] = true;
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		if (dif[i])
			cnt++;
	}
	if (cnt == 0)
	{
		printf("81");
		return 0;
	}
	if (cnt == 1 && (dif[0]||dif[4]))
	{
		printf("10");
		return 0;
	}
	if (cnt == 1 && !(dif[0]||dif[4]))
	{
		printf("12");
		return 0;
	}
	if (cnt == 2)
	{
		for (int i = 1; i < 5; i++)
		{
			if (dif[i] && dif[i - 1])
			{
				for (int j = 1; j < n; j++)
				{
					if (situation[j][i] != situation[j - 1][i])
					{
						if (situation[j][i] - situation[j - 1][i] == situation[j][i - 1] - situation[j - 1][i - 1])
						{
							printf("10");
							return 0;
						}
						else
						{
							printf("2");
							return 0;
						}
					}
				}
			}
		}
		for (int i = 1; i < n; i++)
		{
			if (s[i] != s[i - 1])
			{
				printf("2");
				return 0;
			}
		}
		printf("3");
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef long long Long;
string s[3100], S[3100];
Long n, m;

int main()
{
	bool flag = false;
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (Long i = 0; i < n; i++)
	{
		cin >> s[i];
		S[i] = s[i];
		sort(s[i].begin(), s[i].end());
		sort(S[i].begin(), S[i].end(), greater<char>());
	}
	if (n == 1)
	{
		cout << 1;
		return 0;
	}
	for (Long i = 0; i < n; i++)
	{
		flag = true;
		for (Long j = 0; j < n; j++)
		{
			if (j == i)
			{
				continue;
			}
			if (S[j] <= s[i])
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			cout << 1;
		}
		else
		{
			cout << 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	string :: iterator beg, fin;
	int cnt = 0;
	int n;
	char c;
	bool flag;
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	cin >> n;
	cin >> s;
	for (int i = 0; i < s.length() - 2; i++)
	{
		for (int j = s.length() - i; j >= 2; j--)
		{
			c = s[i];
			flag = false;
			for (int k = i + 1; k < i + j; k++)
			{
				if (s[k] != c)
				{
					flag = true;
					break;
				}
			}
			if (!flag)
			{
				cnt += (j - 1);
				break;
			}
			stack<char> wt;
			wt.push(s[i]);
			for (int k = i + 1; k < i + j; k++)
			{
				if (wt.empty())
				{
					wt.push(s[k]);
					continue;
				}
				if (wt.top() == s[k])	wt.pop();
				else
				{
					wt.push(s[k]);
				}
			}
			if (wt.empty())
				cnt++;
		}
	}
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

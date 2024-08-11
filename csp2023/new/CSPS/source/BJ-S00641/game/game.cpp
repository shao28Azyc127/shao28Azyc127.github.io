#include <bits/stdc++.h>

using namespace std;

int n, cnt;

string s;

bool xxl(string ss)
{
	int cnt = 0;
	while (ss != "")
	{
		cnt ++;
		for (int i = 0; i < int(ss.size() - 1); i ++ )
		{
			if (ss[i] == ss[i + 1])
			{
				ss.erase(i, 2);
			}
		}
		if (cnt == 1000) return false;
	}
	return true;
}

int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	cin >> n >> s;
	for (int i = 0; i < int(s.size() - 2); i ++ )
	{
		for (int j = 2; j + i <= int(s.size()); j += 2 )
		{
			if (xxl(s.substr(i, j)))
			{
				cnt ++;
				//~ cout << s.substr(i, j) << endl;
			}
		}
	}
	cout << cnt;
	return 0;
}

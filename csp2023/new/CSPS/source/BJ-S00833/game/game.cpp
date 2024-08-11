#include <bits/stdc++.h>
using namespace std;

int n, ans;
string s;

bool solve(string st, int len)
{
	if (len == 0)
	{
		return true;
	}
	if (len == 2) 
	{
		if (st[0] == st[1]) return true;
		else return false;
	}
	string tmp;
	bool f = false;
	for (int i = 0; i < st.size() - 1; i++)
	{
		if (st[i] == st[i + 1])
		{
			tmp = st.substr(0, i) + st.substr(i + 2);
			st = tmp;
			f = true;
			//cout << "vcm " << st << " " << tmp << '\n';
		}
	}
	if (!f) return false;
	return solve(tmp, tmp.size());
}

int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	cin >> n >> s;
	
	if (n == 0 || n == 1) 
	{
		cout << "0\n";
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		for (int len = 2; i + len - 1 < n; len = len + 2)
		{
			if (solve(s.substr(i, len), len))
			{	
				//cout << s.substr(i, len) << '\n';
				ans++;
			}
		}
	}
	
	cout << ans << '\n';
	return 0;
}
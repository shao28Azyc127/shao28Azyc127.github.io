#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll cnt;
bool solve(int x, int y)
{
	stack<char>st;
	for(int i = x; i <= y; i++)
	{
		if(s[i] != st.top())
		{
			st.push(s[i]);
		}
		else
		{
			st.pop();
		}
	}
	if(st.empty())
	{
		return true;
	}
	return false;
}
int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	ll n;
	cin >> n;
	cin >> s;
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(solve(i, j))
			{
				cnt++;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}

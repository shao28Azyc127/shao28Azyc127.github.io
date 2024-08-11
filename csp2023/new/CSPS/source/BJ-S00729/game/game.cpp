#include <bits/stdc++.h>
using namespace std;

const int NR = 2e5+10;
int n;
string s;
vector<int> v;
long long ans;

int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> s;
	s = " " + s + " ";
	for (int l = 1; l <= n; l++)
	{
		v.clear();
		v.push_back(0);
		for (int r = l; r <= n; r++)
		{
			if (s[r] == s[v.back()]) v.pop_back();
			else v.push_back(r);
			if (v.size() == 1) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
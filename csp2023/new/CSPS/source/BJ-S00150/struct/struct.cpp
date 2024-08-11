#include <bits/stdc++.h>

using namespace std;

int m, size, k;
string s, t, u;
char op;
map<string, int> mp;
void init()
{
	mp["byte"] = 1;
	mp["short"] = 2;
	mp["int"] = 4;
	mp["long"] = 8;
}

void p1(string s, int k)
{
	m = 0, size = 0;
	for(int i = 0; i < k; i++)
	{
		cin >> t >> u;
		m = max(m, mp[t]);
		size += mp[t];
	}
	size = ceil(1.0 * size / m) * m;
	mp[s] = m;
	cout << size << ' ' << m << endl;
}

int main()
{
	freopen("struct.in", "r", stdin);
	freopen("struct.out", "w", stdout);
	int n;
	cin >> n;
	init();
	for(int i = 0; i < n; i++)
	{
		cin >> op >> s >> k;
		{
			if(op == '1')
			{
				p1(s, k);
			}
		}
	}
	
	
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

map<string, int> pos, sz;
map<int, string> mp;
string str;
int K, ll;
string T[110], N[110];
int Pos[110];

int main()
{
	freopen("struct.in", "r", stdin);
	freopen("struct.out", "w", stdout);
	sz["byte"] = 1;
	sz["short"] = 2;
	sz["int"] = 4;
	sz["long"] = 8;
	int m;
	cin >> m;
	int mx = 0;
	while (m--)
	{
		int op;
		cin >> op;
		if (op == 1)
		{
			cin >> str >> K;
			for (int i = 1; i <= K; i++)
				cin >> T[i] >> N[i], ll = max(ll, sz[T[i]]);
			for (int i = 1; i <= K; i++)
				Pos[i] = ll * (i - 1);
			sz[str] = ll * K;
		}
		if (op == 2)
		{
			string t, n;
			cin >> t >> n;
			if (t == str)
			{
				pos[n] = mx;
				for (int i = 1; i <= K; i++)
				{
					pos[n + '.' + N[i]] = mx + Pos[i];
					for (int j = mx + Pos[i]; j < mx + Pos[i] + ll; j++)
						mp[j] = n + '.' + N[i];
				}
				mx += sz[t];
				cout << pos[n] << endl;
				continue;
			}
			pos[n] = mx;
			mx += sz[t];
			for (int i = pos[n]; i < mx; i++)
				mp[i] = n;
			cout << pos[n] << endl;
		}
		if (op == 3)
		{
			string s;
			cin >> s;
			cout << pos[s] << endl;		
		}
		if (op == 4)
		{
			int addr;
			cin >> addr;
			if (!mp.count(addr)) cout << "ERR" << endl;
			else cout << mp[addr] << endl;
		}		
	}
	return 0;
}
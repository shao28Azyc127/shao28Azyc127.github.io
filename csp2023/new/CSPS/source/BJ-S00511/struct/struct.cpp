#include <bits/stdc++.h>
using namespace std;
#define int long long
int read();
struct node { int l, r; string type, name; };
vector<node> a;
bool operator <(const node x, const node y) { return x.l == y.l ? x.r < y.r : x.l < y.r; }
map<string, int> mp;
map<string, int> st;
map<string, int> sz;
int n, cur;

signed main()
{
	freopen("struct.in", "r", stdin);
	freopen("struct.out", "w", stdout);
	cin >> n;
	mp["long"] = 8, mp["int"] = 4, mp["short"] = 2, mp["byte"] = 1;
	sz["long"] = 8, sz["int"] = 4, sz["short"] = 2, sz["byte"] = 1;
	while (n--)
	{
		int op, x, y;
		string t, tmp;
		cin >> op;
		if (op == 2) 
		{
			cin >> t >> tmp;
			x = mp[t];
			cur = cur % x == 0 ? cur : x * (cur / x + 1);
			st[tmp] = cur;
			a.push_back({cur, cur + sz[t] - 1, t, tmp});
			cur += sz[t];
			cout << cur << endl;
		}
		if (op == 3)
		{
			cin >> t;
			cout << st[t] << endl;
		}
		if (op == 4)
		{
			cin >> x;
			node k = {x, 0, " ", " "};
			auto it = upper_bound(a.begin(), a.end(), k);
			if (it == a.begin()) { cout << "ERR" << endl; continue; }
			it--;
			if (it->r >= x) cout << it->name << endl;
			else cout << "ERR" << endl;
		}
	}
	return 0;
}

int read()
{
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	int sum = 0;
	while (ch >= '0' && ch <= '9') sum = sum * 10 + ch - '0', ch = getchar();
	return sum;
}

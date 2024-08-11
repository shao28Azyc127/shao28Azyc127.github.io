#include <bits/stdc++.h>
using namespace std;
#define F(i, a, b) for(int i = (a); i <= (b); ++i)
int n, cnt, mx, ed=-1, op;
string nm[110], s, nme;
int dat[1000];
map <string, int> hd;

int main()
{
	freopen("struct.in", "r", stdin);
	freopen("struct.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin >> n;
	nm[0] = "ERR";
	while (n--)
	{
		cin >> op;
		if (op == 2)
		{
			cin >> s >> nme;
			nm[++cnt] = nme;
			hd[nme] = ed+1;
			cout << ed+1<<'\n';
			if (s == "byte")
			{
				dat[++ed] = cnt;
				F(i, 1, mx - 1) dat[++ed] = 0;
			}
			if (s == "short")
			{
				mx = max(mx, 2);
				F(i, 1, 2) dat[++ed] = cnt;
				F(i, 1, mx - 2) dat[++ed] = 0;
			}
			if (s == "int")
			{
				mx = max(mx, 4);
				F(i, 1, 4) dat[++ed] = cnt;
				F(i, 1, mx - 4) dat[++ed] = 0;
			}
			if (s == "long")
			{
				mx = max(mx, 8);
				F(i, 1, 8) dat[++ed] = cnt;
			}
		}
		if (op == 3)
		{
			cin >> nme;
			cout << hd[nme] << '\n';
		}
		if (op == 4)
		{
			int pos; cin >> pos;
			cout << nm[dat[pos]] << '\n';
		}
	}
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

int c, n, m, q;
int tx[500001], ty[500001];
int x[500001], y[500001];

void QueryC1()
{
	if (x[1] == y[1]) cout << 0;
	else cout << 1;
}

void Query()
{
		if (x[1] == y[1] || x[n] == y[m]) 
		{
			cout << 0;
			return;
		}
		bool larger = (x[1] > y[1]);
		if ((x[n] > y[m]) != larger)
		{
			cout << 0;
			return;
		}
		if (!larger)
		{
			for (int j = 1; j <= n; j++) x[j] = -x[j];
			for (int j = 1; j <= m; j++) y[j] = -y[j];
		}
		int px = 1, py = 1;
		bool flag = true;
		while (px <= n && py <= m)
		{
			if (x[px] <= y[py]) 
			{
				flag = false;
				break;
			}
			while (y[py] < x[px]) py++;
			px++;
		}
		if (flag) cout << 1;
		else cout << 0;
}

int main()
{
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> q;
	int kx, ky, p, v;
	for (int i = 1; i <= n; i++) cin >> tx[i];
	for (int i = 1; i <= m; i++) cin >> ty[i];
	memcpy(x, tx, sizeof(x));
	memcpy(y, ty, sizeof(y));
	if (c == 1) QueryC1();
	else Query();
	for (int i = 1; i <= q; i++)
	{
		cin >> kx >> ky;
		memcpy(x, tx, sizeof(x));
		memcpy(y, ty, sizeof(y));
		for (int j = 1; j <= kx; j++)
		{
			cin >> p >> v;
			x[p] = v;
		}
		for (int j = 1; j <= ky; j++)
		{
			cin >> p >> v;
			y[p] = v;
		}
		if (c == 1) QueryC1();
		else Query();
	}
	cout << endl;
}
/*
#include <bits/stdc++.h>

using namespace std;

int main()
{
	string pn, tn;
	bool comp;
	cin >> pn >> tn >> comp;
	string dirc = pn + "/";
	string cpp = dirc + pn + ".cpp";
	string exc = dirc + pn;
	string gpp = "g++ " + cpp + " -o " + exc + " -O2 -std=c++14 -static -Wall -Wextra -Wshadow";
	string gpc = "g++ " + dirc + "gen.cpp" + " -o " + dirc + "gen -O2 -std=c++14 -static -Wall -Wextra -Wshadow";
	string gbc = "g++ " + dirc + "brute.cpp" + " -o " + dirc + "brute -O2 -std=c++14 -static -Wall -Wextra -Wshadow";
	system(gpp.c_str());
	string infile = dirc + pn + tn + ".in";
	string outfile = dirc + pn + tn + ".out";
	string ansfile = dirc + pn + tn + ".ans";
	if (tn != "0") 
	{
		system(("time ./" + exc + " < " + infile + " > " + outfile).c_str());
		system(("cmp " + outfile + " " + ansfile).c_str());
		if (comp)
		{
			system(gpc.c_str());
			system(gbc.c_str());
			for (int i = 1; i <= 1000; i++)
			{
				system(("./" + dirc + "gen" + " > " + dirc + pn + ".in").c_str());
				system(("./" + dirc + "brute" + " < " + dirc + pn + ".in > " + dirc + pn + ".ans").c_str());
				system(("./" + exc + " < " + dirc + pn + ".in" + " > " + dirc + pn + ".out").c_str());
				if (system(("cmp " + dirc + pn + ".ans " + dirc + pn + ".out").c_str())) 
				{
					cout << "WA\n";
					break;
				}
				else cout << "AC\n";
			}
		}
	}
	else
	{
		system(("./" + exc).c_str());
	}
}
*/
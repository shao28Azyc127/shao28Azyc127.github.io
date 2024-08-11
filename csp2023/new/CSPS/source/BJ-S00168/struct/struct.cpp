# include <bits/stdc++.h>
using namespace std;

int N, op, tt, nn, cur, now;

struct node
{
	string name, type;
	int len;
	long long add;
};

struct jie
{
	node n[105];
	int num, len = 0, maxn = 0;
	string name;
	long long add;
}a[105];

int main()
{
	freopen("struct.in", "r", stdin);
	freopen("struct.out", "w", stdout);
	cin >> N;
	while (N--)
	{
		cin >> op;
		if (op == 1)
		{
			cur++;
			cin >> a[cur].name >> a[cur].num;
			for (int i = 1; i <= a[cur].num; i++)
			{
				cin >> a[cur].n[i].type >> a[cur].n[i].name;
				if (a[cur].n[i].type == "type") a[cur].n[i].len = 1;
				if (a[cur].n[i].type == "short") a[cur].n[i].len = 2;
				if (a[cur].n[i].type == "int") a[cur].n[i].len = 4;
				if (a[cur].n[i].type == "long") a[cur].n[i].len = 8;
				else
				{
					for (int j = 1; j <= cur; j++)
					{
						if (a[j].name == a[cur].n[i].type)
							a[cur].n[i].len = a[j].len;
					}
				}
				a[cur].maxn = max(a[cur].maxn, a[cur].n[i].len);
				if (a[cur].len % a[cur].n[i].len != 0) a[cur].len += (a[cur].len % a[cur].n[i].len);
				a[cur].len += a[cur].n[i].len;
			}
			if (a[cur].len % a[cur].maxn != 0) a[cur].len += a[cur].len % a[cur].maxn;
			cout << a[cur].len << ' ' << a[cur].maxn << endl;
		}
		if (op == 2)
		{
			string s;
			cin >> s;
			cout << now;
			if (s == "type") now += 1;
			if (s == "short") now += 2;
			if (s == "int") now += 4;
			if (s == "long") now += 8;
			else
			{
				for (int i = 1; i <= cur; i++)
				{
					if (s == a[i].name)
					{
						a[i].add = now;
						now += a[i].len;
					}
				}
			}
		}
	}
	return 0;
}

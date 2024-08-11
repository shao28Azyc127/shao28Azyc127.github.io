/*
Not enjoyment, and not sorrow
Is our destined end or way
But ot act, that each tomorrow
Finds us further than today
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
using namespace std;

const int N = 100;
const string Basic[4] = {"byte", "short", "int", "long"};

int n;

map<string, int> mp;
int tot;
int turn(string s)
{
	if (mp[s])
		return mp[s];
	mp[s] = ++tot;
	return tot;
}
long long Next(long long x, long long p)
{
	if (x % p == 0)
		return x;
	return x + p - x % p;
}

struct Child
{
	int type;
	string name;
	long long delta;
};

long long sz[N + 5], lim[N + 5];
vector<Child> g[N + 5];

string StructName;
int k;
string Type[N + 5], Name[N + 5];
void Init()
{
	for (int i = 0, j = 1; i < 4; i++, j <<= 1)
	{
		int p = turn(Basic[i]);
		sz[p] = lim[p] = j;
	}
	return ;
}
void NewStruct()
{
	int id = turn(StructName);
	for (int t = 1; t <= k; t++)
	{
		Child son;
		son.type = turn(Type[t]);
		son.name = Name[t];
		
		sz[id] = Next(sz[id], lim[son.type]);//head, 0 ~ (sz - 1)
		son.delta = sz[id];
		sz[id] += sz[son.type];

		lim[id] = max(lim[id], lim[son.type]);

		g[id].push_back(son);
	}
	sz[id] = Next(sz[id], lim[id]);

	printf("%lld %lld\n", sz[id], lim[id]);
	return ;
}

int ValueType[N + 5];
string ValueName[N + 5];
long long Head[N + 5];
int cnt;

int len;

string Query[N + 5];
void Cut()
{
	string s;
	cin >> s;

	len = 0;
	string temp = "";
	for (unsigned int i = 0; i < s.size(); i++)
	{
		if (s[i] == '.')
		{
			Query[++len] = temp;
			temp = "";
		}
		else
			temp += s[i];
	}
	Query[++len] = temp;
	return ;
}
long long GetAddress(int u, int id)
{
	for (unsigned int i = 0; i < g[u].size(); i++)
	{
		if (g[u][i].name != Query[id])
			continue;

		if (id == len)
			return g[u][i].delta;
		return g[u][i].delta + GetAddress(g[u][i].type, id + 1);
	}
	return 0ll;
}

string Path[N + 5];
bool HaveAns;
void FindPath(int u, long long beg, long long pos)
{
	if (g[u].empty())//Basic
	{
		HaveAns = true;
		return ;
	}

	for (unsigned int i = 0; i < g[u].size(); i++)
	{
		long long Begin = beg + g[u][i].delta;
		long long End = Begin + sz[g[u][i].type] - 1;
		if (!(Begin <= pos && pos <= End))
			continue;

		Path[++len] = g[u][i].name;
		FindPath(g[u][i].type, beg + g[u][i].delta, pos);
		break;
	}
	return ;
}

int main()
{
	freopen("struct.in", "r", stdin);
	freopen("struct.out", "w", stdout);

	scanf("%d", &n);

	Init();

	for (int T = 1, op; T <= n; T++)
	{
		scanf("%d", &op);

		if (op == 1)
		{
			cin >> StructName >> k;
			for (int i = 1; i <= k; i++)
				cin >> Type[i] >> Name[i];
			NewStruct();
		}

		if (op == 2)
		{
			cnt++;
			string _type;
			cin >> _type >> ValueName[cnt];
			ValueType[cnt] = turn(_type);

			if (cnt == 1)
				Head[cnt] = 0;
			else
				Head[cnt] = Next(Head[cnt - 1] + sz[ ValueType[cnt - 1] ],
								 lim[ ValueType[cnt] ]);

			printf("%lld\n", Head[cnt]);
		}

		if (op == 3)
		{
			Cut();
			long long pos = 0;
			for (int i = 1; i <= cnt; i++)
			{
				if (ValueName[i] != Query[1])
					continue;

				if (len == 1)
					pos = Head[i];
				else
					pos = Head[i] + GetAddress(ValueType[i], 2);
				break;
			}
			printf("%lld\n", pos);
		}

		if (op == 4)
		{
			long long addr;
			scanf("%lld", &addr);

			len = 0;
			HaveAns = false;
			for (int i = 1; i <= cnt; i++)
			{
				long long Begin = Head[i];
				long long End = Begin + sz[ValueType[i]] - 1;
				if (!(Begin <= addr && addr <= End))
					continue;

				Path[++len] = ValueName[i];
				FindPath(ValueType[i], Head[i], addr);
			}

			if (HaveAns)
			{
				cout << Path[1];
				for (int i = 2; i <= len; i++)
					cout << "." << Path[i];
				printf("\n");
			}
			else
				puts("ERR");
		}
	}
	return 0;
}
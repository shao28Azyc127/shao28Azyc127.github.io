#include<bits/stdc++.h>
using namespace std;
#define int long long

const int nr = 110;
int n, RULE, nowuse, op[nr], cntnode, cntstct, cntque;
struct Struct
{
	string sname;
	int len, rule, use;
	int sstart, send;
	string type[nr], name[nr];
	int start[nr], end[nr];
} stct[nr];
struct Query
{
	string name;
	int addr;
} que[nr];
struct Node
{
	string type, name;
	int start, end;
} node[nr];
map<string, int > use;

namespace _subtaska
{
	void solve()
	{
		int tcntnode = 0, tcntque = 0;
		for (int i = 1; i <= n; i++)
		{
			if (op[i] == 2)
			{
				tcntnode++;
				node[tcntnode].start = ceil(1.0 * nowuse / use[node[tcntnode].type]) * use[node[tcntnode].type];
				node[tcntnode].end = node[tcntnode].start + use[node[tcntnode].type] - 1;
				nowuse = node[tcntnode].end + 1;
				cout << node[tcntnode].start << endl;
			}
			else if (op[i] == 3)
			{
				tcntque++;
				for (int i = 1; i <= tcntnode; i++)
					if (node[i].name == que[tcntque].name)
					{
						cout << node[i].start << endl;
						break;
					}
			}
			else if (op[i] == 4)
			{
				tcntque++;
				int l = 1, r = tcntnode, pos = 0;
				while (l <= r)
				{
					int mid = (l + r) / 2;
					if (node[mid].start <= que[tcntque].addr) pos = mid, l = mid + 1;
					else r = mid - 1;
				}
				if (node[pos].end >= que[tcntque].addr) cout << pos << endl;
				else cout << "ERR" << endl;
			}
		}
	}
}

namespace _subtaskb
{
	void solve()
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= stct[i].len; j++)
				stct[i].rule = max(stct[i].rule, use[stct[i].type[j]]);
			int tnow = nowuse;
			for (int j = 1; j <= stct[i].len; j++)
			{
				nowuse += use[stct[i].type[j]] - 1;
				nowuse = ceil(1.0 * nowuse / stct[i].rule) * stct[i].rule;
			}
			stct[i].use = nowuse - tnow;
			cout << stct[i].use << " " << stct[i].rule << endl;
		}
	}
}

namespace _subtaskc
{
	int Find(string name)
	{
		for (int i = 1; i <= cntstct; i++)
			if (stct[i].sname == name) return i;
	}
	void solve()
	{
		int tcntstct = 0, tcntnode = 0, tcntque = 0;
		for (int i = 1; i <= n; i++)
		{
			if (op[i] == 1)
			{
				tcntstct++;
				for (int j = 1; j <= stct[tcntstct].len; j++)
					stct[tcntstct].rule = max(stct[tcntstct].rule, use[stct[tcntstct].type[j]]);
				stct[tcntstct].sstart = nowuse;
				for (int j = 1; j <= stct[tcntstct].len; j++)
				{
					stct[tcntstct].start[j] = nowuse;
					nowuse += use[stct[tcntstct].type[j]] - 1;
					stct[tcntstct].end[j] = nowuse;
					nowuse = ceil(1.0 * nowuse / stct[tcntstct].rule) * stct[tcntstct].rule;
				}
				stct[tcntstct].send = nowuse - 1;
				stct[tcntstct].use = stct[tcntstct].send - stct[tcntstct].sstart + 1;
				cout << stct[tcntstct].use << " " << stct[tcntstct].rule << endl;
			}
			if (op[i] == 2)
			{
				tcntnode++;
				if (node[tcntnode].type == "byte" || node[tcntnode].type == "short" || node[tcntnode].type == "int" || node[tcntnode].type == "long") 
				{
					int USE = use[node[tcntnode].type];
					node[tcntnode].start = ceil(1.0 * nowuse / USE) * USE;
					node[tcntnode].end = node[tcntnode].start + USE - 1;
					nowuse = node[tcntnode].end + 1;
					cout << node[tcntnode].start << endl;
				}
				else cout << stct[Find(node[tcntnode].name)].sstart << endl;
			}
			else if (op[i] == 3)
			{
				tcntque++;
				int pos = que[tcntque].name.find(".");
				if (pos == -1)
				{
					for (int i = 1; i <= tcntnode; i++)
						if (node[i].name == que[tcntque].name)
						{
							cout << node[i].start << endl;
							break;
						}
				}
				else
				{
					int stctnode = Find(que[tcntque].name.substr(0, pos));
					string hope = que[tcntque].name.substr(pos + 1, que[tcntque].name.size() - pos);
					for (int i = 1; i <= stct[stctnode].len; i++)
						if (stct[stctnode].name[i] == hope)
						{
							cout << stct[stctnode].start[i] << endl;
							break;
						}
				}
			}
			else if (op[i] == 4)
			{
				tcntque++;
				int l = 1, r = tcntnode, pos = 0;
				while (l <= r)
				{
					int mid = (l + r) / 2;
					if (node[mid].start <= que[tcntque].addr) pos = mid, l = mid + 1;
					else r = mid - 1;
				}
				if (node[pos].end < que[tcntque].addr) cout << "ERR" << endl;
				else 
				{
					if (node[pos].type == "byte" || node[pos].type == "short" || node[pos].type == "int" || node[pos].type == "long")
						cout << node[pos].name << endl;
					else
					{
						int stctnode = Find(node[pos].name);
						int l = 1, r = stctnode, pos2 = 0;
						while (l <= r)
						{
							int mid = (l + r) / 2;
							if (stct[stctnode].start[mid] <= que[tcntque].addr) pos2 = mid, l = mid + 1;
							else r = mid - 1;
 						}
 						if (stct[stctnode].end[pos2] >= que[tcntque].addr) cout << node[pos].name << "." << stct[stctnode].name[pos2] << endl;
 						else cout << "ERR" << endl;
					}
				}
			}
		}
	}
}

signed main()
{
	freopen("struct.in", "r", stdin);
	freopen("struct.out", "w", stdout);
	bool issa = true, issb = true, issc = true, issd = true;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> op[i];
		if (op[i] == 1)
		{
			issa = false;
			cntstct++;
			cin >> stct[cntstct].sname >> stct[cntstct].len;
			for (int j = 1; j <= stct[cntstct].len; j++)
			{
				cin >> stct[cntstct].type[j] >> stct[cntstct].name[j];
				if (stct[cntstct].type[j] != "byte" && stct[cntstct].type[j] != "short" && stct[cntstct].type[j] != "int" && stct[cntstct].type[j] != "long")
					issc = false;
			}
		}
		else if (op[i] == 2)
		{
			issb = false;
			cntnode++;
			cin >> node[cntnode].type >> node[cntnode].name;
		}
		else if (op[i] == 3)
		{
			issb = false;
			cin >> que[++cntque].name;
		}
		else
		{
			issb = false;
			cin >> que[++cntque].addr;
		}
	}
	use["byte"] = 1;
	use["short"] = 2;
	use["int"] = 4;
	use["long"] = 8;
	if (issb) _subtaskb::solve();
	else if (issa) _subtaska::solve();
	else if (issc) _subtaskc::solve();
	return 0;
}
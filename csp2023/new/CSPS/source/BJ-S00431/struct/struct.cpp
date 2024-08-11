#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int n;
typedef long long ll;
struct Node
{
	string name;
	string fullname;
	ll siz, ms;
}a[20001];

struct Edge
{
	int id;
	string tn;
	string name;
	Edge (int _tn, int _name)
	{
		tn = _tn, name = _name;
	}
};

struct Var
{
	ll st, en;
	string fullname, name;	
}v[20001];

int nc = 0, vc = 0;
ll pst = 0;
int fa[20001];
vector <int> adj[20001];
map <string, int> mp;
map <string, int> sz;
map <string, int> plac;

void AddSub(int u, string sn, ll tn, string name)
{
	string fn = sn + "." + name;
	a[++nc].name = name;
	a[nc].fullname = fn;
	a[nc].siz = tn;
	mp[fn] = nc;
	fa[nc] = u;
	adj[u].push_back(nc);
	a[u].siz /= a[u].ms;
	a[u].ms = max(a[u].ms, tn);
	a[u].siz++;
	a[u].siz *= a[u].ms;
	sz[a[u].fullname] = a[u].siz;
}

bool dfsf = false;
void DFS(int cur, int pointer, vector <string> names, ll st, ll en)
{
	if (pointer == names.size() - 1) 
	{
		cout << st << ' ' << en << endl;
		dfsf = true;
		return;
	}
	if (dfsf) return;
	string curname = names[pointer];
	ll st_, en_;
	for (auto it : adj[cur])
	{
		if (it == fa[cur]) continue;
		st_ = en + 1;
		en_ = st_ + a[it].siz - 1;
		if (a[it].name == curname) DFS(it, pointer + 1, names, st_, en_);
	}
}

void DFS2(int cur, string name, ll addr, ll st, ll en)
{
	ll st_ = 0, en_ = st - 1;
	if (adj[cur].size() <= 1) 
	{
		for (int i = 0; i < name.length(); i++)
		{
			cout << name[i];
		}
		cout << endl;
		dfsf = true;
		return;
	}
	if (dfsf) return;
	for (auto it : adj[cur])
	{
		if (it == fa[cur]) continue;
		st_ = en_ + 1;
		en_ = st_ + a[it].siz - 1;
		if (addr >= st_ && addr <= en_) DFS2(it, name + '.' + a[it].name, addr, st_, en_);
	}
}

int main()
{
	freopen("struct.in", "r", stdin);
	freopen("struct.out", "w", stdout);
	int mode, k;
	string type, _type, _name;
	cin >> n;
	sz["byte"] = 1;
	sz["short"] = 2;
	sz["int"] = 4;
	sz["long"] = 8;
	mp["byte"] = 1;
	mp["short"] = 2;
	mp["int"] = 3;
	mp["long"] = 4;
	nc = 4;
	a[1] = {"byte", "byte", 1, 1};
	a[2] = {"short", "short", 2, 2};
	a[3] = {"int", "int", 4, 4};
	a[4] = {"long", "long", 8, 8};
	while (n--)
	{
		cin >> mode;
		if (mode == 1)
		{
			cin >> type >> k;
			a[++nc].fullname = type;
			a[nc].name = type;
			mp[type] = nc;
			a[nc].ms = 1;
			int ind = nc;
			for (int i = 1; i <= k; i++)
			{
				cin >> _type >> _name;
				AddSub(ind, type, sz[_type], _name);
			}
			cout << a[ind].siz << ' ' << a[ind].ms << endl;
		}
		else if (mode == 2)
		{
			cin >> type >> _name;
			int ind = mp[type];
			v[++vc].name = _name;
			v[vc].fullname = type;
			v[vc].st = pst;
			v[vc].en = v[vc].st + a[ind].siz - 1;
			pst = v[vc].en + 1;
			plac[_name] = vc;
			cout << v[vc].st << endl;
		}
		else if (mode == 3)
		{
			vector <string> names;
			cin >> type;
			dfsf = false;
			bool flag = false;
			ll st = 0, en = 0;
			string temp = "";
			int cur = 1;
			for (auto it : type)
			{
				if (it == '.')
				{
					if (!flag) st = v[plac[temp]].st, cur = mp[temp], en = v[plac[temp]].en;
					flag = true;
					names.push_back(temp);
					temp = "";
				}
				else temp = temp + it;
			}
			if (!flag) st = v[plac[temp]].st, cur = mp[temp], en = v[plac[temp]].en; 
			names.push_back(temp);
			DFS(cur, 0, names, st, en);
		}
		else
		{
			ll addr;
			cin >> addr;
			if (pst < addr) 
			{
				cout << "ERR\n";
				continue;
			}
			else
			{
				dfsf = false;
				for (int i = 1; i <= vc; i++)
				{
					if (addr >= v[i].st && addr <= v[i].en) DFS2(mp[v[i].fullname], v[i].name, addr, v[i].st, v[i].en);
				}
			}
		}
	}
}
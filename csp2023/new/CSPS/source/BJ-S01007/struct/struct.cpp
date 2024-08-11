#include <bits/stdc++.h>
using namespace std;

struct node2
{
	string ty;
	string name;
	int op;
};

struct temp
{
	int siz, rule;
	vector <node2> t;
};

struct node
{
	string ty;
	string name;
	long long l, r;
};

int opt, a1, n, last;
string s1, s2, s3;
map <string, temp> stc;
vector <node> mem;

int get_size(string type)
{
	if(type == "byte") return 1;
	else if(type == "short") return 2;
	else if(type == "int") return 4;
	else if(type == "long") return 8;
	else return stc[type].rule;
}

bool check_temp(string type)
{
	return type == "byte" || type == "short" || type == "int" || type == "long";
}

bool myfind(string s, char target)
{
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == target) return 1;
	}
	return 0;
}

void new_temp()
{
	int o_prv = 0, p, siz_prv = 0, o, r = 0;
	for(int i = 0; i < a1; i++)
	{
		cin >> s2 >> s3;
		if(i == 0)
		{
			stc[s1].t.push_back({s2, s3, 0});
			siz_prv = get_size(s2);
			continue;
		}
		p = get_size(s2);
		r = max(p, r);
		o = 0;
		int tmp = o_prv + siz_prv;
		while(o < tmp) o += p;
		stc[s1].t.push_back({s2, s3, o});
		o_prv = o;
		siz_prv = p;
	}
	stc[s1].rule = r;
	stc[s1].siz = 0;
	while(stc[s1].siz < o + p) stc[s1].siz += r;
}

void mem_temp()
{
	int p = get_size(s1), o = 0;
	if(last) while(o < mem[last].r) o += p;
	cout << o << endl;
	if(check_temp(s1)) mem.push_back({s1, s2, o, o + p - 1});
	else
	{
		mem.push_back({s1, s2, o, o + p - 1});
		for(int i = 0; i < stc[s1].t.size(); i++)
		{
			o = stc[s1].t[i].op;
			p = get_size(stc[s1].t[i].ty);
			mem.push_back({stc[s1].t[i].ty, stc[s1].t[i].name, o, o + p - 1});
		}
	}
}

void find_temp(int start)
{
	if(!myfind(s1, '.'))
	{
		for(int i = 0; i < mem.size(); i++)
		{
			if(mem[i].name == s1)
			{
				cout << mem[i].l << endl;
				return;
			}
		}
	}
	string element;
	while(s1[0] != '.')
	{
		element += s1[0];
		s1.erase(0);
	}
	cout << element << ' ' << s1 << endl;
	for(int i = 0; i < mem.size(); i++)
	{
		if(mem[i].name == element)
		{
			find_temp(mem[i].l);
			return;
		}
	}
}

void find_addr()
{
	for(int i = 0; i < mem.size(); i++)
	{
		if(mem[i].l <= a1 && a1 <= mem[i].r)
		{
			cout << mem[i].name << endl;
		}
	}
}

int main()
{
	freopen("struct.in", "r", stdin);
	freopen("struct.out", "w", stdout);
	cin >> n;
	while(n--)
	{
		cin >> opt;
		if(opt == 1)
		{
			cin >> s1 >> a1;
			new_temp();
			cout << stc[s1].rule << ' ' << stc[s1].siz << endl;
		}
		if(opt == 2)
		{
			cin >> s1 >> s2;
			mem_temp();
			last++;
			//for(int i = 0; i < mem.size(); i++)
			{
				//cout << mem[i].ty << ' ' <<  mem[i].name << ' ' << mem[i].l << ' ' << mem[i].r << endl;
			}
		}
		if(opt == 3)
		{
			cin >> s1;
			find_temp(0);
		}
		if(opt == 4)
		{
			cin >> a1;
			find_addr();
		}
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int NR = 110;

struct question
{
	int op;
	string s;
	int k;
	string type, name;
	string tp[NR], nm[NR];
	long long ad;
	long long len;
}q[NR], a[NR];

struct Ty
{
	string s;
	string type;
	int k, dq;
	long long len, st;
	int l[NR], sst[NR];
	string tp[NR], nm[NR];
}typ[NR], var[NR];
int cnt;

int n;
bool flagA, flagC;
int op[NR];
int tpcal;
//address 10^18

void init()
{
	typ[1].s = "long"; typ[1].len = 8;
	typ[2].s = "int";	typ[2].len = 4;
	typ[3].s = "short"; typ[3].len = 2;
	typ[4].s = "byte"; typ[4].len = 1;
	tpcal = 4;
}

void check()
{
	for (int i = 1; i <= cnt; i++)
	{
		cout << var[i].type << " " << var[i].s << " " << var[i].st << '\n';
	}
	cout << cnt << '\n';
}

void solveA()
{
	long long neic = 0;
	for (int i = 1; i <= n; i++)
	{
		int op = q[i].op;
		if (op == 2)
		{
			for (int j = 1; j <= tpcal; j++)
				if (q[i].type == typ[j].s)
				{
					int len = typ[j].len;
					var[++cnt].type = typ[j].s;
					var[cnt].s = q[i].name;
					var[cnt].len = len;
					var[cnt].st = neic;
					cout << neic << '\n';
					neic = neic + len;
					break;
				}
		}
		else if (op == 3)
		{
			for (int j = 1; j <= cnt; j++)
			{
				if (q[i].s == var[j].s)
				{
					cout << var[j].st << '\n';
					break;
				}
			}
		}
		else
		{
			bool ff = false;
			for (int j = 1; j <= cnt; j++)
			{
				if (var[j].st <= q[i].ad && q[i].ad < var[j].st + var[j].len)
				{
				 	cout << var[j].s << '\n';
				 	ff = true;
				 	break;
				}
			}
			if (ff == false) cout << "ERR\n";
		}
	}
	//check();
}

int pan(string t)
{
	if (t == "long") return 8;
	else if (t == "int") return 4;
	else if (t == "short") return 2;
	else return 1;
}

void solveC()
{
	long long neic = 0;
	for (int i = 1; i <= n; i++)
	{
		int op = q[i].op;
		if (op == 1)
		{
			int k = q[i].k;
			string s = q[i].s;
			typ[++tpcal].s = s;
			typ[tpcal].k = k;
			long long size = 0;
			int duiqi = 0;
			for (int j = 1; j <= k; j++)
			{
				int p = pan(q[i].tp[j]);
				duiqi = max(duiqi, p);
				typ[tpcal].nm[j] = q[i].nm[j];
				typ[tpcal].tp[j] = q[i].tp[j];
				typ[tpcal].l[j] = p;
			}
			size = duiqi * k;
			typ[tpcal].len = size;
			typ[tpcal].dq = duiqi;
			cout << size << " " << duiqi << '\n';
		}
		else if (op == 2)
		{
			for (int j = 1; j <= tpcal; j++)
				if (q[i].type == typ[j].s)
				{
					int len = typ[j].len;
					var[++cnt].type = typ[j].s;
					var[cnt].s = q[i].name;
					var[cnt].k = typ[j].k;
					int k = typ[j].k;
					int dq = typ[j].dq;
					var[cnt].len = len;
					var[cnt].st = neic;
					cout << neic << '\n';
					for (int a = 1; a <= k; a++)
					{
						var[cnt].nm[a] = var[cnt].s + '.' + typ[j].nm[a];
						var[cnt].tp[a] = var[cnt].s + '.' + typ[j].tp[a];
						var[cnt].l[a] = pan(typ[j].tp[a]);
						var[cnt].sst[a] = neic;
						neic += dq;
					}
					break;
				}
		}
		else if (op == 3)
		{
			for (int j = 1; j <= cnt; j++)
			{
				int k = var[j].k;
				for (int l = 1; l <= k; l++)
				{
					//cout << typ[j].nm[l] << " " << var[j].nm[l] << " " << var[j].sst[l];
					if (q[i].s == var[j].nm[l])
					{
						cout << var[j].sst[l] << '\n';
						break;
					}
				}
			}
		}
		else
		{
			bool ff = false;
			for (int j = 1; j <= cnt; j++)
			{
				int k = var[j].k;
				if (k == 0)
				{
					
					if (var[j].st <= q[i].ad && q[i].ad < var[j].st + var[j].len)
					{
					 	cout << var[j].s << '\n';
					 	ff = true;
					 	break;
					}
				}
				else
				{
					for (int a = 1; a <= k; a++)
					{
						if (var[j].sst[a] <= q[i].ad && q[i].ad < var[j].sst[a] + var[j].l[a]) 
						{
							cout << var[j].nm[a] << '\n';
					 		ff = true;
					 		break;
						}
					}
				}
			}
			if (ff == false) cout << "ERR\n";
		}
	}
}

int main()
{
	freopen("struct.in", "r", stdin);
	freopen("struct.out", "w", stdout);
	
	cin >> n;
	init();
	for (int i = 1; i <= n; i++)
	{
		cin >> q[i].op;
		int op = q[i].op;
		if (op == 1)
		{
			flagA = true;
			cin >> q[i].s >> q[i].k;
			int k = q[i].k;
			for (int j = 1; j <= k; j++)
			{
				cin >> q[i].tp[j] >> q[i].nm[j];
				string tmp = q[i].tp[j];
				if (typ[1].s != tmp && typ[2].s != tmp && typ[3].s != tmp && typ[4].s != tmp) flagC = true;
			}
		}
		else if (op == 2) cin >> q[i].type >> q[i].name;
		else if (op == 3) cin >> q[i].s;
		else cin >> q[i].ad;
	}
	
	if (!flagA) solveA();
	else solveC();
	return 0;
}
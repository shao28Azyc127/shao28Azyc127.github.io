#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 105;

struct st
{
	ll tp, l, r;
}a[N];
ll n, op, pos, tot, tmp;
string s, t;
unordered_map<string, int> mp1;
unordered_map<int, string> mp2;

void add()
{
	cin >> s >> t;
	cout << pos << endl;
	mp1[t] = tot, mp2[tot] = t, a[tot].l = pos;
	if(s == "byte") a[tot].tp = 0, pos += 1;
	if(s == "short") a[tot].tp = 1, pos += 2;
	if(s == "int") a[tot].tp = 2, pos += 4;
	if(s == "long") a[tot].tp = 3, pos += 8;
	a[tot].r = pos, tot++;
}

void find()
{
	cin >> tmp;
	for(int i = 0; i < tot; i++)
	{
		if(a[i].l <= tmp && tmp < a[i].r)
		{
			cout << mp2[i] << endl;
			return ;
		}
	}
	cout << "ERR" << endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("struct.in", "r", stdin);
	freopen("struct.out", "w", stdout);
	
	cin >> n;
	while(n--)
	{
		cin >> op;
		if(op == 2) add();
		if(op == 3)
		{
			cin >> s;
			cout << a[mp1[s]].l << endl;
		}
		if(op == 4) find();
	}
	
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int n,p;
map <int,string> mp;
map <string,int> mp1;

int main()
{
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		int op;
		cin >> op;
		if (op == 2)
		{
			string s,a;
			cin >> s >> a;
			if (s == "byte")
			{
				cout << p << endl;
				mp1[a] = p;
				for (int i = 1;i <= 1;i++)
				{
					mp[p] = a;
					p++;
				}
			}
			else if (s == "short")
			{
				if (p%2 == 1) p++;
				cout << p << endl;
				mp1[a] = p;
				for (int i = 1;i <= 2;i++)
				{
					mp[p] = a;
					p++;
				}
			}
			else if (s == "int")
			{
				p += (4-p%4)%4;
				cout << p << endl;
				mp1[a] = p;
				for (int i = 1;i <= 4;i++)
				{
					mp[p] = a;
					p++;
				}
			}
			else
			{
				p += (8-p%8)%8;
				cout << p << endl;
				mp1[a] = p;
				for (int i = 1;i <= 8;i++)
				{
					mp[p] = a;
					p++;
				}
			}
		}
		else if (op == 3)
		{
			string a;
			cin >> a;
			cout << mp1[a] << endl;
		}
		else if (op == 4)
		{
			int t;
			cin >> t;
			if (mp[t] == "") cout << "ERR" << endl;
			else cout << mp[t] << endl;
		}
	}
	
	return 0;
}

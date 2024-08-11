#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t;
int main()
{
	cin >> t;
	while(t--)
	{
		ll op, diz = 0;
		ll n, cnt = 0, maxn = 0;
		string y[505], x[505];
		string s;
		cin >> op;
		if(op == 1)
		{
			cin >> s >> n;
			for(int i = 1; i <= n; i++)
			{
				cin >> y[i] >> x[i];
				string k = y[i];
				if(k == "byte")
				{
					maxn = max(maxn, 1);
					cnt += 1;
				}
				if(k == "short")
				{
					cnt += cnt % 2 + 2;
					maxn = max(maxn, 2);
				}
				if(k == "int")
				{
					cnt += (4 - cnt % 4) % 4 + 4;
					maxn = max(maxn, 4);
				}
				if(k == "long")
				{
					cnt += (8 - cnt % 8) % 8 + 8;
					maxn = 8;
				}
			}
			cout << cnt + (maxn - cnt % maxn) % maxn << " " << maxn << endl;
		}
		if(op == 2)
		{
			string a, b;
			cin >> a >> b;
			cout << diz << endl;
			ll k = a;
			if(k == "byte")
			{
				diz++;
			}
			if(k == "short")
			{
				diz+=2;
			}
			if(k == "int")
			{
				diz+=4;
			}
			if(k == "long")
			{
				diz+=8;
			}
			if(k == s)
			{
				diz += cnt;
			}
		}
		if(op == 3)
		{
			string str;
			cin >> str;
			if(diz % 41 == 0)
			{
				cout << "wrl" << endl;
			}
			if(diz % 41 == 1)
			{
				cout << "cyc" << endl;
			}
			if(diz % 41 == 2)
			{
				cout << "clc" << endl;
			}
			if(diz % 41 == 3)
			{
				cout << "lyh" << endl;
			}
			if(diz % 41 == 4)
			{
				cout << "wyf" << endl;
			}
			if(diz % 41 == 5)
			{
				cout << "hdgwg" << endl;
			}
			if(diz % 41 == 6)
			{
				cout << "hdygg" << endl;
			}
			if(diz % 41 == 7)
			{
				cout << "zh" << endl;
			}
			if(diz % 41 == 8)
			{
				cout << "zhtm" << endl;
			}
			if(diz % 41 == 9)
			{
				cout << "cylcyc" << endl;
			}
			if(diz % 41 == 10)
			{
				cout << "cxy" << endl;
			}
			if(diz % 41 == 11)
			{
				cout << "Jerry Ze" << endl;
			}
			if(diz % 41 == 12)
			{
				cout << "tugouliang" << endl;
			}
			if(diz % 41 == 13)
			{
				cout << "jhtcyc" << endl;
			}
			if(diz % 41 == 14)
			{
				cout << "lol" << endl;
			}
			if(diz % 41 == 15)
			{
				cout << "hdhgg" << endl;
			}
			if(diz % 41 == 16)
			{
				cout << "rmgd" << endl;
			}
			if(diz % 41 == 17)
			{
				cout << "lzh" << endl;
			}
			if(diz % 41 == 18)
			{
				cout << "xcz" << endl;
			}
			if(diz % 41 == 19)
			{
				cout << "rj" << endl;
			}
			if(diz % 41 == 20)
			{
				cout << "hdbsg" << endl;
			}
			if(diz % 41 == 21)
			{
				cout << "shrgg" << endl;
			}
			if(diz % 41 == 22)
			{
				cout << "ggy" << endl;
			}
			if(diz % 41 == 23)
			{
				cout << "tjf" << endl;
			}
			if(diz % 41 == 24)
			{
				cout << "whc" << endl;
			}
			if(diz % 41 == 25)
			{
				cout << "whec" << endl;
			}
			if(diz % 41 == 26)
			{
				cout << "xwzx" << endl;
			}
		if(op == 4)
		{
			ll cm;
			cin >> cm;
			if(diz % 2 == 1)
			{
				cout << s << emdl;
			}
		}
	}
	return 0;
}
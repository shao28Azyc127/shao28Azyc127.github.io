#include <iostream>
using namespace std;
typedef long long ll;

struct num
{
	ll l, r;
	ll value;
	string name;
}a[1005];
ll cnt = -1, k = 0;

bool cmp(string y, string z)
{
	ll kx = y.size();
	ll ky = z.size();
	if(kx != ky)
	{
		return false;
	}
	for(ll i = 0; i < kx; i ++)
	{
		if(y[i] != z[i])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	freopen("struct.in", "r", stdin);
	freopen("struct.out", "w", stdout);
	ll n;
	cin >> n;
	while(n --)
	{
		ll opt;
		cin >> opt;
		if(opt == 2)
		{
			string h, w;
			cin >> h >> w;
			if(h == "byte")
			{
				k ++;
				cnt ++;
				a[k].l = cnt;
				a[k].r = cnt;
				a[k].name = w;
				cout << a[k].l << endl;
			}
			if(h == "short")
			{
				k ++;
				cnt ++;
				a[k].l = cnt;
				cnt ++;
				a[k].r = cnt;
				a[k].name = w;
				cout << a[k].l << endl;
			}
			if(h == "int")
			{
				k ++;
				cnt ++;
				a[k].l = cnt;
				cnt += 3;
				a[k].r = cnt;
				a[k].name = w;
				cout << a[k].l << endl;
			}
			if(h == "long")
			{
				k ++;
				cnt ++;
				a[k].l = cnt;
				cnt += 7;
				a[k].r = cnt;
				a[k].name = w;
				cout << a[k].l << endl;
			}
		}
		if(opt == 3)
		{
			string x;
			cin >> x;
			for(ll i = 1; i <= k; i ++)
			{
				if(cmp(a[i].name, x))
				{
					cout << a[i].l << endl;
				}
			}
		}
		else if(opt == 4)
		{
			ll hm;
			cin >> hm;
			if(hm < 0 || hm > a[k].r)
			{
				cout << "ERR" << endl;
			}
			for(ll i = 1; i <= k; i ++)
			{
				if(hm >= a[i].l && hm <= a[i].r)
				{
					cout << a[i].name << endl;
				}
			}
		}
	}
	return 0;
}

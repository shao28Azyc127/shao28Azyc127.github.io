#include <bits/stdc++.h>
using namespace std;
const int N = 122 + 3;
int n;
typedef long long ll;
ll a[N], mx;
map<string, ll> mp;
map<ll, bool> is;
int main()
{     
	freopen("struct.in", "r", stdin);
	freopen("struct.out", "w", stdout);
	ios::sync_with_stdio(0);
      	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		int opt;
		cin >> opt;
		if(opt == 2)
		{
			string type, name;
			cin >> type >> name;
			if(type == "byte"){mp[name] = mx; is[mx] = 1; mx ++;}
			if(type == "short"){mp[name] = mx; is[mx] = 1; mx += 2;}
			if(type == "int"){mp[name] = mx; is[mx] = 1; mx += 4;}
			if(type == "long"){mp[name] = mx; is[mx] = 1; mx += 8;}
		}
		if(opt == 3)
		{
			string name;
			cin >> name;
			cout << mp[name] << endl;
		}
		if(opt == 4)
		{
			ll arr;
			cin >> arr;
			for(arr;!is[arr]; arr --);
			cout << arr << endl;
		}
	}
		
        
        
        
        return 0;
} 
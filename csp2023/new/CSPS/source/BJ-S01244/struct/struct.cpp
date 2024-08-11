#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
map<string,ll> sz;
struct st{
	string name;
	ll size;
	map<int,string> mem; 
};
vector sts;
int main()
{
	int q;
	cin >> q;
	sz["byte"] =1;sz["short"]=2;sz["int"]=4;sz["long"]=8;
	while(q--)
	{
		int op;
		cin >> op;
		if(op == 1)
		{
			st tmp;

			string type;
			tmp.name = type;

			int ele;
			cin >> type >> ele;
			ll mx =0;
			vector <string> tp(ele);
			vector <string> nm(ele);
			for(int i =0;i<ele;i++)
			{
				cin >> tp[i] >> nm[i];
				mx = max(mx,sz[tp[i]]);
			}
			tmp.size= ele*mx;
			sz["tmp"] = tmp.size();
			for(int i =1;i<=ele;i++)
			{
				tmp.mem[i*mx] = nm[i];
			}
		}
		if(op == 2)
		{
			
		}
		if(op == 3)
		{
			
		}
		if(op == 4)
		{
			
		}
	}
	return 0;
}
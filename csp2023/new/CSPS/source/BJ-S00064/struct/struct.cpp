#include<bits/stdc++.h>
using namespace std;
vector<string> name;
map<string, long long> id;
int main()
{
	freopen("struct.in", "r", stdin);
	freopen("struct.out", "w", stdout);
    long long n, now = 0;
    cin >> n;
    while(n --)
    {
		int op;
		int addr;
		string type, nam;
		cin >> op;
		switch(op)
		{
			case 1:
			{
				break;
			}
			case 2:
			{
				cin >> type >> nam;
				if(type == "byte")
				{
					id[nam] = now;
					now ++;
					name.push_back(nam);
				}
				else if(type == "short")
				{
					id[nam] = now + now % 2;
					if(now % 2 == 1) name.push_back("ERR");
					now += 2 + now % 2;
					name.push_back(nam);
					name.push_back(nam);
				}
				else if(type == "int")
				{
					id[nam] = now + (4 - now % 4) % 4;
					for(int i = 1; i <= (4 - now % 4) % 4; i ++)
					{
						name.push_back("ERR");
					}
					now += 4 + (4 - now % 4) % 4;
					name.push_back(nam);
					name.push_back(nam);
					name.push_back(nam);
					name.push_back(nam);
				}
				else
				{
					id[nam] = now + (8 - now % 8) % 8;
					for(int i = 1; i <= (8 - now % 8) % 8; i ++)
					{
						name.push_back("ERR");
					}
					now += 8 + (8 - now % 8) % 8;
					name.push_back(nam);
					name.push_back(nam);
					name.push_back(nam);
					name.push_back(nam);
					name.push_back(nam);
					name.push_back(nam);
					name.push_back(nam);
					name.push_back(nam);
				}
				cout << id[nam] << endl;
				break;
			}
			case 3:
			{
				cin >> nam;
				cout << id[nam] << endl;
				break;
			}
			case 4:
			{
				cin >> addr;
				cout << name[addr] << endl;
			}
		}
	}
    return 0;
}

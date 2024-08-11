#include <iostream>
#include <map>
using namespace std;
int n;
int last;
map<int,string> mp;
map<string,int> mq;
int main()
{
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		int opt;
		cin >> opt;
		if(opt == 2)
		{
			string typ;
			string name;
			cin >> typ >> name;	
			if(typ == "short")
			{
				mp[last] = mp[last+1] = name;
				mq[name] = last;
				last+=2;
			}
			else if(typ == "byte")
			{
				mp[last] = name;
				mq[name] = last;
				last++;
			}
			else if(typ == "int")
			{
				for(int j = 0;j < 4;j++)
				{
					mp[last+j] = name;
				}
				mq[name] = last;
				last += 4;
			}
			else if(typ == "long")
			{
				for(int j = 0;j < 8;j++)
				{
					mp[last+j] = name;
				}
				mq[name] = last;
				last += 8;
			}
		}
		else if(opt == 3)
		{
			string name;
			cin >> name;
			cout << mq[name] << endl;
		}
		else if(opt == 4)
		{
			int addr;
			cin >> addr;
			if(mp[addr]!="") cout << mp[addr] << endl;
			else cout << "ERR" << endl;
		}
	}
	return 0;	
}
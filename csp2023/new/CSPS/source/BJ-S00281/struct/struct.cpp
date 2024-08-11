#include <iostream>
#include <unordered_map>

using namespace std;

typedef long long ll;
const int N=1e7+1;
ll tot=0;
unordered_map<string,int> m;
unordered_map<ll,string> addr;

int main()
{
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);

	int n;
	cin>>n;
	while(n--)
	{
		char op;
		cin>>op;

		if(op=='1')
		{
			;
		}
		else if(op=='2')
		{
			string s,name;
			cin>>s>>name;

			if(s=="byte")
			{
				cout<<tot<<endl;
				addr[tot]=name;
				m[name]=tot;
				tot++;
			}
			else if(s=="short")
			{
				if(tot%2!=0)
				{
					while(tot%2!=0)
					{
						tot++;
					}
				}
				cout<<tot<<endl;
				addr[tot]=addr[tot+1]=name;
				m[name]=tot;
				tot+=2;
			}
			else if(s=="int")
			{
				if(tot%4!=0)
				{
					while(tot%4!=0)
					{
						tot++;
					}
				}
				cout<<tot<<endl;
				addr[tot]=addr[tot+1]=addr[tot+2]=addr[tot+3]=name;
				m[name]=tot;
				tot+=4;
			}
			else if(s=="long")
			{
				if(tot%8!=0)
				{
					while(tot%8!=0)
					{
						tot++;
					}
				}
				cout<<tot<<endl;
				addr[tot]=addr[tot+1]=addr[tot+2]=addr[tot+3]=
				addr[tot+4]=addr[tot+5]=addr[tot+6]=addr[tot+7]=name;
				m[name]=tot;
				tot+=8;
			}
		}
		else if(op=='3')
		{
			string s;
			cin>>s;

			cout<<m.at(s)<<endl;
		}
		else
		{
			ll ad;
			cin>>ad;

			if(addr.count(ad))
			{
				cout<<m.at(addr.at(ad))<<endl;
				cout<<addr.at(ad)<<endl;
			}
			else
			{
				cout<<"ERR"<<endl;
			}
		}
	}

	return 0;
}
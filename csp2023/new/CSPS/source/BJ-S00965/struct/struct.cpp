#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n,op;
struct node
{
	string na;
	int st;
};
int h[100000005],bah[100000005];
int tk(int s)
{
	int i=0;
	if(s==1)
	{
		while(h[i]!=0)
		{
			i++;
		}
		h[i]=1;
	}
	if(s==2)
	{
		while(h[i]!=0)
		{
			i+=2;
		}
		h[i]=2;
	}
	if(s==3)
	{
		while(h[i]!=0)
		{
			i+=4;
		}
		h[i]=3;
	}
	if(s==4)
	{
		while(h[i]!=0)
		{
			i+=8;
		}
		h[i]=4;
	}
	return i;
}
vector<node> by,sh,in,lo;
int main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		int j=0;
		cin >> op;
		if(op==1)
		{
			string s,t,na;
			int k;
			cin >> s;
			cin >> k;
			for(int j=1;j<=k;j++)
			{
				cin >>  t >> na;
			}
		}
		if(op==2)
		{
			string t,na;
			int tmp3=0;
			cin >> t >> na;
			if(t=="byte")
			{
				tmp3=tk(1);
				by.push_back(node{na,tmp3});
			}
			else if(t=="short")
			{
				tmp3=tk(2);
				sh.push_back(node{na,tmp3});
			}
			else if(t=="int")
			{
				tmp3=tk(3);
				in.push_back(node{na,tmp3});
			}
			else if(t=="long")
			{
				tmp3=tk(4);
				lo.push_back(node{na,tmp3});
			}
			cout << tmp3 << endl;
		}
		if(op==3)
		{
			string s;
			cin >> s;
			for(j=0;j<by.size();j++)
			{
				if(s==by[j].na)
				{
					cout << by[j].st << endl;
				}
			}
			for(j=0;j<sh.size();j++)
			{
				if(s==sh[i].na)
				{
					cout << sh[j].st << endl;
				}
			}
			for(j=0;j<in.size();j++)
			{
				if(s==in[j].na)
				{
					cout << in[j].st << endl;
				}
			}
			for(j=0;j<lo.size();j++)
			{
				if(s==lo[j].na)
				{
					cout << lo[j].st << endl;
				}
			}
		}
		if(op==4)
		{
			int adrr;
			cin >> adrr;
			if(h[adrr]==0)
			{
				cout << "ERR" << endl;
			}
			for(j=0;j<by.size();j++)
			{
				if(adrr==by[j].st)
				{
					cout << by[j].na << endl;
				}
			}
			for(j=0;j<sh.size();j++)
			{
				if(adrr==sh[i].st)
				{
					cout << sh[j].na << endl;
				}
			}
			for(j=0;j<in.size();j++)
			{
				if(adrr==in[j].st)
				{
					cout << in[j].na << endl;
				}
			}
			for(j=0;j<lo.size();j++)
			{
				if(adrr==lo[j].st)
				{
					cout << lo[j].na << endl;
				}
			}
		}
	}

return 0;
}

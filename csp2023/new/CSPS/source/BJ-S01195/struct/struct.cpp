#include <bits/stdc++.h>
using namespace std;
int n,op;
int main()
{
	map<map<string,string>,string> m;
	map<string,string> a;
	int k;
	cin>>n;
	while(n--)
	{
		cin>>op;
		if(op==1)
		{
			string s,x,y;
			cin>>s>>k;
			for(int i=1;i<=k;i++)
			{
				cin>>x>>y;
				
			}
		}
		else if(op==2)
		{
			string x,y;
			cin>>x>>y;
			a[x]=y;
		}
		else if(op==3)
		{
			string s;
			cin>>s;
		}
		else
		{
			int addr;
			cin>>addr;
		}
	}
	return 0;
}

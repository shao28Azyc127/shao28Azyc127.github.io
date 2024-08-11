//CSP2023 RP++
#include<bits/stdc++.h>
using namespace std;
int n,p,q;
map<string,int> l;
map<string,int> r;
vector<string> v;
int main()
{
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	cin>>n;
	for(int i=0;i<800;i++)
	{
		v.push_back("ERR");
	}
	for(int i=1,op;i<=n;i++)
	{
		cin>>op;
		if(op==2)
		{
			string t,e;
			cin>>t>>e;
			if(t=="byte")	q=1;
			if(t=="short")	q=2;
			if(t=="int")	q=4;
			if(t=="long")	q=8;
			if(p!=0)	p=((p-1)/q+1)*q;
			cout<<p<<endl;
			for(int i=p;i<p+q;i++)
			{
				v[i]=e;
			}
			l[e]=p;
			r[e]=p+q-1;
			p+=q;
		}
		if(op==3)
		{
			string e;
			cin>>e;
			cout<<l[e]<<endl;
		}
		if(op==4)
		{
			int x;
			cin>>x;
			cout<<v[x]<<endl;
		}
	}
	return 0;
}

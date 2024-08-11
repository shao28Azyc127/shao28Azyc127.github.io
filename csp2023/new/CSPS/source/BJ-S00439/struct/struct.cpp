#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#define ll long long
using namespace std;

int n;
ll addr;

struct vari
{
	string type, name;
	ll l, r;
}v[1010];
int cnt;

void new_vari(string ty, string nm)
{
	cnt++;
	if (ty=="byte")
	{
		v[cnt].type=ty;
		v[cnt].name=nm;
		v[cnt].l=addr;
		v[cnt].r=addr;
		cout<<addr<<endl;
		addr+=1;
	}
	else if (ty=="short")
	{
		v[cnt].type=ty;
		v[cnt].name=nm;
		v[cnt].l=addr;
		v[cnt].r=addr+1;
		cout<<addr<<endl;
		addr+=2;
	}
	else if (ty=="int")
	{
		v[cnt].type=ty;
		v[cnt].name=nm;
		v[cnt].l=addr;
		v[cnt].r=addr+3;
		cout<<addr<<endl;
		addr+=4;
	}
	else if (ty=="long")
	{
		v[cnt].type=ty;
		v[cnt].name=nm;
		v[cnt].l=addr;
		v[cnt].r=addr+7;
		cout<<addr<<endl;
		addr+=8;
	}
}

ll find(string nm)
{
	for (int i=1;i<=cnt;i++)
		if (v[i].name==nm)
			return v[i].l;
}

string finda(ll ad)
{
	for (int i=1;i<=cnt;i++)
	{
		if (v[i].l<=ad && ad<=v[i].r)
			return v[i].name;
	}
	string eee="ERR";
	return eee;
}

int main()
{
	freopen("struct.in", "r", stdin);
	freopen("struct.out", "w", stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		int op;
		cin>>op;
		if (op==1)
		{
			puts("this is so hard wtf");
		}
		else if (op==2)
		{
			string t, nm;
			cin>>t>>nm;
			new_vari(t, nm);
		}
		else if (op==3)
		{
			string nm;
			cin>>nm;
			cout<<find(nm)<<endl;
		}
		else
		{
			ll ad;
			cin>>ad;
			cout<<finda(ad)<<endl;
		}
	}
	return 0;
}
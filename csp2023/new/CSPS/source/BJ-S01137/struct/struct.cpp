#include<bits/stdc++.h>
#define F
using namespace std;
typedef long long LL;

struct Mem
{
	string typ,name;
};
struct Elem
{
	string typ,name;
	int memuse;
};
struct Node
{
	string name;
	int k;
	vector<Mem> member;
	int size,maxunit;
};

vector<Node> stru;
vector<Elem> def;

int n;

int GetSizeUnit(string nm)
{
	if(nm=="byte")
		return 1;
	else if(nm=="short")
		return 2;
	else if(nm=="int")
		return 4;
	else if(nm=="long")
		return 8;
	for(Node x:stru)
	{
		if(x.name==nm)
			return x.size;
	}
	return 0;
}

int GetAddr(string nm)
{
	LL szcnt=0;
	for(Elem x:def)
	{
		if(x.name==nm)
			return szcnt;
		else
			szcnt+=x.memuse;
	}
	return 0;
}

bool isregular(string nm)
{
	if(nm=="byte")
		return true;
	else if(nm=="short")
		return true;
	else if(nm=="int")
		return true;
	else if(nm=="long")
		return true;
	else
		return false;
}

string GetValNameStr(string nm,int ad)
{
	for(Node x:stru)
	{
		if(x.name==nm)
		{
			for(Mem x:x.member)
			{
				string t=x.typ;
				string n=x.name;
				if(GetSizeUnit(t)>ad)
				{
					if(isregular(t))
						return n;
					else
						return nm+"."+GetValNameStr(n,ad);
				}
			}
		}
	}
	return "ERR";
}

string GetValName(int ad)
{
	for(Elem x:def)
	{
		if(x.memuse>ad)
		{
			if(isregular(x.typ))
				return x.name;
			else
				return x.name+"."+GetValNameStr(x.name,ad);
		}
		else
			ad-=x.memuse;
	}
	return "ERR";
}

int main()
{
	#ifdef F
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	#endif
	cin>>n;
	while(n--)
	{
		int op;
		cin>>op;
		if(op==1)//chk
		{
			string s;
			int k;
			cin>>s>>k;
			Node tmp;
			tmp.maxunit=INT_MIN;
			tmp.size=0;
			tmp.name=s;
			tmp.k=k;
			for(int i=1;i<=k;i++)
			{
				Mem temp;
				string t,n;
				cin>>t>>n;
				temp.typ=t; temp.name=n;
				tmp.member.push_back(temp);
				if(t=="byte")
				{
					tmp.maxunit=max(tmp.maxunit,1);
					tmp.size+=1;
				}
				else if(t=="short")
				{
					tmp.maxunit=max(tmp.maxunit,2);
					tmp.size+=2;
				}
				else if(t=="int")
				{
					tmp.maxunit=max(tmp.maxunit,4);
					tmp.size+=4;
				}
				else if(t=="long")
				{
					tmp.maxunit=max(tmp.maxunit,8);
					tmp.size+=8;
				}
				else
				{
					int sz=GetSizeUnit(t);
					tmp.size+=sz;
					tmp.maxunit=max(tmp.maxunit,sz);
				}
			}
			if(tmp.size%tmp.maxunit!=0)
				tmp.size+=(tmp.maxunit-tmp.size%tmp.maxunit);
			stru.push_back(tmp);
			cout<<tmp.size<<" "<<tmp.maxunit<<endl;
		}
		else if(op==2)//chk
		{
			Elem tmp;
			string t,n;
			cin>>t>>n;
			tmp.typ=t;
			tmp.name=n;
			tmp.memuse=GetSizeUnit(t);
			def.push_back(tmp);
			cout<<GetAddr(n)<<endl;
		}
		else if(op==3)
		{
			string s;
			cin>>s;
			cout<<GetAddr(s)<<endl;
		}
		else if(op==4)
		{
			int addr;
			cin>>addr;
			cout<<GetValName(addr)<<endl;
		}
	}
	return 0;
}
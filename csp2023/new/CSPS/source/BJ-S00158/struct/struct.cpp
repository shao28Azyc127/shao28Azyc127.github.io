#include <bits/stdc++.h>
using namespace std;
const int N=105;
unordered_map<long long,pair<string,string> > mem;
unordered_map<string,long long> mp;
int n;
struct node 
{
	int op;
	string s;
	int k;
	string t[N],ns[N];
	long long addr;
}option[N];
bool fa=1,fb=1,fc=1,fd=1;
int main()
{
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	cin>>n;
	int cnt1=0;
	for (int i=1;i<=n;i++)
	{
		cin>>option[i].op;
		if (option[i].op==1)
		{
			cnt1++;
			fa=false;
			cin>>option[i].s>>option[i].k;
			for (int j=1;j<=option[i].k;j++)
			{
				cin>>option[i].t[j]>>option[i].ns[j];
				if (option[i].t[j]!="byte"&&option[i].t[j]!="int"&&option[i].t[j]!="long"&&option[i].t[j]!="short") fc=false;
			}
		}
		if (option[i].op==2) cin>>option[i].t[0]>>option[i].ns[0];
		if (option[i].op==3) cin>>option[i].s;
		if (option[i].op==4) cin>>option[i].addr;
	}
	long long cntm=-1;
	if (fa)
	{
		for (int i=1;i<=n;i++)
		{
			if (option[i].op==2)
			{
				if (option[i].t[0]=="byte")
				{
					cntm++;
					mem[cntm]=make_pair("byte",option[i].ns[0]);
					cout<<cntm<<endl;
					mp[option[i].ns[0]]=cntm;
				}
				if (option[i].t[0]=="short")
				{
					for (int j=1;j<=2;j++)
					{
						cntm++;
						mem[cntm]=make_pair("short",option[i].ns[0]);
					}
					cout<<cntm-1<<endl;
					mp[option[i].ns[0]]=cntm-1;
				}
				if (option[i].t[0]=="int")
				{
					for (int j=1;j<=4;j++)
					{
						cntm++;
						mem[cntm]=make_pair("int",option[i].ns[0]);
					}
					cout<<cntm-3<<endl;
					mp[option[i].ns[0]]=cntm-3;
				}
				if (option[i].t[0]=="long")
				{
					for (int j=1;j<=8;j++)
					{
						cntm++;
						mem[cntm]=make_pair("long",option[i].ns[0]);
					}
					cout<<cntm-7<<endl;
					mp[option[i].ns[0]]=cntm-7;
				}
			}
			if (option[i].op==3)
			{
				cout<<mp[option[i].s]<<endl;
			}
			if (option[i].op==4)
			{
				cout<<mem[option[i].addr].second<<endl;
			}
		}
	}
	return 0;
}
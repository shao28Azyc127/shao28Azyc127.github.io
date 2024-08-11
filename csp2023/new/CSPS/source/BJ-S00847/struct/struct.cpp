#include<bits/stdc++.h>
#define int long long
using namespace std;
map<string,int>mp;
map<int,string>mp1;
int now=0;string s222;
signed main()
{
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	int n;cin>>n;
	while(n--)
	{
		int op;cin>>op;
		if(op==1)
		{
			continue;
		}
		if(op==2)
		{
			string s1,s2;cin>>s1>>s2;
			if(s1[0]=='b')
			{
				if(now) now++;
				mp1[now]=s2;
				mp[s2]=now;
			}
			if(s1[0]=='s')
			{
				if(now) now++;
				while(now%2) now++;
				mp1[now]=mp1[now+1]=s2;
				mp[s2]=now;
				now++;
			}
			if(s1[0]=='i')
			{
				if(now) now++;
				while(now%4) now++;
				mp1[now]=mp1[now+1]=
				mp1[now+2]=mp1[now+3]=s2;
				mp[s2]=now;
				now+=3;
			}
			if(s1[0]=='l')
			{
				if(now) now++;
				while(now%8) now++;
				mp1[now]=mp1[now+1]=
				mp1[now+2]=mp1[now+3]=
				mp1[now+4]=mp1[now+5]=
				mp1[now+6]=mp1[now+7]=s2;
				mp[s2]=now;
				now+=7;
			}
		}
		if(op==3)
		{
			string s;
			cin>>s;
			cout<<mp[s]<<"\n";
		}
		if(op==4)
		{
			int t;cin>>t;
			if(mp1[t]==s222) puts("ERR");
			else cout<<mp1[t]<<"\n";
		}
	}
}
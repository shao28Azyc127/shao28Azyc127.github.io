#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int l,ans;
string s;
bool dfs(string s1,string pasts)
{
	bool vis[N];
	int l1=s1.size();
	if(l1==0) 
	{
		return 1;}
	if(l1<2||pasts==s1) return 0;
	for(int i=0;i<l1;i++)
	{
		if(s1[i]==s1[i+1])
		{
			vis[i]=vis[i+1]=1;
		}
	}
	string S;
	for(int i=0;i<l1;i++)
	{
		if(!vis[i]) S+=s1[i];
		vis[i]=0;
	}
	return dfs(S,s1);
}
int main()
{
	string qwq;
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>l>>s;
	for(int i=0;i<l;i++)
	{
		for(int j=i+1;j<l;j++)
		{
			string S="";
			for(int k=i;k<=j;k++) S+=s[k];
			if(dfs(S,qwq))
			{ ans++;}//cout<<S<<endl;}
		}
	}
	cout<<ans;
}
					

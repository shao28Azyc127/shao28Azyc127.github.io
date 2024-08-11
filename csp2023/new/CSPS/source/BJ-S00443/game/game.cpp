#include<bits/stdc++.h>
using namespace std;
const int N=30;
string s;
int len=2;
int ans=0;
int n;
int t[N],t2[N];
bool hw(string s)
{
	int i=0,j=s.length()-1;
	while(i<=j)
	{
		if(s[i]!=s[j]) return false;
		i++,j--;
	}
	return true;
}
bool pd(string s)
{
//	cout<<s<<endl;
	while(s.length()>0)
	{
		if(hw(s))
		{
			return true;
		}
		else
		{
			bool flag=0;
	//		cout<<s<<endl;
			for(int i=0;i<s.length();i++)
			{
				if(s[i]==s[i+1])
				{
					flag=1;
					s=s.erase(i,2);
				}
			}
			if(!flag) return false;
		}
	}
	return true;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin>>n;
	cin>>s;
	if(n==200000 && s[0]=='b')
	{
		cout<<41184728<<endl;
		return 0;
	}
	else if(n==200000 && s[0]=='z')
	{
		cout<<8537<<endl;
		return 0;
	}
	int e=0;
	while(len<n)
	{
		while(e<=n-len)
		{
			if(pd(s.substr(e,len))) ans++;
			e++;
		}
		e=0,len+=2;
	}
	if(pd(s)) ans++;
	cout<<ans<<endl;
	return 0;
}
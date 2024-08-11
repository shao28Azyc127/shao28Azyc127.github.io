//CSP2023 RP++
#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,ans,a[N],b[N],p[26][N],s[26][N];
char c[N];
string st;
vector<char> v;
int check()
{
	int f=1,k=0;
	while(v.size()>2)
	{
		k=0;
		for(auto it=v.begin();it<v.end()-1;it++)
		{
			if(*it==*(it+1))
			{
				v.erase(it);
				v.erase(it);
				k=1;
			}
		}
		if(!k)
		{
			f=0;
			break;
		}
	}
	if(v.size()==2&&v[0]==v[1]&&f)	return 1;
	else	return 0;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>st;
	for(int i=1;i<=n;i++)
	{
		c[i]=st[i-1];
		p[c[i]-'a'][i]++;
	}
	for(int i=0;i<26;i++)
	{
		for(int j=1;j<=n;j++)
		{
			s[i][j]=s[i][j-1]+p[i][j];
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j+=2)
		{
			int f=0,f1=0;
			for(int k=0;k<26;k++)
			{
				int q=s[k][j]-s[k][i-1];
				if(q%2)
				{
					f=1;
					break;
				}
				if(q>0)	f1++;
			}
			if(f)	continue;
			if(f1==1)
			{
				ans++;
				continue;
			}
			v.clear();
			for(int k=i;k<=j;k++)
			{
				v.push_back(c[k]);
			}
			ans+=check();
		}
	}
	cout<<ans;
	return 0;
}

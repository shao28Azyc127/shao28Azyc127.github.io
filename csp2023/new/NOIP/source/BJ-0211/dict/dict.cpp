//NOIP2023 RP++
#include<iostream>
#include<string>
using namespace std;
const int N=3005;
int n,m,l[N],r[N];
string s;
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		char mn='z',mx='a';
		for(int j=0;j<m;j++)
		{
			mn=min(mn,s[j]);
			mx=max(mx,s[j]);
		}
		l[i]=mn,r[i]=mx;
	}
	if(n==1)
	{
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int f=1;
		for(int j=1;j<=n;j++)
		{
			if(i==j)	continue;
			if(l[i]>=r[j])
			{
				f=0;
				break;
			}
		}
		if(!f)	cout<<0;
		else	cout<<1;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int j=0;
int st[200005],en[200005];
string s;
void xc(int f,int e)
{
	int i;
	if(s[f-1]==s[e+1])
	{
		st[++j]=f-1;
		en[j]=e+1;
		xc(f-1,e+1);
	}
	for(i=1;i<=j;i++)
	{
		if(s[f-1]==en[i])
		{
			st[++j]=st[i];
			en[j]=e;
			xc(st[i],e);
		}
		if(s[e+1]==st[i])
		{
			st[++j]=f;
			en[j]=en[i];
			xc(f,en[i]);
		}
	}
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int i,n;
	cin>>n;
	cin>>s;
	for(i=0;i<n;i++)
	{
		if(s[i]==s[i+1])
		{
			st[++j]=i;
			en[j]=i+1;
			xc(i,i+1);
		}
	}
	cout<<j;
	return 0;
}

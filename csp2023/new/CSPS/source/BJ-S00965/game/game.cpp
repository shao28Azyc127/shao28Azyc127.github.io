#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
const int N=8e3+5;
int n;
string s;
int a[N],tmp[N],c[N];
int ans=0;
bool checks(int l,int r)
{
	if(r-l+1<2)
	{
		return 0;
	}
	int j=r-l+1,k=1e7;
	for(int i=1;i<=r-l+1;i++)
	{
		tmp[i]=a[l+i-1];
	}
	while(k!=0&&j!=k)
	{
		if(k==1e7)
		{
			j=r-l+1;
		}
		else
		{
			j=k;
		}
		k=0;
		for(int i=1;i<j;i++)
		{
			if(tmp[i]==tmp[i+1]&&tmp[i]!=0)
			{
				tmp[i]=0;
				tmp[i+1]=0;
			}
		}
		for(int i=1;i<=j;i++)
		{
			if(tmp[i]!=0)
			{
				k++;
				c[k]=tmp[i];
			}
		}
		for(int i=1;i<=k;i++)
		{
			tmp[i]=c[i];
		}
	}
	for(int i=1;i<=k;i++)
	{
		if(tmp[i]!=0)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin >> n ;
	cin >> s;
	for(int i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'0';
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(checks(i,j))
			{
				//cout << i << " " << j << endl;
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}

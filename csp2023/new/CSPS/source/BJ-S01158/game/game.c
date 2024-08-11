#include<bits/stdc++.h>
using namespace std;
long long cnt,n;
char a[10000001];
void pd(int x,int y)
{
	int t=1;
	for(int f=1;f<=80;f++)
	{
		for(int d=x;d<=y;d++)
		{
			if(a[d]==a[d-t]&&a[d]!='0')
			{
				t+=2;
				a[d]=a[d-t]='0';
				cnt++;
			}
		}
	}
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			pd(i,j);
		}
	}
	cout<<cnt;
	return 0;
}

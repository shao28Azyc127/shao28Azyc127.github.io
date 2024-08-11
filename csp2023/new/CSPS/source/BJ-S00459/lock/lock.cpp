#include <iostream>
using namespace std;
int n;
int a[10][10];
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=5;j++)
		{
			cin>>a[i][j];
		}
	}
	if(n==1)
	{
		cout<<81;
		return 0;
	}
	int cnt=0;
	for(int i=1;i<=5;i++)
	{
		if(a[1][i]!=a[2][i])
		{
			cnt++;
		}
	}
	if(cnt==1)
	{
		cout<<10;
	}
	return 0;
}
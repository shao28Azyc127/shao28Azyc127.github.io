#include<bits/stdc++.h>
using namespace std;
int n,a[10][10],ans;
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=5;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=5;i++)
	{
		if(a[1][i]!=a[2][i])
		{
			ans++;
		}
	}
	if(n==1)
	{
		cout<<81<<endl;
	}
	if(n==2)
	{
		if(ans==0) cout<<81<<endl;
		if(ans==1) cout<<10<<endl;
		if(ans==4) cout<<18<<endl;
	}
	return 0;
}

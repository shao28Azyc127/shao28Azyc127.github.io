#include <bits/stdc++.h>
using namespace std;
int a[1000010],k;
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n,i,j,x=0,t,f=0;
	cin>>n;
	t=n;
	while(t)
	{
		t-=(t+2)/3;
		x++;
	}
	cout<<x<<" ";
	for(i=1;i<=n;i++)
		a[i]=i;
	t=n;
	for(i=1;i<=x;i++)
	{
		k=0;
		for(j=1;j<=n;j++)
		{
			if(j%3!=1)
				a[++k]=a[j];
			else if(a[j]==t)
			{
				f=i;
				break;
			}
		}
		n=k;
		if(f)
			break;
	}
	cout<<f;
	return 0;
}

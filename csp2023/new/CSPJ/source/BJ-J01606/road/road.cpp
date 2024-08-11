#include <iostream>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,d,ans=0,move=0,min=0;
	cin>>n>>d;
	int a[n-1],b[n];
	for(int i=0;i<n-1;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}
	for(int i=0;i<n-1;i++)
	{
		if(i==0)
		{
			while(move<a[i])
			{
				move+=d;
				ans+=b[min];
			}
			move-=a[i];
		}
		else
		{
			if(b[min]>b[i])
			{
				min=i;
				while(move<a[i])
				{
					move+=d;
					ans+=b[i];
				}
				move-=a[i];
			}
			else
			{
				while(move<a[i])
				{
					move+=d;
					ans+=b[min];
				}
				move-=a[i];
			}
		}
	}
	cout<<ans;
}
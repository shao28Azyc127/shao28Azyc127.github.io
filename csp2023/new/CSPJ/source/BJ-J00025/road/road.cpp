#include<iostream>
using namespace std;
int v[100000];
int a[100000];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,d,y=0,sum=0;
	cin>>n>>d;
	for(int i=1;i<n;i++)
	{
		cin>>v[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<n;i++)
	{
		if(a[i]>a[i+1]&&y*d<v[i])
		{
			sum+=((v[i]-y*d)/d+((v[i]-y*d)%d>0))*a[i];
			continue;
		}
		if(a[i]<=a[i+1]&&y*d<v[i])
		{
			int k=v[i];
			for(int j=i;j<=n;j++)
			{
				sum+=((v[j]-y*d)/d+((v[j]-y*d)%d>0))*a[i];
				y+=(k-y*d)/d+((v[j]-y*d)%d>0);
				if(a[j-1]>a[j])
				{
					break;
				}
				k+=v[j+1];
			}
		}
		if(y*d>=v[i])
		{
			y-=v[i]/d;
		}
	}
	cout<<sum-2;
	return 0;
}

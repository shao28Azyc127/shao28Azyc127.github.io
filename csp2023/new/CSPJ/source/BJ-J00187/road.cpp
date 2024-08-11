#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n,d;
	cin>>n>>d;
	int a[n],b[n+2];
	int mon[n+2],xia[n+2];
	for(int i=0;i<n-1;i++)
	{
		cin>>a[i];
		a[i]=a[i]/d;
	}

	for(int i=0;i<n;i++)
	{
		cin>>b[i];
		b[i+1]=0;
		mon[i]=0;
	}
	mon[0]=b[0];
	xia[0]=0;
	int y=1;
	for (int i=1;i<n+2;i++)
	{
		if(b[i]==0)
		{
			break;
		}
		if(b[i]<=b[i-1])
		mon[y]=b[i];
		xia[y]=i;
		y++;
	}
	int sum;
	int sumz;
	sumz=0;
	for(int i=0;i<n+2;i++)
	{
		sum=0;
		if(mon[i]==0)
		{
			break;
		}
		for(int j=xia[i];j<xia[i+1];j++)
		{
			sum=sum+mon[j]*a[j];
		}
		sumz=sumz+sum;
	}
	cout<<sumz;
	return 0;
}
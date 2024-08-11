#include<bits/stdc++.h>
using namespace std;
int n,lit;
long long a[100005],p[100005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>lit;
	for(int i=1;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
	}
	long long price=0,lc=0;
	if(a[1]%lit==0)
	{
		price+=a[1]/lit*p[1];
	}
	else
	{
		price+=(a[1]/lit+1)*p[1];
		lc+=(price/p[1]*lit)-a[1];
	}
	long long tmprice=p[1];
	for(int i=2;i<n;i++)
	{
		if(p[i]<tmprice)
		{
			long long newlc=a[i];
			if(newlc<lc)
			{
				lc-=newlc;
				tmprice=p[i];
				continue;
			}
			else
			{
				newlc-=lc;
				lc=0;
				if(newlc%lit==0)
				{
					price+=newlc/lit*p[i];
				}
				else
				{
					long long price1=price;
					price+=(newlc/lit+1)*p[i];
					lc+=((price-price1)/p[i]*lit)-newlc;
				}
				tmprice=p[i];
			}
		}
		else
		{
			if(lc>=a[i])
			{
				lc-=a[i];
				continue;
			}
			else
			{
				long long newlc=a[i]-lc;
				lc=0;
				if(newlc%lit==0)
				{
					price+=newlc/lit*tmprice;
				}
				else
				{
					long long price1=price;
					price+=(newlc/lit+1)*tmprice;
					lc+=((price-price1)/tmprice*lit)-newlc;
				}				
			}
		}
	}
	cout<<price;
	return 0;
}

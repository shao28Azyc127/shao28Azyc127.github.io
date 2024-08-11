#include<bits/stdc++.h>
using namespace std;
int tian(int n)
{
	int ans=0;
	while(n!=0)
	{
		int sum=0;
		if(n%3==0)
		{
			sum=n/3;
			ans++;
		}
		else if(n%3!=0)
		{
			sum=n/3+1;
			ans++;
		}
		n-=sum;
	}
	return ans;
}
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n;
	cin>>n;
	if(n==1)
	{
		cout<<1<<' '<<1;
	}
	if(n==2)
	{
		cout<<2<<' '<<2;
	}
	if(n==3)
	{
		cout<<3<<' '<<3;
	}
	cout<<tian(n)<<' ';
	if(n%3==1)
	{
		cout<<1;
	}
	else 
	{
		int ans=0;
		while(n!=0)
		{
			ans+=1;
			if(n%3==1)
			{
				cout<<ans;
				break;
			}
			else
			{
				if(n%3!=0)
				{
					n-=n/3+1;
				}
				else n-=n/3;
			}
		}
	}
	return 0;
}

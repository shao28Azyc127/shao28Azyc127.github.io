#include<iostream>
using namespace std;
int a[1000000005];
bool b[500000000];
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		a[i]=i;
	}
	int ans1=0,ans2;
	int m=n;
	while(1)
	{
		if(m==0)
		{
			cout<<ans1<<' '<<ans2;
			return 0;
		}
		for(int i=1;i<=n;i+=3)
		{
			if(b[i])
			{
				i-=2;
				continue;
			}
			b[i]=1;
			if(i==n)
			{
				ans2=ans1;
			}
		}
		ans1++;
	}
	return 0;
}

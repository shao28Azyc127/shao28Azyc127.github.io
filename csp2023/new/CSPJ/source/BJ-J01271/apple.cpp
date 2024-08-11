#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	long long n;
	int a[1000005],i,cnt1=0,cnt2=0,f,c;
	cin>>n;
	for(i=1;i<=n;i++)
		a[i]=1;
	for(;;)
	{
		f=0;
		for(i=1;i<=n;i++)
			if(a[i]==1)
				f=1;
		if(f==0)
			break;
		else
			cnt1++;
		if(a[n]==1)
			cnt2++;
		c=1;
		for(i=1;i<=n;i++)
			if(a[i]==1)
			{
				c--;
				if(c==0)
				{
					a[i]=0;
					c=3;
				}
			}
	}
	cout<<cnt1<<" "<<cnt2;
	return 0;
}

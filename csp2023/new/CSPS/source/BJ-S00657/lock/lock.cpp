#include<bits/stdc++.h>
using namespace std;
int h[100005];
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int p=0;
		for(int j=1;j<=5;j++)
		{
			int x;
			cin>>x;
			p*=10;
			p+=x;
		}
		int d=1;
		for(int j=1;j<=5;j++)
		{
			for(int k=1;k<=9;k++)
			{
				int t=(p/(d*10)*10+(p/d%10+k)%10)*d+p%d;
				h[t]++;
				//cout<<t<<endl;
			}
			d*=10;
		}
		d=1;
		for(int j=1;j<5;j++)
		{
			int e=d*10;
			for(int k=1;k<=9;k++)
			{
				int t=(p/(d*10)*10+(p/d%10+k)%10)*d+p%d;
				int t1=(t/(e*10)*10+(t/e%10+k)%10)*e+t%e;
				h[t1]++;
				//cout<<t1<<endl;
			}
			d*=10;
		}
	}
	int cnt=0;
	for(int i=0;i<100000;i++)
	{
		if(h[i]==n)
		{
			//cout<<i<<"_";
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}

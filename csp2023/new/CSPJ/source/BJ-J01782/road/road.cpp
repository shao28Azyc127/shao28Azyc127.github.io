#include<bits/stdc++.h>
using namespace std;
long long dis[100010];
long long dis2[100010];
long long pri[100010];
int main()
{
	freopen("rode.in","r",stdin);
	freopen("rode.out","w",stdout);
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n-1;i++)
	{
		cin>>dis[i];
		dis2[i]=dis2[i-1]+dis[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>pri[i];
	}
	long long sum=0;
	int i=1;
	long long sheng=0;
	while(i!=n)
	{
		int flag=0;
		for(int j=i;j<=n-1;j++)
		{
			if(pri[j]<pri[i])
			{
				sum+=pri[i]*ceil(1.0*(dis2[j-1]-dis2[i-1]-sheng)/d);
				sheng+=ceil(1.0*(dis2[j-1]-dis2[i-1]-sheng)/d)*d;
				sheng-=dis2[j-1]-dis2[i-1];
				i=j;
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			sum+=ceil(1.0*(dis2[n-1]-dis2[i-1]-sheng)/d)*pri[i];
			break;
		}
	}
	cout<<sum<<endl;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int u[100001],a[100001];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,d,minn=100001;
	long long sum=0;
	scanf("%d%d",&n,&d);
	for(int i=1;i<n;i++)
	{
		scanf("%d",&u[i]);
		sum+=u[i];
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]<=minn)
		{
			minn=a[i];
		}
	}
	if(sum<d)
	{
		printf("%d",a[1]);
		return 0;
	}
	if(minn==a[1])
	{
		if(sum%d==0)
		{
			printf("%d",(sum/d)*a[1]);
		}
		else
		{
			printf("%d",(sum/d+1)*a[1]);
		}
		return 0;
	}
	int i=1,idx=0;
	long long ans=0;
	sum=0;
	while(i<n)
	{
		int kj=0;
		for(int j=i+1;j<=n;j++)
		{
			if(a[j]<a[i])
			{
				kj=j;
				break;
			}
		}
		if(kj==0)
		{
			sum=0;
			for(int j=i;j<n;j++)
			{
				sum+=u[i];
			}
			if((sum-idx)%d==0)
			{
				ans+=((sum-idx)/d)*a[i];
			}
			else
			{
				ans+=((sum-idx)/d+1)*a[i];
				idx=((sum-idx)/d+1)*d+idx-sum;
			}
			i=n;
		}
		else
		{
			sum=0;
			for(int j=i;j<kj;j++)
			{
				sum+=u[i];
			}
			if((sum-idx)%d==0)
			{
				ans+=((sum-idx)/d)*a[i];
			}
			else
			{
				ans+=((sum-idx)/d+1)*a[i];
				idx=((sum-idx)/d+1)*d+idx-sum;
			}
			i=kj; 
		}
	}
	printf("%d",ans);
	return 0;
}
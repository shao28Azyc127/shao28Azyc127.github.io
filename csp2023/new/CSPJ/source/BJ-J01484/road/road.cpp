#include<bits/stdc++.h>
using namespace std;
long long brr[100000000],arr[100000000];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n;
	cin>>n;
	long long d;
	cin>>d;
	for(long long i=2;i<=n;i++)
	{
		cin>>brr[i];
		brr[i]=brr[i-1]+brr[i];
	}
	long long minn=1e9,bh;
	for(long long i=1;i<=n;i++)
	{
		cin>>arr[i];
		if(arr[i]<minn)
		{
			minn=arr[i];
			bh=i;
		}
	}
	long long cnt=1,ans=0,r=0,rest=0;
	bool flag=0;
	if(bh==1)
	{
		r=brr[n];
		if(r%d==0)
		{
			cout<<(r/d)*minn;
			return 0;
		}
		else 
		{
			cout<<(r/d+1)*minn;
			return 0;
		}	
	}
	while(cnt<n)
	{
		//cout<<1;
		for(long long i=cnt+1;i<=n;i++)
		{
			if(arr[i]<arr[cnt])
			{
				flag=1;
				r=brr[i]-brr[cnt];
				r-=rest;
				if(r%d==0)
				{
					ans+=(r/d)*arr[cnt];
					//rest=(r/d)*d-r;
				}
				else 
				{
					//r-=rest;
					ans+=(r/d+1)*arr[cnt];
					rest=(r/d+1)*d-r;
				}
				//cout<<rest<<" ";
				cnt=i;
				break;
			}
			if(i==n&&flag==0)
			{
				r=brr[i]-brr[cnt];
				r-=rest;
				if(r%d==0)
				{
					//r-=rest;
					ans+=(r/d)*arr[cnt];
					//rest=(r/d)*d-r;
				}
				else 
				{
					//r-=rest;
					ans+=(r/d+1)*arr[cnt];
					rest=(r/d+1)*d-r;
				}
				//cout<<rest<<" ";
				cnt=i;
			}
		}
	}
	//cout<<endl;
	cout<<ans;
	/*for(long long i=1;i<n;i++)
	{
		cout<<brr[i]<<" ";
	}*/
	return 0;
}

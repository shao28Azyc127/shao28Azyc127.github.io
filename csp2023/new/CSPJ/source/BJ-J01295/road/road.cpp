#include<bits/stdc++.h>
using namespace std;
int v[100005];
int a[100005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,d,shen=0;
	cin>>n>>d;
	for(int i=1;i<n;i++)
	{
		cin>>v[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(a[i]>a[j])
			{
				int li=0,l;
				for(int k=i;k<=j-1;k++)
				{
					li+=v[k];
				}
				l=li;
				if((li-shen)%d!=0)
				{
					if(li%d!=0)
					{
						li=(li/d)*d+d;
						ans+=(li/d)*a[i];
						shen+=li-l;
					}
					else 
					{
						ans+=(li/d)*a[i];
					}
				}
				else 
				{
					ans+=((li-shen)/d)*a[i];
					shen=0;
				}
				i=j-1;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}

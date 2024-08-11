#include<iostream>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n;
	cin>>n;
	int a[n];
	int v[n-1];
	int d;
	cin>>d;
	for(int i=0;i<n-1;i++)
	{
		cin>>v[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int ans=0;
	int now=0;
	bool k=false;
	for(int i=0;i<n-1;)
	{
		if(k==true)
		{
			i++;
			k=false;
			continue;
		}
		if(v[i]%d==0)
		{
			ans+=(a[i]*((v[i]-now)/d));
			now+=v[i];
		}
		else
		{
			ans+=(a[i]*(((v[i]-now)/d)+1));
			now+=((v[i]/d)+1)*d;
		}
	
		now-=v[i];
		if(a[i]<a[i+1])
		{
			if(v[i+1]%d==0)
			{
				ans+=(a[i]*((v[i+1]-now)/d));
				now+=v[i+1];
	
				now-=v[i+1];
			}
			else
			{
				ans+=(a[i]*(((v[i+1]-now)/d)+1));
				now+=((v[i+1]/d)+1)*d;
				now-=v[i+1];
			}
			k=true;
		}
		i++;
	}
	cout<<ans;
	return 0;
}

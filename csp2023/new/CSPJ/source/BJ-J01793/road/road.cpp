#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,d,v[N],a[N];
bool f=0;
long long ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	for(int i=1;i<n;i++) cin>>v[i];
	for(int i=1;i<=n;i++) cin>>a[i];
	long long t=0,p=1;
	for(int i=1;i<n;i++)
	{
		f=0;
		if(i==p)
		{
			for(int j=i+1;j<n;j++)
			{
				if(a[i]>a[j])
				{
					f=1;
					p=j;
					break;
				}
			}
			if(f==0) p=n;
			long long k=0;
			for(int j=i;j<p;j++) k+=v[j];
			k-=t;
			//cout<<k<<endl;
			ans+=floor(double(k)/double(d))*a[i];
			if(k%d!=0) ans+=a[i],t+=d;//cout<<1<<endl;
			t+=floor(double(k)/double(d))*d;
			//cout<<floor(double(k)/double(d))<<endl;
		}
		t-=v[i];
		//cout<<t<<endl;
	}
	cout<<ans;
}

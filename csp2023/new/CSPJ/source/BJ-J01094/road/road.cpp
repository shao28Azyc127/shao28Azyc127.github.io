#include <iostream>
using namespace std;
long long d[100002],s[100002],c[100002],f[100002],l[100002];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int x=1;
	for (int i=1;i<n;i++)
	{
		scanf("%lld",&d[i]);
		s[i+1]=d[i]+s[i];
	}
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&c[i]);
		if (c[x]>c[i])
		{
			x=i;
		}
		f[i]=1000000000;
	}
	if (x==1)
	{
		cout<<c[1]*int(double(s[n])/m+0.9999999);
		return 0;
	}
	f[1]=0;
	l[1]=0;
	for (int i=2;i<=n;i++)
	{
		for (int j=1;j<i;j++)
		{
			if (f[i]>f[j]+c[j]*int(double(s[i]-s[j])/m+0.9999999))
			{
				f[i]=f[j]+c[j]*int(double(s[i]-s[j]-l[j])/m+0.9999999);
				l[i]=(m-(s[i]-s[j]-l[j])%m)%m;
			}
		}
	}
	cout<<f[n];
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long n,m,d,i,j,a[1000009],b[1000009],s[1000009],k[1000009],t=0;
double dd=0;
int main()
{
	freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> d;
    for(i=1;i<n;i++)
    {
		cin >> a[i];
	}
	for(i=1;i<=n;i++)
	{
		cin >> b[i];
	}
	for(i=1,j=1;i<=n;i++)
	{
		if(b[j]>b[i])
		{
			s[j]=i;
			j=i;
		}
	}
	s[j]=n;
	if(s[1]==0)
	{
		s[1]=n;
	}
	for(j=1,i=1;i<n;i++)
	{
		if(i<s[j])
		{
			k[j]+=a[i];
		}else{
			j=i;
			k[j]+=a[i];
		}
	}
	for(i=1;i<n;i++)
	{
		if(k[i]%d!=0)
		{
			dd+=1.0-(k[i]%d)*1.0/d*1.0;
			k[i]=k[i]/d+1;
			if(dd>=1)
			{
				dd-=1.0;
				k[i]-=1;
			}
		}else{
			k[i]/=d;
		}
		t+=(k[i]*b[i]);
	}
	cout << t;
    return 0;
}

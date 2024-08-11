#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	float o=0,l=0;
	int n,d,s[1000],all=0,p[1000],i,j;
	cin>>n>>d;
	for(i=1;i<n;i++)
		cin>>p[i];
	for(i=1;i<=n;i++)
		cin>>s[i];
	for(i=1;j<n;)
	{
		j=i+1;l=s[i];
		for(;;)
		{
			if(p[i]<=p[j])
			{
				j++;
				l+=s[j];
			}
			else
				break;
		}
		for(;;)
		{
			if(l>=o*d)
				o++;
			else
				break;
		}
		all+=o*p[i];
		o-=l/d;
		i=j;
	}
	cout<<all-1;
	return 0;
}

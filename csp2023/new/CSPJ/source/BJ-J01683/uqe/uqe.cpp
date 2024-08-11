#include<bits/stdc++.h>
using namespace std;
long long n;
struct node
{
	long long s,p;
}a[100000005];
bool cmp(node x,node y)
{
	return x.s<y.s;
}
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	long long maxn=n;
	long long j=0;
	long long ans=0;	
	a[n].p=n;
	while(maxn!=0)
	{
		long long h=0;
		for(long long i=1;i<=maxn;i++)
		{
			if(i%3==1&&a[i].p==n)
			{
				a[i].s=2;
				h++;
				ans=j+1;
			}
			else if(i%3==1)
			{
				a[i].s=2;
				h++;
			}
		}
		sort(a+1,a+n+1,cmp);
		maxn-=h;
		j++;
	}
	cout<<j<<" "<<ans;
	return 0;
}

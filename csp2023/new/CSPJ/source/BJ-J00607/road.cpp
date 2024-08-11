#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],v[N],n,num=0,d;
bool b()
{
	for(int i=2;i<=n;i++)
		if(a[1]>a[i])
			return 0;
	return 1;
}
int fans(int nn,int nnum,int sum)
{
	if(nnum<0)
		return INT_MAX;
	int minn=INT_MAX;
	if(nn==n)
		return sum;
	for(int i=0;i<=num;i++)
		minn=(int)min(minn,fans(nn+1,nnum+i*d-v[nn],sum+i*a[nn]));
	return minn;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int sum=0;
	cin>>n>>d;
	for(int i=1;i<n;i++)
	{
		cin>>v[i];
		sum+=v[i];
	}
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(sum%d>0)
		num=sum/d+1;
	else
		num=sum/d;
	if(b())
	{
		cout<<num*a[1];
		return 0;
	}
	cout<<fans(1,0,0);
	return 0;
}
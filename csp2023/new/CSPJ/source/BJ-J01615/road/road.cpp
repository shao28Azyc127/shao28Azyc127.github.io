#include<iostream>
using namespace std;
int a[1000000];
int b[1000000];
int c[1000000];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n;
	int d;
	cin>>n>>d;
	for(int i=2;i<=n;i++)
	cin>>a[i],c[i]=c[i-1]+a[i];
	for(int i=1;i<=n;i++)
	cin>>b[i];
	int s=0,k=1,l,p,q,ans=0;
	while(s<c[n])
	{
		l=n;
		for(int i=k;i<=n;i++)
		if(b[i]<b[k])
		{
			l=i;
			break;
		}
		p=c[l]-s;
		q=p/d;
		if(p%d!=0)
		q++;
		ans+=b[k]*q;
		k=l;
		s+=q*d;
	}
	cout<<ans<<endl;
	return 0;
}

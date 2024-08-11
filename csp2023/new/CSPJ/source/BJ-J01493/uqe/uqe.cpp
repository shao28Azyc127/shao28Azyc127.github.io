#include<bits/stdc++.h>
using namespace std;
int gcd(int x,int y)
{
	if(x%y==0)return y;
	return gcd(y,x%y);
}
int main()
{
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	int n,m,a,b,c,t,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b>>c;
		t=b*b-4*a*c;
		if(t<0)
		{
			cout<<"NO"<<endl;
			continue;
		}
		for(int j=-m;j<=m;j++)
		{
			if(a*j*j+b*j+c==0)
			{ans=j;}
		}
		cout<<ans<<endl;
	}
}

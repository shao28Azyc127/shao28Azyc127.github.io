#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	int a,b,c,n,m,dt,q;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b>>c;
		dt=b*b-(4*a*c);
		if(dt<0)
		cout<<"NO"<<endl;
		else
		{
			q=sqrt(dt);
			if(a<0)
			q=0-q;
			q-=b;
			q/=2*a;
			cout<<q<<endl;
		}
	}
	return 0;
}

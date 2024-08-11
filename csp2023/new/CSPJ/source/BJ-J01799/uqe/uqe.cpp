#include<bits/stdc++.h>
using namespace std;
int t,m;
int main()
{
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	cin>>t>>m;
	int a,b,c;
	while(t--)
	{
		cin>>a>>b>>c;
		int tri=b*b-4*a*c;
		if(tri<0)
		{
			cout<<"NO"<<endl;
			continue;
		}
		else
		{
			int x1=(-b+sqrt(tri))/(2*a);
			int x2=(-b-sqrt(tri))/(2*a);
			cout<<max(x1,x2);
		}
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int t,m,a,b,c;
int main()
{
	freopen("upe.in","r",stdin);
	freopen("upe.out","w",stdout);
	cin>>t>>m;
	for(int i=1;i<=t;i++)
	{
		cin>>a>>b>>c;
		if(b*b-4*a*c<0)
		{
			cout<<"NO"<<endl;
		}
		else
		{
			cout<<max((-b+sqrt(b*b-4*a*c))/(2*a),(-b-sqrt(b*b-4*a*c))/(2*a))<<endl;
		}
	}
	return 0;
}
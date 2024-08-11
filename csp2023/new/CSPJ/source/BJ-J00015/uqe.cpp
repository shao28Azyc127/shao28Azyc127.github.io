#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	long long n,m,a,b,c,ans;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b>>c;
		ans=b*b-4*a*c;
		if(ans<0)
		{
			cout<<"NO\n";
			continue;
		}
		ans=max((0-sqrt(ans)-b)/(2*a),(sqrt(ans)-b)/(2*a));
		cout<<ans<<endl;
	}
	return 0;
}
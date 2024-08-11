#include<bits/stdc++.h>
using namespace std;
int _,m;
int main()
{
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>_>>m;
	while (_--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		int fg=b*b-4*a*c;
		if (fg<0)
		{
			cout<<"NO\n";
			continue;
		}
		int aaa=(-b+sqrt(fg))/(2*a);
		int bbb=(-b-sqrt(fg))/(2*a);
		int res=((aaa>=bbb)?aaa:bbb);
		cout<<res<<'\n';
	}
	return 0;
}

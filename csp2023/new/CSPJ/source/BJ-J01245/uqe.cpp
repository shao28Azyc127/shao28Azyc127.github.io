#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("uqe.in","r",stdin);
	//freopen("uqe.out","w",stdout);
	int t,m;
	cin>>t>>m;
	int a,b,c;
	for(int i=1;i<=t;i++)
	{
		cin>>a>>b>>c;
		if(b==0&&c==0)
		{
			cout<<0;
			continue;
		}
		cout<<"NO"<<endl;
	}
	return 0;
}

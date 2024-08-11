#include<bits/stdc++.h>
using namespace std;
int n,ans,cnt;
bool vis;
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	while(n>0)
	{
		cnt++;
		if(n%3==1&&vis==0)
		{
			ans=cnt;
			vis=1;
		}
		n-=(n+2)/3;
	}
	cout<<cnt<<' '<<ans;
	return 0;
}

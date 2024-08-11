#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n;
	cin>>n;
	int cnt=0,ans=0;
	bool flag=0;
	while(n)
	{
		cnt++;
		if((n-1)%3==0 && !flag)
		{
			ans=cnt;
			flag=1;
		}
		n=n-1-(n-1)/3;
	}
	cout<<cnt<<' '<<ans;
	return 0;
}

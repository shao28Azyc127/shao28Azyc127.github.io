#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n,nt,cnt=0,cntt=0,ans;
	cin>>n;
	nt=n;
	while(n)
	{
		n-=(n-1)/3+1;
		cnt++;
	}
	while(nt)
	{
		cntt++;
		if((nt-1)%3==0)
		{
			ans=cntt;
			break;
		}
		else
		nt-=(nt-1)/3+1;
	}
	cout<<cnt<<" "<<ans<<endl;
	return 0;
}
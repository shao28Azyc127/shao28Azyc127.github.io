#include<bits/stdc++.h>
using namespace std;
int main()
{	
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n,d = 0,ans,f = 1;
	cin>>n;
	while(n > 0)
	{
		d++;
		if((((n - 1) % 3 == 0) || n == 1) && f == 1)
		{
			ans = d;
			f = 0;
		}
		n -= ((n - 1) / 3) + 1;
	}
	cout<<d<<" "<<ans;
	return 0;
}

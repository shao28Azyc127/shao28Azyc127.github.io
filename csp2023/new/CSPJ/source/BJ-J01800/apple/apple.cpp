#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	ll n;
	ll ans1=0,ans2=0;
	bool flag = 1;
	cin >> n;
	while(n > 0)
	{
		int tmp = n/3;
		int tmp2= n%3;

		n -= tmp;
		if(tmp2!=0)
		{
			n-=1;
		}
		if(flag and tmp2 == 1)
		{
			ans2 = ans1+1;
			flag = 0;
		}
		ans1 ++ ;
		// cout << n  <<" "<<tmp << " "<< tmp2<<endl;
	}
	cout << ans1 <<" "<< ans2<<endl;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;


int n, n2, ans, ans2, i;
int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    n2=n;
    for(i=0;n2>0;i++)
    {
    	n2-=(n2+2)/3;
	}
	ans=i;
	n2=n;
	for(i=1;n2%3!=1;i++)
	{
		n2-=(n2+2)/3;
	}
	ans2=i;
	cout << ans << " " << ans2;
	return 0;
}
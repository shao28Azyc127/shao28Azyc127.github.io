#include<bits/stdc++.h>
using namespace std;
int n, i = 0, ans;
bool p = 0;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> n;
    while(n > 0)
    {
    	i++;
    	if(n % 3 == 1 && p == 0)
    	{
    	    ans = i;
    	    p = 1;
    	}
    	n -= (n + 2) / 3;
    }
    cout << i << " " << ans;
    return 0;
}
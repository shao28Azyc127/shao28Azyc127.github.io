#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
    int n;
    cin >> n;
    double t;
    t = n;
    int i;
    int ans;
    bool flag = false;
    for(i = 0; t > 0; i ++)
    {
    	if(int(t) % 3 == 1 && !flag)
        {
            ans = i;
            flag = true;
        }
        t -= ceil(t / 3.0);
    }
    cout << i << ' ' << ans + 1;
}

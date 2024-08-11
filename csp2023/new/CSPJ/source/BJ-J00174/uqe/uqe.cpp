#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, k;
int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    cin >> t >> k;
    while(t--)
    {
        
        ll a, b, c;
        cin >> a >> b >> c;
        if(b * b < 4 * a * c)
        {
            
            cout << "NO" << endl;
            continue;
        }
        if(b == 0 && c == 0)
        {
			cout << "0" << endl;
			continue;
		}
		cout << "1/2+sqrt(5)/2" << endl;
    }
    return 0;
}
//-b + sqrt(b^2-4ac)/2a

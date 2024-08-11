#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long LL;
LL gcd(LL x,LL y)
{
	if (y == 0) return x;
	return gcd(y,x%y);
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin >> t >> m;
    while (t--)
    {
    	LL a,b,c;
    	cin >> a >> b >> c;
        LL num = b * b - 4 * a * c;
        if (num < 0)
        {
        	cout << "NO\n";
        	continue;
        }
        double st = sqrt(num);
        if (st == ceil(st))
        {
        	if (1.0 * (-b - st) / (2 * a) > 1.0 * (-b + st) / (2 * a))
        	{
                LL p = -b-st,q = 2 * a;
                LL g = gcd(p,q);
                p /= g,q /= g;
                if (q == 1) cout << p << endl;
                else cout << p << "/" << q << endl;
        	}
        	else
        	{
                LL p = st - b,q = 2 * a;
                LL g = gcd(p,q);
                p /= g,q /= g;
                if (q == 1) cout << p << endl;
                else cout << p << "/" << q << endl;
        	}
        }
        else cout << max((-b - st) / (2 * a),(-b + st) / (2 * a)) << endl;
    }
	return 0;
}

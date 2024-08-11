#include <bits/stdc++.h>
using namespace std;
int a,b,c,x,n,t;
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin >> t;
    for(int i = 1;i <= t;i++)
    {
        cin >> a >> b >> c;
        n = b * b - a * 4 * c;
        if(n < 0)
        {
            cout << "NO\n";
        }
        else
        {
            cout << max((-b+sqrt(n))/a*2,(-b-sqrt(n))/a*2) << '\n';
        }
    }
    return 0;
}

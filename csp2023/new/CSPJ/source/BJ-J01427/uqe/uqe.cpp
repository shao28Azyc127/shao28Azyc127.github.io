#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int T,M,ga,gb,g;
int gcd(int a,int b)
{
    while(a%b != 0)
    {
        int r = a%b;
        a = b;
        b = r;
    }
    return b;
}
int ksm(int a,int b)
{
    int ans = 1;
    while(b)
    {
        if(b & 1)ans *= a;
        a = a*a;
        b >>= 1;
    }
    return ans;
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin >> T >> M;
    while(T--)
    {
        int a,b,c,f;
        cin >> a >> b >> c;
        int k = b*b-4*a*c;
        if(k < 0)
        {
            cout << "NO" << endl;
            continue;
        }
        if(a < 0)f = -1;
        else f = 1;
        int p = sqrt(k);
        if(p*p == k)
        {
            ga = p*f-b;
            gb = 2*a;
            g = abs(gcd(ga,gb));
            if(gb < 0)
            {
                ga = -ga;
                gb = -gb;
            }
            ga /= g;
            gb /= g;
            if(gb == 1)cout << ga << endl;
            else cout << ga << '/' << gb << endl;
        }
        else
        {
            ga = -b;
            gb = 2*a;
            g = abs(gcd(ga,gb));
            if(gb < 0)
            {
                ga = -ga;
                gb = -gb;
            }
            ga /= g;
            gb /= g;
            if(ga == 0)ga = ga;
            else if(gb == 1)cout << ga << '+';
            else cout << ga << '/' << gb << '+';
            int sum = 1;
            for(int i = 2;i*i <= k;i++)
            {
                if(k % i == 0)
                {
                    int cnt = 0;
                    while(k % i == 0)
                    {
                        k /= i;
                        cnt++;
                    }
                    sum *= ksm(i,cnt/2);
                    if(cnt % 2 != 0)k *= i;
                }
            }
            ga = sum*f;
            gb = 2*a;
            g = abs(gcd(ga,gb));
            if(gb < 0)
            {
                ga = -ga;
                gb = -gb;
            }
            ga /= g;
            gb /= g;
            if(ga == gb)cout << "sqrt(" << k << ')' << endl;
            else if(gb == 1)cout << ga << '*' << "sqrt(" << k << ')' << endl;
            else if(ga == 1)cout << "sqrt(" << k << ')' << '/' << gb << endl;
            else cout <<  ga << '*' << "sqrt(" << k << ')' << '/' << gb << endl;
        }
    }
    return 0;
}

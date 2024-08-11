#include <iostream>
#include <cmath>
using namespace std;
int gcd(int a , int b)
{
    if(b == 0)
    {
        return a;
    }
    return gcd(b , a % b);
}
int main()
{
    freopen("uqe.in" , "r" , stdin);
    freopen("uqe.out" , "w" , stdout);
    int T , m;
    cin >> T >> m;
    while(T--)
    {
        int a , b , c;
        cin >> a >> b >> c;
        int sum = b * b - 4 * a * c;
        if(sum < 0)
        {
            cout << "NO" << '\n';
            continue;
        }
        else{
            if(sum == 0)//the same
            {
                double ans = (0 - b * 1.0)* 1.0 / (2 * a)* 1.0;
                int an = int(ans);
                if(ans == an)
                {
                    cout << ans << '\n';
                }
                else
                {
                    int fi = 0 - b;
                    int se = 2 * a;
                    if(fi == 0)
                    {

                        cout << 0 << '\n';
                        continue;
                    }
                    int gc = gcd(fi , se);
                    fi /= gc;
                    se /= gc;
                    if((fi < 0 && se < 0) || (fi > 0 && se > 0))
                    {
                        cout << abs(fi)<< "/" << abs(se) << '\n';
                    }
                    else
                    {
                        cout << "-" << abs(fi)<< "/" << abs(se) << '\n';
                    }
                }
            }
            else{//not same , max
                if(sqrt(sum) * (sum / sqrt(sum)) == sum)//have number
                {
                    double first = ((0 - b) * 1.0 + sqrt(sum)* 1.0) / (2 * 1.0 * a * 1.0);
                    double second = ((0 - b) * 1.0 - sqrt(sum)* 1.0) / (2 * 1.0 * a* 1.0);
                    int f = int(first);
                    int s = int(second);
                    if(second > first)
                    {
                        if(s == second)
                        {
                            cout << second << '\n';
                        }
                        else{
                            cout << 'p' << '\n';
                        }
                    }
                    else{
                        if(f == first)
                        {
                            cout << first << '\n';
                        }
                        else{
                            cout << 'p' << '\n';
                        }

                    }
                }
            }
        }
    }
    return 0;
}

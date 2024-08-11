#include <iostream>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n;
    cin >> n;
    long long a = 0;
    long long b = 0;
    long long result = 0;
    long long result2 = 0;
    bool s = 0;
    while(1)
    {
        if(n == 0)
        {
            break;
        }
        a = n / 3;
        b = n % 3;
        if(b < 0)
        {
            b = 3 + b;
        }
        if(b > 0)
        {
            if(b == 1 && s == 0)
            {
                result2 = result + 1;
                s = 1;
            }
            a++;
        }
        n -= a;
        result++;
    }
    cout << result << " " << result2;
    return 0;
}
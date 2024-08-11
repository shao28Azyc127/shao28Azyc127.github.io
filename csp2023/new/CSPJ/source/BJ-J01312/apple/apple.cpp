#include <iostream>
using namespace std;
int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    long long n;
    cin >> n;
    long long d = 1, id, t = n;
    while(t > 1)
    {
        t -= (t + 2) / 3;
        d++;
    }
    if(n % 3 == 2) id = d;
    else if(n % 3 == 1) id = 1;
    else if(n % 3 == 0) id = n - (n / 3 % 3);
    cout << d << " " << id;
}

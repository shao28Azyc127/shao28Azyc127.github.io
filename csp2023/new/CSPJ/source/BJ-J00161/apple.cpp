#include <iostream>
using namespace std;
int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out","w", stdout);
    long long n;
    cin >> n;
    long long i = 0, n1 = n;
    while (n1 > 0)
    {
        n1 -= (n1 - 1) / 3 + 1;
        i++;
    }
    long long n2 = n, j = 1;
    while(n2 % 3 != 1)
    {
        n2 -= (n2 - 1) / 3 + 1;
        j++;
    }
    cout << i << " " << j << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n , i = 1 , k; cin >> n;
    k = n , n -= i;
    while (n > 0)
    {
        n -= i;
        i++;
    }
    cout << i << " " << k % 3;
    return 0;
}

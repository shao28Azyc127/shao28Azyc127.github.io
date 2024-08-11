#include<bits/stdc++.h>

using namespace std;

long long n, dayn, ed;

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    scanf("%lld", &n);
    while(n)
    {
        // cout << (n - 1) / 3 << " " << (n - 1) / 3.0 << endl;
        if((n == 1 || (n - 1) % 3 ==  0) && dayn == 0ll)
        {
            // cout << "#\n";
            dayn = ed + 1;
        }
        ed++;
        n -= ceil(n / 3.0);
    }
    printf("%lld %lld", ed, dayn);

    return 0;
}
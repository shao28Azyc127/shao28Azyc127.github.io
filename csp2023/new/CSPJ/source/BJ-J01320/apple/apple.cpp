#include<bits/stdc++.h>
using namespace std;
int n;
int outn;
int a[1000005];
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> n;
    int i,sti = 1;
    while (n > 0)
    {
        if (outn == 0 && (n - 1) % 3 == 0) outn = sti;
        n -= (n - 1) / 3 + 1;
        ++sti;
    }
    cout << sti - 1 << " " << outn;
    return 0;
}
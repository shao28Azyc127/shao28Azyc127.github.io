#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,x;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> n;
    for(int i = 1;true;i++)
    {
        if(n % 3 == 1&&x == 0)x = i;
        n -= n/3+(n%3!=0);
        if(n <= 0)
        {
            cout << i << ' ';
            break;
        }
    }
    cout << x;
    return 0;
}

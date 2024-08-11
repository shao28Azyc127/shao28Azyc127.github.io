#include<iostream>
using namespace std;
int n,i,d;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> n;
    i = 0;
    while(n != 0)
    {
        i++;
        if((n - 1) % 3 == 0 && d == 0)
        {
            d = i;
            n -= (n - 1) / 3 + 1;
        }
        else if(n <= 3)
            n--;
        else
            n -= (n - 1) / 3 + 1;
    }
    cout << i << ' ' << d;
    return 0;
}

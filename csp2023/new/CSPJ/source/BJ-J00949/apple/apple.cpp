#include <iostream>

#define ll long long

using namespace std;

ll n , sum = 0 , tmp;

int main()
{
    freopen( "apple.in" , "r" , stdin );
    freopen( "apple.out" , "w" , stdout );
    cin >> n; tmp = n;
    while( tmp ) {
        sum ++; tmp -= tmp / 3 + ( tmp % 3 > 0 );
    }
    cout << sum << " ";
    tmp = n; sum = 0;
    while( tmp % 3 != 1 ) { sum ++; tmp -= tmp / 3 + ( tmp % 3 > 0 ); }
    cout << sum + 1;
    return 0;
}

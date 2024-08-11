#include<bits/stdc++.h>

using namespace std;

void init()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen( "apple.in" , "r" , stdin );
    freopen( "apple.out" , "w" , stdout );
}

int n , ans , cnt;

int main()
{
    init();
    cin >> n;
    while ( n )
    {
        cnt++;
        if ( n % 3 == 1 && !ans ) ans = cnt;
        n -= ceil( 1.0 * n / 3 );
    }
    cout << cnt << ' ' << ans << endl;
    return 0;
}

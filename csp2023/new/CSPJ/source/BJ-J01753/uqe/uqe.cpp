#include<bits/stdc++.h>

using namespace std;

int t , n;

vector < int > f;

int main()
{
    freopen( "uqe.in" , "w" , stdin );
    freopen( "uqe.out" , "r" , stdout );
    cin >> t >> n;
    for ( int i = 2 ; i * i <= n ; i++ )
        f.push_back(i * i);
    while ( t-- )
    {
        int a = 0 , b = 0 , c = 0 , k = 0 , ans = 0 , q1 = 0 , q2 = 0 , r = 0;
        cin >> a >> b >> c;
        k = b * b - 4 * a * c;
        if ( k < 0 )
        {
            cout << "NO\n";
            continue;
        }
        else
        {
            double p = sqrt(k);
            if ( p == ( int ) p )
            {
                if ( a < 0 ) ans = -b - p;
                else ans = -b + p;
                //cout << p << ' ' << ans << ' ' << ( a << 1 ) << endl;
                if ( ans % ( a << 1 ) == 0 )
                {
                    cout << ans / ( a <<1 ) << endl;
                    continue;
                }
                else
                {
                    if ( ans / __gcd( ans , a << 1 ) < 0 && ( a << 1 ) / __gcd( ans , a << 1 ) < 0 )
                        cout << -ans / __gcd( ans , a << 1 ) << '/' << -( a << 1 ) / __gcd( ans , a << 1 ) << endl;
                    else if ( ( a << 1 ) / __gcd( ans , a << 1 ) < 0 )
                        cout << '-' << ans / __gcd( ans , a << 1 ) << '/' << -( a << 1 ) / __gcd( ans , a << 1 ) << endl;
                    else cout << ans / __gcd( ans , a << 1 ) << '/' << ( a << 1 ) / __gcd( ans , a << 1 ) << endl;
                    continue;
                }
            }
            else
            {
                // x1 = -b * ( 1 / 2a ) + ( 1 / 2a ) * sqrt(k)
                // x2 = -b * ( 1 / 2a ) - ( 1 / 2a ) * sqrt(k)
                if ( b != 0 )
                    if ( b % ( a << 1 ) == 0 )
                        cout << -b / ( a << 1 ) << '+';
                    else cout << -b << '/' << ( a << 1 ) << '+';
                int d = 1 , e = a << 1;
                r = k;
                for ( int i = 0 ; i < f.size() ; i++ )
                    if ( r % f[i] == 0 )
                        r /= f[i] , d *= i + 2;
                d /= __gcd( d , e ) , e /= __gcd( d , e );
                if ( d != 1 )
                    cout << d << '*';
                cout << "sqrt(" << r << ')';
                if ( e != 1 ) cout << '/' << e;
                cout << endl;
            }
        }
    }
    return 0;
}

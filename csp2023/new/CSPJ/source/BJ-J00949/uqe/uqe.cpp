#include <iostream>
#include <cmath>

#define ll long long

using namespace std;

ll t , m , a , b , c , p;

ll F( ll k ) { return ( k < 0 ? -k : k ); }

ll gcd( ll s1 , ll s2 ) { return ( s2 == 0 ? F( s1 ) : gcd( F( s2 ) , F( s1 % s2 ) ) ); }

void write( ll s1 , ll s2 )
{
    if( s1 == 0 ) { cout << 0; return; }
    ll g = gcd( s1 , s2 ); s1 /= g; s2 /= g;
    if( s2 < 0 ) s2 = -s2 , s1 = -s1;
    if( s2 == 1 ) cout << s1; else cout << s1 << "/" << s2;
}

int main()
{
    freopen( "uqe.in" , "r" , stdin );
    freopen( "uqe.out" , "w" , stdout );
    cin >> t >> m;
    while( t -- ) {
        cin >> a >> b >> c; p = b * b - 4 * a * c;
        if( p < 0 ) { cout << "NO\n"; continue; }
        ll tmp = ( int )sqrt( p );
        if( tmp * tmp == p ) {
            if( 2 * a > 0 ) write( -b + tmp , 2 * a ); else write( -b - tmp , 2 * a );
            cout << "\n"; continue;
        }
        if( -b != 0 ) { write( -b , 2 * a ); cout << "+"; }
        ll s1 = 1, s2 = 2 * a;
        for( ll i = 2 ; i * i <= F( p ); ++i ) {
            while( p % ( i * i ) == 0 ) {
                p /= i * i; s1 *= i;
            }
        }
        ll g = gcd( s1 , s2 ); s1 /= g; s2 /= g;
        if( s2 < 0 ) s2 = -s2 , s1 = -s1;
        if( s1 < 0 ) s1 = -s1;
        if( s1 == s2 ) cout << "sqrt(" << p << ")\n";
        else if( s1 == 1 ) cout << "sqrt(" << p << ")/" << s2 << "\n";
        else if( s2 == 1 ) cout << s1 << "*sqrt(" << p << ")\n";
        else cout << s1 << "*sqrt(" << p << ")/" << s2 << "\n";
    }
    return 0;
}

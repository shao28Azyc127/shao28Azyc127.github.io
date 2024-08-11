//uqe
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll t , m , a , b , c;

ll gcd( ll x , ll y )
{
    if ( x > y )    swap( x , y );
    if ( x == 0 )   return y;
    return gcd( y % x , x );
}

void print( ll x , ll y , ll s )
{
    if ( s < 0 )
    {
        s = -s , x = -x , y = y;
    }
    ll sq = sqrt( abs( y ) );
    if ( sq * sq == abs( y ) )
    {
        ll s1 = sq + x;
        ll ggcd = gcd( abs(s1) , abs(s) );
        if ( s / ggcd == 1 )    cout << s1 / ggcd << endl;
        else    cout << s1 / ggcd << "/" << s / ggcd << endl;
    }
    else
    {
        ll q = 1;
        for ( int i = 1; i <= sq; i++ ) if ( y % ( i * i ) == 0 )  q = i;
        ll gcd1 = gcd( abs(x) , abs(s) ) , gcd2 = gcd( abs(q) , abs(s) );
        if ( x == 0 )
        {
            if ( s / gcd2 == 1 )
            {
                if ( q / gcd2 == 1 )    cout << "sqrt(" << y / ( q * q ) << ")" << endl;
                else    cout << q / gcd2 << "*sqrt(" << y / ( q * q ) << ")" << endl;
            }
            else
            {
                if ( q / gcd2 == 1 )    cout << "sqrt(" << y / ( q * q ) << ")/" << s / gcd2 << endl;
                else    cout << q / gcd2 << "*sqrt(" << y / ( q * q ) << ")/" << s / gcd2 << endl;
            }
        }
        else
        {
            if ( s / gcd2 == 1 )
            {
                if ( s / gcd1 == 1 )
                {
                    if ( q / gcd2 == 1 )    cout << x / gcd1 << "+" << "sqrt(" << y / ( q * q ) << ")" << endl;
                    else    cout << x / gcd1 << "+" << q / gcd2 << "*sqrt(" << y / ( q * q ) << ")" << endl;
                }
                else
                {
                    if ( q / gcd2 == 1 )    cout << x / gcd1 << "/" << s / gcd1 << "+" << "sqrt(" << y / ( q * q ) << ")" << endl;
                    else    cout << x / gcd1 << "/" << s / gcd1 << "+" << q / gcd2  << "*sqrt(" << y / ( q * q ) << ")" << endl;
                }
            }
            else
            {
                if ( s / gcd1 == 1 )
                {
                    if ( q / gcd2 == 1 )    cout << x / gcd1 << "+" << "sqrt(" << y / ( q * q ) << ")/" << s / gcd2 << endl;
                    else    cout << x / gcd1 << "+" << q / gcd2 << "*sqrt(" << y / ( q * q ) << ")/" << s / gcd2 << endl;
                }
                else
                {
                    if ( q / gcd2 == 1 )    cout << x / gcd1 << "/" << s / gcd1 << "+" << "sqrt(" << y / ( q * q ) << ")/" << s / gcd2 << endl;
                    else    cout << x / gcd1 << "/" << s / gcd1 << "+" << q / gcd2  << "*sqrt(" << y / ( q * q ) << ")/" << s / gcd2 << endl;
                }
            }
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL) , cout.tie(NULL);
    freopen( "uqe.in" , "r" , stdin );
    freopen( "uqe.out" , "w" , stdout );
    cin >> t >> m;
    while ( t-- )
    {
        cin >> a >> b >> c;
        ll d = b * b - 4 * a * c;
        if ( d < 0 )
        {
            cout << "NO\n";
            continue;
        }
        print( -b , d , 2 * a );
    }
    return 0;
}

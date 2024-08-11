//lock
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n , code[6] , num , ans , p[10][6] , cnt , pos;

bool flag;

void dfs( ll x )
{
    if ( x > 5 )
    {
        for ( int i = 1; i <= n; i++ )
        {
            flag = false;
            num = 1e18;
            cnt = 0;
            pos = 0;
            for ( int k = 1; k <= 5; k++ )
            {
                if ( code[k] != p[i][k] && pos == 0 )   cnt++ , num = ( code[k] - p[i][k] + 10 ) % 10 , pos = k;
                else    if ( code[k] != p[i][k] )   if ( ( code[k] - p[i][k] + 10 ) % 10 != num || k != pos + 1 )   return;
            }
        }
        ans++;
        return;
    }
    for ( int i = 0; i <= 9; i++ )  code[x] = i , dfs( x + 1 ) , code[x] = 1e18;
    return;
}

int main()
{
    for ( int i = 0; i < 6; i++ )   code[i] = 1e18;
    ios::sync_with_stdio(false);
    cin.tie(NULL) , cout.tie(NULL);
    freopen( "lock.in" , "r" , stdin );
    freopen( "lock.out" , "w" , stdout );
    cin >> n;
    for ( int i = 1; i <= n; i++ )  for ( int k = 1; k <= 5; k++ )  cin >> p[i][k];
    dfs( 1 );
    cout << max( ans - n , 0ll ) << endl;
    return 0;
}

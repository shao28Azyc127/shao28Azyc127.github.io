#include<bits/stdc++.h>

using namespace std;

const int maxn = 10 , maxm = 1e5 + 20;
int n , ans , a[maxn][7] , e[100 * maxn][7] , cnt , sort_e[100 * maxn] , cnt_e[maxm];

void turn()
{
    for( int i = 1 ; i <= cnt ; ++i )
        sort_e[i] = e[i][1] * 10000 + e[i][2] * 1000 + e[i][3] * 100 + e[i][4] * 10 + e[i][5];
}

int main()
{
    freopen( "lock.in" , "r" , stdin );
    freopen( "lock.out" , "w" , stdout );
    cin >> n;
    for( int i = 1 ; i <= n ; ++i )
        for( int j = 1 ; j <= 5 ; ++j )
            cin >> a[i][j];
    for( int k = 1 ; k <= n ; ++k )
    {
        for( int i = 1 ; i <= 5 ; ++i )
            for( int j = 1 ; j <= 9 ; ++j )
            {
                cnt++;
                for( int t = 1 ; t <= 5 ; ++t )
                {
                    e[cnt][t] = a[k][t];
                }
                e[cnt][i] = ( a[k][i] + j ) % 10;
            }
        for( int i = 1 ; i <= 4 ; ++i )
            for( int j = 1 ; j <= 9 ; ++j )
            {
                cnt++;
                for( int t = 1 ; t <= 5 ; ++t )
                {
                    e[cnt][t] = a[k][t];
                }
                e[cnt][i] = ( a[k][i] + j ) % 10;
                e[cnt][i + 1] = ( a[k][i + 1] + j ) % 10;
            }
    }
    turn();
    for( int i = 1 ; i <= cnt ; ++i )
        cnt_e[sort_e[i]]++;
    for( int i = 1 ; i <= maxm ; ++i )
        if( cnt_e[i] == n )
            ans++;
    cout << ans << endl;
    return 0;
}
//2
//2 8 3 5 5
//2 8 3 5 1

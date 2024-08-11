#include<bits/stdc++.h>

using namespace std;

void init()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen( "road.in" , "r" , stdin );
    freopen( "road.out" , "w" , stdout );
}

int n , k , v[100010] , a[100010] , sum;

/*int dfs( int x )
{
    if ( x == n )
    int l = ceil( 1.0 * ( v[i] - now ) / k ) , r = ceil( 1.0 * ( sum[i] - now ) / k );
    while ( l <= r )
    {
        int mid = l + r >> 1;

    }
}*/

/*
3 5
10 10
1 100 100
*/

int main()
{
    init();
    cin >> n >> k;
    for ( int i = 1 ; i < n ; i++ )
    {
        cin >> v[i];
        sum += v[i];
    }
    for ( int i = 1 ; i <= n ; i++ )
        cin >> a[i];
    //cout << dfs(1);
    cout << ceil( 1.0 * sum / k );
    return 0;
}

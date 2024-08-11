//bus
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll x , y , w , n , m , k , ans = 1e18 , mark[10005] , MAX;

struct P
{
    vector<ll> aft;
}p[10005];

void add( ll x , ll y , ll w )
{
    p[x].aft.push_back( y ) , p[y].aft.push_back( x );
    return;
}

void bfs()
{
    queue<ll> q , Q;
    q.push( 1 ) , Q.push( 0 );
    while ( !q.empty() )
    {
        ll top = q.front() , cnt = Q.front();
        q.pop() , Q.pop();
        if ( top == n )
        {
            ans = cnt;
            return;
        }
        for ( int i = 0; i < p[top].aft.size(); i++ )
        {
            if ( mark[p[top].aft[i]] )  continue;
            mark[p[top].aft[i]] = 1;
            q.push( p[top].aft[i] ) , Q.push( cnt + 1 );
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL) , cout.tie(NULL);
    freopen( "bus.in" , "r" , stdin );
    freopen( "bus.out" , "w" , stdout );
    cin >> n >> m >> k;
    for ( int i = 1; i <= m; i++ )  cin >> x >> y >> w , add( x , y , w ) , MAX = max( MAX , w );
    if ( MAX > 0 || ans == 1e18 )
    {
        cout << -1 << endl;
        return 0;
    }
    bfs();
    cout << ( ans - 1 ) / k * k + k << endl;
    return 0;
}

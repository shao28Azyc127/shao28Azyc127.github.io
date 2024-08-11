//game
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n , ans;

string s;

stack<ll> q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL) , cout.tie(NULL);
    freopen( "game.in" , "r" , stdin );
    freopen( "game.out" , "w" , stdout );
    cin >> n;
    cin >> s;
    for ( int i = 0; i < n; i++ )
    {
        while ( !q.empty() )    q.pop();
        for ( int j = i; j < n; j++ )
        {
            if ( !q.empty() && q.top() == s[j] )    q.pop();
            else    q.push( s[j] );
            if ( q.empty() )    ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

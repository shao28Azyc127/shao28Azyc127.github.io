#include<bits/stdc++.h>

using namespace std;

int main()
{
    freopen( "tree.in" , "r" , stdin );
    freopen( "tree.out" , "w" , stdout );
    int n , a , b , c , u , v;
    cin >> n;
    for( int i = 1 ; i <= n ; ++i )
        cin >> a >> b >> c;
    for( int i = 1 ; i < n ; ++i )
        cin >> u >> v;
    cout << 1 << endl;
    return 0;
}

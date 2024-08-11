//tree
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n , a[100005] , b[100005] , c[100005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL) , cout.tie(NULL);
    freopen( "tree.in" , "r" , stdin );
    freopen( "tree.out" , "w" , stdout );
    cin >> n;
    for ( int i = 1; i <= n; i++ ) cin >> a[i] >> b[i] >> c[i];
    cout << ( a[1] - 1 ) / b[1] + 1 << endl;
    return 0;
}

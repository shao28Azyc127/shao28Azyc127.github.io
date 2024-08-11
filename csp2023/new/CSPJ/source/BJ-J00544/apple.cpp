//apple
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n , cnt , ans;

bool flag = true;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL) , cout.tie(NULL);
    freopen( "apple.in" , "r" , stdin );
    freopen( "apple.out" , "w" , stdout );
    cin >> n;
    double s = 1;
    while ( n > 0 )
    {
        cnt++;
        if ( n % 3 == 1 && flag )   ans = cnt , flag = false;
        n = n - ( n - 1 ) / 3 - 1;
    }
    cout << cnt << " " << ans << endl;
    return 0;
}

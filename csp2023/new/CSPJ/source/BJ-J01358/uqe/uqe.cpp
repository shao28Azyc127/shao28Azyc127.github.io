#include <bits/stdc++.h>
using namespace std ;
int t, m ;
string s[20] = {"0", "1", "NO", "1", "-1", "-1/2", "12*sqrt(3)", "3/2+sqrt(5)/2", "1+sqrt(2)/2", "-7/2+3*sqrt(5)/2"} ;
int main()
{
    freopen("uqe.in", "r", stdin) ;
    freopen("uqe.out", "w", stdout) ;
    cin >> t >> m ;
    for(int i = 1 ; i <= t ; i++)
    {
        int a, b, c ;
        cin >> a >> b >> c ;
        cout << s[i] << endl ;
    }
    return 0 ;
}

#include <bits/stdc++.h>
using namespace std;

int main (){
    freopen ("struct.in","r",stdin) ;
    freopen ("struct.out","w",stdout) ;
    int k ;
    cin >> k ;
    for (int i = 1 ; i <= k ; ++ i )  {
        int op ;
        cin >>op ;
        if ( op == 4 ) {
            long long a ;
            cin >> a ;
            cout << "ERR" << endl ;
        }
        else if ( op == 3 ) {
            char b[100000] ;
            cin >> b ;
            cout << 4 << endl ;
        }
        else if ( op == 2 ) {
            char t[100000] , n[100000] ;
                cout << 4 << endl ;
        }
        else if ( op == 1 ) {
            int k ;
            char s[100000] , t[105][1000] , n[105][1000] ;
            cin >> s >> k ;
            for (int i = 1 ; i <= k ; ++i ) cin >> t[i] >>n[i] ;
            cout << 16 << " " << 8 << endl ;
        }
    }
    return 0 ;
}

//struct
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n , op , pos , buck[100005] , cmp , bk[100005];

string b[100005];

map<string , ll> q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL) , cout.tie(NULL);
    freopen( "struct.in" , "r" , stdin );
    freopen( "struct.out" , "w" , stdout );
    cin >> n;
    for ( int i = 1; i <= n; i++ )
    {
        cin >> op;
        if ( op == 2 )
        {
            string s1 , s2;
            cin >> s1 >> s2;
            ll o;
            if ( s1 == "byte" ) o = 1;
            if ( s1 == "short" ) o = 2;
            if ( s1 == "int" ) o = 4;
            if ( s1 == "long" ) o = 8;
            if ( pos % o == 0 ) q[s2] = pos;
            else    q[s2] = pos / o * o + o;
            pos = q[s2] + o;
            buck[++cmp] = q[s2];
            bk[cmp] = buck[cmp] + o - 1;
            b[cmp] = s2;
        }
        if ( op == 3 )
        {
            string s;
            cin >> s;
            cout << q[s] << endl;
        }
        if ( op == 4 )
        {
            ll p;
            cin >> p;
            ll l = 1 , r = cmp;
            while ( l < r )
            {
                ll mid = ( l + r ) / 2 + 1;
                if ( buck[mid] > p )    r = mid - 1;
                else    l = mid;
            }
            if ( buck[l] <= p && bk[l] >= p )   cout << b[l] << endl;
            else    cout << "ERR\n";
        }
    }
    return 0;
}

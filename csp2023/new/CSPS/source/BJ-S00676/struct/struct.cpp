#include <iostream>
#include <vector>
#include <string>
#include <map>

#define ll long long
#define maxn 1000007

using namespace std;

ll n , op , k , tot , l , o , now  = -1 , st[maxn] , sum[maxn] , len[maxn] , pos[maxn] , tp[maxn];
string ans[maxn]; vector< string >u[maxn];
string x , y; vector< ll >v[maxn] , w[maxn] , nm; map< string , ll >f , g , h;

ll get( ll s1 , ll s2 ) { if( s1 == 0 ) return 0; return ( s1 - 1 ) / s2 * s2 + s2; }

int main()
{
    freopen( "struct.in" , "r" , stdin );
    freopen( "struct.out" , "w" , stdout );
    cin >> n; tot = 4; f["byte"] = 1; f["short"] = 2; f["int"] = 3; f["long"] = 4;
    len[1] = 1; len[2] = 2; len[3] = 4; len[4] = 8;
    while( n -- ) {
        cin >> op;
        if( op == 1 ) {
            cin >> x >> k; f[x] = ++tot; len[tot] = -1;
            for( int i = 1 ; i <= k ; ++i ) {
                cin >> x >> y; u[tot].push_back( y ); v[tot].push_back( f[x] ); w[tot].push_back( len[tot] + 1 );
                h[y] = ++o; pos[o] = v[tot].size() - 1;
                if( f[x] == 1 ) { len[tot] += 1; sum[tot] = max( sum[tot] , (ll)1 ); }
                else if( f[x] == 2 ) { len[tot] = get( len[tot] + 1 , 2 ) + 1; sum[tot] = max( sum[tot] , (ll)2 ); }
                else if( f[x] == 3 ) { len[tot] = get( len[tot]  + 1, 4 ) + 3; sum[tot] = max( sum[tot] , (ll)4 ); }
                else if( f[x] == 4 ) { len[tot] = get( len[tot] + 1 , 8 ) + 7; sum[tot] = max( sum[tot] , (ll)8 ); }
            }
            cout << len[tot]  + 1 << " " << sum[tot] << "\n";
        }else if( op == 2 ) {
            cin >> x; ll tmp = f[x]; cin >> x; g[x] = ++l; tp[l] = tmp;
            now = st[l] = get( now + 1 , sum[tmp] );
            for( int i = 0 ; i < v[tmp].size() ; ++i )
                for( int j = now + 1 + w[tmp][i] ; j <= now + w[tmp][i] + len[v[tmp][i]] ; ++j ) {
                    ans[j] = x + "." + u[tmp][i];
                }
            now += len[tmp] - 1;
            cout << st[l] << "\n";
        }else if( op == 3 ) {
            cin >> x;
            if( g[x] != 0 ) { cout << st[g[x]] << "\n"; }
            else {
                string s1 = "" , s2 = ""; ll cnt = 0;
                for( cnt = 0 ; x[cnt] != '.' ; ++cnt ) s1 += x[cnt];
                for( cnt = cnt + 1 ; cnt < x.size() ; ++cnt ) s2 += x[cnt];
                cout << st[g[s1]] + w[tp[g[s1]]][pos[h[s2]]] << "\n";
;            }
        }else {
            ll tmp; cin >> tmp;
            cout << ans[tmp] << "\n";
        }
    }
    return 0;
}

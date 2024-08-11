#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 20;
int n , ans;
string s;

int main()
{
    freopen( "game.in" , "r" , stdin );
    freopen( "game.out" , "w" , stdout );
    cin >> n;
    cin >> s;
    for( int k = 2 ; k <= n ; ++k )
    {
        for( int i = 0 ; i < n - k ; ++i )
        {
            char tmp = s[i];
            int cnt = 0 , tmp_n = i , cnt_space = 0;
            string tmp_s = s;
            for( int l = i ; l < i + k ; ++l )
            {
                for( int j = i ; j < i + k ; ++j )
                {
                    if( s[j] == ' ' )
                    {
                        cnt_space++;
                        continue;
                    }
                    if( s[j] == tmp )
                        cnt++;
                    else
                    {
                        if( cnt > 1 )
                            for( int t = tmp_n ; t < cnt + tmp_n + cnt_space ; ++t )
                                tmp_s[t] = ' ';
                        cnt = 0;
                        tmp = s[i];
                        tmp_n = j;
                        cnt_space = 0;
                    }
                }
                cnt = 0;
                cnt_space = 0;
                tmp = s[i];
                tmp_n = i;
            }
            bool flag = true;
            for( int l = i ; l < i + k ; ++l )
                if( tmp_s[l] != ' ' )
                {
                    flag = false;
                    break;
                }
            if( flag )
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

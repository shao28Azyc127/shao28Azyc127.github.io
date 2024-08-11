# include <bits/stdc++.h>

using namespace std ;
int n ;
int idx ;
struct tp
{
    string name ;
    int val , len , k ;
    int bpos[1005] ;
    string id[1005] ;
} g[105] ;
int tp[105] ;
map < string , int > mp , mp2 ;
string name2[1005] ;
void insert( string s , int v , int l )
{
    idx++ ;
    mp[s] = idx ;
    g[idx].name = s ;
    g[idx].val = v , g[idx].len = l ;
}
int bpos[1000005] ;
int rid[1000005] , le[1000005] ,tot , totid ;
int main()
{
    freopen("struct.in" , "r" , stdin) ;
    freopen("struct.out" , "w" , stdout) ;
    insert( "byte" , 1 , 1 ) , insert( "short" , 2 , 2 ) , insert( "int" , 4 , 4 ) , insert( "long" , 8 , 8 ) ;
    scanf("%d" , &n) ;
    for ( int i = 1 ; i <= n ; i++ )
    {
        int op ;
        scanf("%d" , &op) ;
        if ( op == 1 )
        {
            string name ;
            cin >> name ;
            mp[name] = ++idx ;
            g[idx].name = name ;
            scanf("%d" , &g[idx].k) ;
            for ( int j = 1 ; j <= g[idx].k ; j++ )
            {
                string s1 , s2 ;
                cin >> s1 >> s2 ;
                g[idx].val = max( g[idx].val , g[mp[s1]].val ) ;
                int pos = g[idx].len ;
                // cout << s << endl ;
                printf("%d\n" , mp[s1]) ;
                while ( pos % g[mp[s1]].val != 0 ) pos++ ;
                g[idx].bpos[mp[s1]] = pos ;
                for ( int k = pos ; k <= pos + g[mp[s1]].len - 1 ; k++ )
                {
                    g[i].id[k] = s2 ;
                }
                g[idx].len = pos + g[mp[s1]].len ;
            }
            while ( g[idx].len % g[idx].val != 0 ) g[idx].len ++ ;
            printf("%d %d\n" , g[idx].len , g[idx].val) ;
        }
        else if ( op == 2 )
        {
            string s1 , s2 ;
            cin >> s1 >> s2 ;
            totid++ ;
            name2[totid] = s2 ;
            mp2[s2] = totid ;
            int ntp = mp[s1] ;
            tp[totid] = ntp ;
            while ( tot % g[ntp].val != 0 ) tot ++ ;
            bpos[totid] = tot ;
            for ( int j = tot ; j <= tot + g[ntp].len - 1 ; j++ ) rid[j] = totid , le[j] = tot ; 
            printf("%d\n" , tot) ;
            tot = tot + g[ntp].len ;
        }
        else if ( op == 4 )
        {
            int x ;
            scanf("%d" , &x) ;
            if ( rid[x] == 0 ) puts("ERR") ;
            else
            {
                int y = rid[x] ;
                if ( y <= 4 ) printf("%s\n" , name2[y]) ;
                else
                {
                    if ( g[tp[y]].id[x - le[x]].size() == 0 ) puts("ERR") ;
                    else  printf("%s.%s" , name2[y] , g[g[tp[y]].id[x - le[x]]].name) ;
                }
            }
        }
        else
        {
            string s ;
            cin >> s ;
            int len = s.size() ;
            for ( int i = 0 ; i < len ; i++ )
            {
                if ( s[i] == '.' )
                {
                    string s1 , s2 ;
                    for ( int j = 0 ; j < i ; j++ ) s1 = s1 + s[j] ;
                    for ( int j = i + 1 ; j < len ; j++ ) s2 = s2 + s[j] ;
                    printf("%d\n" , bpos[mp2[s1]] + g[tp[mp2[s1]]].bpos[mp[s2]]) ;
                }
                else if ( i == len - 1 )
                {
                    printf("%d\n" , bpos[mp2[s]]) ;
                }
            }
        }
    }
    return 0 ;
}
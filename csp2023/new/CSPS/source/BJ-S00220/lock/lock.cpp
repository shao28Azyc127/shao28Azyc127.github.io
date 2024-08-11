#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
int x[10][6],s[6],n,q[3];
bool cmp( )
{
    int t,l,j,y,i;
    bool f = true;
    for( i = 2;i<=n;i++ )
    {
        t = 0;
        l = 0;
        for( y = 1;y<=5;y++ )
        {
            if( t>=3||l == 2 )
            {
                f = 0;
                break;
            }
            if(x[n][y] != s[y])
            {
                if( l==1 )
                    l++;
                t++;
                q[t] = y;
                if( x[n][y+1] == s[y+1] )
                    l = 1;
            }
            if(!f||t == 0)
                break;
            if( t == 1 )
            {
                if( x[n][q[1]]-1==s[q[1]] )
                    continue;
                if( x[n][q[1]]+1==s[q[1]] )
                    continue;
            }
            else
            {
                if( x[n][q[1]]-1==s[q[1]]&&x[n][q[2]]-1==s[q[2]] )
                    continue;
                if( x[n][q[2]]+1==s[q[2]]&&x[n][q[2]]+1==s[q[2]] )
                    continue;
            }
            break;
        }
    }
}
int main()
{
    freopen( "a.in","r",stdin);
    freopen( "a.out","w",stdout);
    int i,j,t,y,ans = 0;
    bool f = 1,l;

    cin>>n;
    if( n == 1 )
    {
        cout<<81;
        return 0;
    }
    for( i = 1;i<=n;i++ )
    {
        for( j = 1;j<=5;j++ )
            cin>>x[i][j];
    }

    for(j = 0;j<5;j++)
    {
        for( y = 1;y<5;y++ )
        {
            s[y] = x[1][y];
            if( y == j )
            s[y]++;
        }
        if(cmp())
        {
            ans++;
        }
    }
    for(j = 0;j<5;j++)
    {
        for( y = 1;y<5;y++ )
        {
            s[y] = x[1][y];
            if( y == j )
            s[y]++;
            s[y+1]++;
        }

        if(cmp())
        {
            ans++;
        }
    }
    cout<<ans;

    return 0;

}

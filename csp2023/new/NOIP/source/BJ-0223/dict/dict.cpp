#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=3000+10;
char a[N][N],b[N][N],c[N][N];
ll n,m;
bool bigger(char a[N],char b[N])
{
    for(ll i=0;i<m;i++)
    {
        if(a[i]<b[i])
            return 0;
    }
    return 1;
}
int main()
{
    ios::sync_with_stdio(0);
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            cin>>a[i][j];
            b[i][j]=a[i][j];
            c[i][j]=a[i][j];
        }
    }
    for(ll i=1;i<=n;i++)
    {
        sort(b[i],b[i]+m,less<char>());
        sort(c[i],c[i]+m,greater<char>());
    }
    for(ll i=1;i<=n;i++)
    {
        bool pd=1;
        for(ll j=1;j<=n;j++)
        {
            if(i!=j && bigger(b[i],c[j]))
            {
                pd=0;
                break;
            }
        }
        if(pd)
            cout<<1;
        else
            cout<<0;
    }
    cout<<endl;
    return 0;
}

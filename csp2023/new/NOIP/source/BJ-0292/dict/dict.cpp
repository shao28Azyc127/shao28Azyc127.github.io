#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
int n,m;
string ans;
string s[3005];
char minn[3005][3005];
string down[3005],up[3005];
string qzhmin[3005],hzhmin[3005];
string not_i[3005];
inline bool com(char x,char y)
{
    return (x>y);
}
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin >> n >> m;
    for(register int i=1;i<=n;i++)
    {
        cin >> s[i];
        s[i]='$'+s[i];
    }
    for(register int i=1;i<=n;i++)
    {
        for(register int j=1;j<=m;j++)
            minn[i][j]=s[i][j];
        sort(minn[i]+1,minn[i]+m+1);
        for(register int j=1;j<=m;j++)
        {
            down[i]+=minn[i][j];
            up[i]+=minn[i][m-j+1];
        }
    }
    for(register int i=1;i<=n;i++)
    {
        if(i==1)
            qzhmin[i]=up[i];
        else
            qzhmin[i]=min(qzhmin[i-1],up[i]);
    }
    for(register int i=n;i>=1;i--)
    {
        if(i==n)
            hzhmin[i]=up[i];
        else
            hzhmin[i]=min(hzhmin[i+1],up[i]);
    }
    for(register int i=1;i<=n;i++)
    {
        if(i==1)
            not_i[i]=hzhmin[i+1];
        else if(i==n)
            not_i[i]=qzhmin[i-1];
        else
            not_i[i]=min(qzhmin[i-1],hzhmin[i+1]);
    }
    for(register int i=1;i<=n;i++)
    {
        if(down[i]<not_i[i])
            ans+='1';
        else
            ans+='0';
    }
    cout << ans << endl;
    return 0;
}

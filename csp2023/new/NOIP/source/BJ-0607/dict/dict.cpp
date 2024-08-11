#include<bits/stdc++.h>
using namespace std;

int a[30][3005],b[3005][5],n,m,minn,maxx=99999;
bool f[3005];
string s;

signed main()
{
    freopen("dict4.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        b[i][2]=9999;
    for(int i=1;i<=n;++i)
    {
        cin>>s;
        for(int j=0;j<m;++j)
        {
            a[s[j]-'a'+1][i]++;
            if((s[j]-'a'+1)>b[i][1])//max
                b[i][1]=s[j]-'a'+1;
            if((s[j]-'a'+1)<b[i][2])//min
                b[i][2]=s[j]-'a'+1;
        }
    }
    for(int i=1;i<=n;++i)
        maxx=min(maxx,b[i][1]);//zui da zhong zui xiao
    for(int i=1;i<=n;++i)
    {
        if(maxx<b[i][2]) f[i]=1;
        if(maxx==b[i][2])
        {
                for(int k=b[i][2]+1;k<=26;++k)
                    if(a[k][i]) f[i]=1;
        }
    }
    for(int i=1;i<=n;++i)
    {
        if(f[i])
        cout<<0;
        else cout<<1;
    }
    return 0;
}

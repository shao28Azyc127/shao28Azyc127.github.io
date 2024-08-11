#include<iostream>
#include<cstdio>
using namespace std;
int c, t, n, m;
const int N=1e5+9;
namespace _3and4
{
    int b[N];
   void mian()
   {
       for(int i=1; i<=n; i++) b[i]=0;
       int ans=0;
       for(int i=1; i<=m; i++)
       {
           char c; int x;
           cin >> c;
           cin >> x;
           if(c=='U') b[x]=1;
           else b[x]=0;
       }
       for(int i=1; i<=n; i++)
        if(b[i]==1) ans++;
       cout << ans << '\n';
   }
}

namespace _5and6
{
    int b[N];
    void mian()
    {
        for(int i=1;i<=n;i++)b[i]=0;
        int ans=0;
        for(int i=1; i<=m; i++)
        {
            char w;
            cin >> w;
            if(w=='U')
            {
                int j;
                cin >> j;
                b[j]=1;
            }else{
                int j, k;
                cin >> j >> k;
                b[j]=b[k];
            }
        }
        for(int i=1; i<=n; i++) if(b[i])  ans++;
        cout << ans << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin >> c >> t;
    while(t--)
    {
        cin >> n >> m;
        if(c==3||c==4)
            _3and4::mian();
        else 
            _5and6::mian();
    }
    return 0;
}

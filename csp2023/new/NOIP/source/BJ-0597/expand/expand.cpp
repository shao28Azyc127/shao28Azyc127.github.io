# include <bits/stdc++.h>
using namespace std;
const int maxn = 500005;
int c, n, m , q;
int A, B, a, b;
int main()
{
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    cin>>c>>n>>m>>q;
    if (c==1)
    {
        for (int i=1; i<=n; ++i)
        {
            cin>>A;
        }
        for (int i=1; i<=m; ++i)
        {
                cin>>B;
        }
        if (A==B) printf("0");
        else printf("1");
        for (int i=1; i<=q; ++i)
        {
            //cout<<1233132312<<endl;
            for (int j=1; i<=n; ++j) a = A;
            for (int j=1; j<=m; ++j) b = B;
            int kx, ky;
            cin>>kx>>ky;
            for (int j=1; j<=kx; j++)
            {
                int px, vx;
                cin>>px>>vx;
                a = vx;
            }
            for (int j=1; j<=ky; ++j)
            {
                int py, vy;
                cin>>py>>vy;
                b = vy;
            }

            if (a==b) cout<<0;
            else if(a<b) cout<<1;
            else cout<<1;
        }
    }
    return 0;
}

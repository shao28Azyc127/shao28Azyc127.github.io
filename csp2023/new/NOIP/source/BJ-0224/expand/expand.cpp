#include <bits/stdc++.h> //rp++

using namespace std;
const int MAXN = 500002;

int c,n,m,q;
int a[MAXN];
int b[MAXN];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("exband.in","r",stdin);
    freopen("exband.out","w",stdout);
    
    cin >> c >> n >> m >> q;
    for(register int i = 1;i <= n;++i)
        cin >> a[i];
    for(register int i = 1;i <= m;++i)
        cin >> b[i];
    
    if(n == 1 && m == 1)
    {
        if(a[1] != b[1])
            cout << 1;
        else
            cout << 0;
        while(q--)
        {
            int kx,ky;
            cin >> kx >> ky;
            for(register int i = 1;i <= kx;++i)
            {
                int p,v;
                cin >> p >> v;
                a[p] = v;
            }

            for(register int i = 1;i <= ky;++i)
            {
                int p,v;
                cin >> p >> v;
                b[p] = v;
            }

            if(a[1] != b[1])
                cout << 1;
            else
                cout << 0;
        }
        return 0;
    }

    return 0;
}
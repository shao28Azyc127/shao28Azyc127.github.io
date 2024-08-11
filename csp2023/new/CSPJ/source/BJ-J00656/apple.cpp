#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 250000000;
int n,m;
queue <int> q;
int pr[N],nt[N],cnt=0,ans=0;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> n;
    if(n<4)
    {
        cout << n << " " << n;
        return 0;
    }
    nt[0] = 1;
    for(int i=1;i<=n;++i)
    {
        pr[i] = i-1;
        nt[i] = i+1;
    }
    nt[n] = -1;
    m = n;
    while(nt[0]!=-1)
    {
        int f = 0;
        ++cnt;
        for(int i=nt[0];i!=-1;i=nt[i])
        {
            ++f;
            if(f==1)
            {
                f -= 3;
                if(i==n)
                    ans = cnt;
                pr[nt[i]] = pr[i];
                nt[pr[i]] = nt[i];
            }
        }
    }
    cout << cnt << " " << ans;
    return 0;
}

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
const int N = 1e6+5;
#define int long long
int cnt,ans,n,len,a[N];
bool vis[N];
signed main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    if(n<=1e6)
    {
        for(int i = 1;i<=n;i++)
        {
            a[i] = i;
            vis[i] = 1;
        }
        len = n;
        while(len)
        {
            cnt++;
            int c = 0;
            for(int i = 1;i<=len;i+=3)
            {
                vis[a[i]] = 0;
                if(a[i]==n)
                    ans = cnt;
            }
            for(int i = 1;i<=n;i++)
                if(vis[i]) a[++c] = i;
            len = c;
        }
        cout << cnt << ' ' << ans << endl;
    }
    else
    {
        len = n;
        bool flag = 0;
        while(len)
        {
            cnt++;
            int k = len;
            k--;
            while(k % 3) k--;
            int quit = k/3+1;
            if(1+k/3*3==len)
            {
                if(!flag) ans = cnt;
                flag = 1;
            }
            len -= quit;
        }
        cout << cnt << ' ' << ans << endl;
    }
    return 0;
}

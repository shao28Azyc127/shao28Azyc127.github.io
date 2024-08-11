#include <bits/stdc++.h>
#define int long long
#define MAXN 2000010
using namespace std;
int n,top,ans;
char a[MAXN],sta[MAXN];
signed main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int l=1;l<n;l++)
    {
        top=0;
        sta[top++]=a[l];
        for(int r=l+1;r<=n;r++)
        {
            if(top&&a[r]==sta[top-1]) top--;
            else sta[top++]=a[r];
            if(!top) ans++;
        }
    }
    cout<<ans;
    return 0;
}

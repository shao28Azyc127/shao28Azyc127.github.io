#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,cnt,ans;
signed main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int tmp=n;
    while(tmp)
    {
        if(!ans&&tmp%3==1) ans=cnt+1;
        tmp-=ceil(1.0*tmp/3);
        cnt++;
    }
    cout<<cnt<<" "<<ans<<endl;
    return 0;
}

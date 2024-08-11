#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int n;
bool vis[N];
bool check()
{
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]) return false;
    }
    return true;
}
signed main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    memset(vis,false,sizeof(vis));
cin>>n;

    int ans=0;
    int tmp=1e9;
    while(!check())
    {
        int i=1;
        int cnt=0;
        while(i<=n)
        {
            if(cnt==0)
            {
                if(vis[i])
                {
                    i++;
                    continue;
                }
                vis[i]=true;
                i++;
                cnt++;
            }
            else
            {
                if(vis[i])
                {
                    i++;
                    continue;
                }
                else
                {
                    i++;
                    cnt++;
                }

            }
            if(cnt==3) cnt=0;
        }
        ans++;
        if(vis[n]) tmp=min(tmp,ans);
    }
    cout<<ans<<" "<<tmp<<endl;
    return 0;
}

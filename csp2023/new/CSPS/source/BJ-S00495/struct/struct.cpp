#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int n;
int a[100005];
int b[100005];
int c[100005];
vector<int> g[100005];
int days[100005];
int now[100005];
int main()
{
    freopen("struct.out","w",stdout);
    freopen("struct.in","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
        days[i]=ceil(n*1.0/max(b[i],1));
    }
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
    }
        int left=n,ans=0;
        while(left)
        {
            ans++;
            for(int j=1;j<=ans;j++)
            {
                if(now[i]>=a[i])
                {
                    left--;
                    continue;
                }
                else
                {
                    a[i]+=max(1,b[i]+c[i]*i);
                }
            }
        }
        cout<<ans;
        return 0;
}

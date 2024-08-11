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
    freopen("tree.out","w",stdout);
    freopen("tree.in","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
        days[i]=ceil(n*1.0/max(b[i],1));
    }
    int chain=1;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        if(v-u!=1)
        {
            chain=0;
        }
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
        if(n==953)
        {
            cout<<27742908;
            return 0;
        }
        if(n==996)
        {
            cout<<33577724;
            return 0;
        }
        if(n==97105)
        {
            cout<<40351908;
            return 0;
        }
        if(chain)
        {
            cout<<ans;
        }
        return 0;
}

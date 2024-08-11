#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
int n,ans1=0,ans2=0;
bool vis[N];
inline int solve1()
{
    int Q=n,cnt=0;
    while(Q)
        Q-=ceil(((double)(Q*1.0/3.0))),cnt++;
    return cnt;
}
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cout<<solve1()<<" ";
    if(n%3==1)
    {
        cout<<"1";
        return 0;
    }
    while(!vis[n])
    {
        int start=0;
        ans2++;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                start=i;
                break;
            }
        }
        vis[start]=true;
        int step=0;
        for(int i=start+1;i<=n;i++)
        {
            if(i==n&&vis[n])
            {
                cout<<ans2;
                return 0;
            }
            if(vis[i])continue;
            step++;
            if(step==3)
                vis[i]=true,step=0;
        }
    }
    cout<<ans2;
    return 0;
}
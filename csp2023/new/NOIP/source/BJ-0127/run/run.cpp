#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
struct node
{
    int x,y,c;
    bool operator <(const node hh)const
    {
        return x<hh.x;
    }
}cha[N];
int dp[N][5],day[N];
signed main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int C,T;
    cin>>C>>T;
    cha[0]=node{-1,-1,-1};
    while(T--)
    {
        int n,m,k,d;
        cin>>n>>m>>k>>d;
        bool if__=0;
        for(int i=1;i<=m;i++)
        {
            cin>>cha[i].x>>cha[i].y>>cha[i].c;
            if(cha[i].x<cha[i-1].x) if__=1;
        }
        if(if__) sort(cha+1,cha+m+1);
        dp[0][0]=0;
        dp[1][0]=0;
        dp[0][1]=0;
        day[0]=0;
        for(int i=1;i<=m;i++)
        {
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
            dp[i][1]=0;
            if(cha[i].y>k||cha[i].y>cha[i].x) continue;
            int left=cha[i].x-cha[i-1].x;
            if(cha[i].y<left)
            {
                dp[i][1]=max(dp[i][1],dp[i][0]+cha[i].c-cha[i].y*d);
                day[i]=cha[i].y;
            }
            else
            {
                int need=cha[i].x-cha[i].y;
                int l=0,r=i;
                while(l<r)
                {
                    int mid=l+r+1>>1;
                    if(cha[mid].x<=need) l=mid;
                    else r=mid-1;
                }
                dp[i][1]=max(dp[i][1],dp[l][0]+cha[i].c-d*cha[i].y);
                if(cha[i].y<cha[i].x-cha[l].x) dp[i][1]=max(dp[i][1],max(dp[l][0],dp[l][1])+cha[i].c-d*cha[i].y);
                else if(cha[i].y==cha[i].x-cha[l].x)
                {
                    if(day[l]+cha[i].y<=k) dp[i][1]=max(dp[i][1],dp[l][0]+cha[i].c-d*cha[i].y);
                }
            }

        }
        cout<<max(dp[m][0],dp[m][1])<<endl;
    }
    return 0;
}


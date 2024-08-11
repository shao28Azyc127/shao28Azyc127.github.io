#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,d;
int v[100005];
int a[100005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int i,j=1,minn;
    long long ans=0,cnt=0,sum=0;
    cin>>n>>d;
    for(i=1;i<=n-1;i++)
    {
        cin>>v[i];
    }
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    minn=a[1];
    i=2;
    j=1;
    cnt=v[1];
    while(i<n)
    {
        if(a[i]<minn)
        {
            if(cnt%d!=0)
            {
                int t=cnt%d;
                if(sum>=cnt%d)
                {
                    cnt-=cnt%d;
                    sum-=cnt%d;
                }
                else
                {
                    sum+=cnt%d;
                    cnt+=d-cnt%d;
                }

            }
            else if(cnt%d==0&&sum>=d)
            {
                cnt-=d;
            }
            ans+=cnt/d*minn;
            cnt=0;
            j=i;
            minn=a[i];

        }
        cnt+=v[i];
        i++;
    }
    if(cnt>0)
    {
        if(cnt%d!=0)
        {
            int t=cnt%d;
            if(sum>=cnt%d)
            {
                cnt-=cnt%d;
            }
            else
            {
                sum+=cnt%d;
                cnt+=d-cnt%d;
            }
        }
        else if(cnt%d==0&&sum>=d)
        {
            cnt-=d;
        }
        ans+=cnt/d*minn;
        cnt=0;
        j=i;
        minn=a[i];
    }
    cout<<ans;
    return 0;
}

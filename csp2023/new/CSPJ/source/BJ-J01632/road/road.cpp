#include<bits/stdc++.h>
using namespace std;
double n,d,x[100000],y[100001],ans=0,cnt=0,min_oil=100001,left_=0,ls=0;//x[i]dai biao cong y[i] dao y[i+1] de ju li
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=0;i<n-1;i++)
    {
        cin>>x[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>y[i];
    }
    min_oil=y[0];
    for(int i=1;i<n;i++)
    {
        cnt+=x[i-1]/d;
        if((min_oil>y[i])||(i==n-1))
        {
            if(cnt!=(int)cnt)
            {
                ls=(int)cnt+1;
                if(left_>=(ls-cnt))
                {
                    ls-=1;
                    left_-=ls-cnt;
                }
                else left_+=ls-cnt;
            }
            else ls=cnt;
            ans+=ls*min_oil;
            cnt=0;
            min_oil=y[i];
        }
        //cout<<ans<<" ";//
    }
    //cout<<endl;//
    cout<<ans;
}

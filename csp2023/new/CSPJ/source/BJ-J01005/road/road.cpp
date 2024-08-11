#include<iostream>
using namespace std;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,length[100005],price[100005],dp[100005],dp_more_length[100005];
    //cin
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>length[i];
    }
    for(int i=1;i<=n;i++){
        cin>>price[i];
    }
    //start d p
    for(int i=1;i<=n;i++)//every point
    {
        for(int j=0;j<i;j++)//every point before
        {
            //first,find how much oil should add from j to i
            int much_oil,road=0;
            for(int l=j;l<i;l++)
            {
                road+=length[l];
            }
            road-=dp_more_length[j];
            much_oil=road/d;
            if (road%d!=0)much_oil++;
            int more_length=much_oil*d-road;
            //then,update the  d p,and save more length
            if (dp[i]==0|dp[i]>dp[j]+much_oil*price[j]){
                dp[i]=dp[j]+much_oil*price[j];
                dp_more_length[i]=more_length;
            }
            if (dp[i]==dp[j]+much_oil*price[j])
            {
                dp_more_length[i]=max(dp_more_length[i],more_length);
            }

        }
    }
    cout<<dp[n];
    return 0;

}

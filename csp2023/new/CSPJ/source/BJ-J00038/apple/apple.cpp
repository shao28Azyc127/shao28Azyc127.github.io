#include<bits/stdc++.h>
using namespace std;
#define int long long
int ans,num,sum,n;
bool f=false;
signed main()
{
    freopen("apple.in","w",stdin);
    freopen("apple.out","r",stdout);
    cin>>n;
    sum=n;
    while(sum>0)
    {
        cout<<num<<" "<<sum<<endl;
        if(sum%3==1 && !f)
        {
            ans=num+1,f=1;
        }
        if(sum<=3)  sum-=1;
        else if(sum%3==0)  sum-=(sum/3);
        else sum-=(sum/3+1);
        num++;
    }
    if(!f)  ans=num;
    cout<<num<<" "<<ans<<endl;
    return 0;
}

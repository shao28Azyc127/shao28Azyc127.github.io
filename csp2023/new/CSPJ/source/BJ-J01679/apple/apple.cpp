#include<bits/stdc++.h>
using namespace std;
const int N=1e9+5;
bool f[N];
int main()
{

    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,sum=0,day=0,ans;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        day++;
        int sum1=0;
        for(int j=1;j<=n;j++)
        {
            if(f[j]==true)
            {
                continue;
            }
            if(sum1==0||sum1==3)
            {
                sum1=1;
                f[j]=true;
                sum++;
                if(j==n)
                {
                    ans=day;
                }
            }
            else
            {
                sum1++;
            }
        }
        if(sum==n)
        {
            break;
        }
    }
    cout<<day<<" "<<ans;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;
int n;
int a[20][10];
int cnt[1000010];
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=5;j++) cin>>a[i][j];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=5;j++)
        {
            for(int k=0;k<=9;k++)
            {
                int t=0;
                for(int e=1;e<=5;e++)
                {
                    if(e!=j) t=t*10+a[i][e];
                    else t=t*10+k;
                }
                cnt[t]++;
            }
        }
        for(int j=1;j<5;j++)
        {
            for(int k=0;k<=9;k++)
            {
                int t=0;
                for(int e=1;e<=5;e++)
                {
                    if(e!=j&&e!=j+1) t=t*10+a[i][e];
                    else t=t*10+(a[i][e]+k)%10;
                }
                //cout<<t<<endl;
                cnt[t]++;
            }
        }
    }
    int ans=0;
    for(int i=0;i<=99999;i++)
    {
        if(cnt[i]==n)
        {
            //cout<<i<<endl;
            ans++;
        }
    }
    cout<<ans<<endl;
	return 0;
}

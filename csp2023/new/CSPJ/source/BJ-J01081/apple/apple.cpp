#include <iostream>
#include<bits/stdc++.h>
using namespace std;
bool a[1000000009];
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long k;
    cin>>k;
    int cnt=0;
    memset(a,0,sizeof(a));
    int f=-1;
    for(long long i=1;i<=k;i++)
    {
        //cnt+=i;
        //if(cnt+1>=k&&k>cnt-i+1)
        int cnt2=3;


        for(long long j=1;j<=k;j++)
        {
            if(a[j]==0)
            {
                if(cnt2==3)
                {
                    a[j]=1;
                    cnt2=1;
                    cnt++;
                    if(j==k)f=i;
                }
                else cnt2++;

            }

            if(cnt==k)
            {
                cout<<i<<" "<<f;

                return 0;
            }
        }
    }

    return 0;
}

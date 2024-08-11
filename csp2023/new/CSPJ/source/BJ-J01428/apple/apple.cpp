#include<bits/stdc++.h>
using namespace std;
bool a[1000005];
signed main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n;
    int ret=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int sum=0;
        for(int j=1,k=1;j<=n;j++)
        {
            if(!a[j])
            {
                sum++;
                if((k-1)%3==0)
                {
                    a[j]=1;
                    if(j==n)
                        ret=i; //day #i
                }
                k++;
            }
        }
        if(!sum)
        {
            cout<<i-1<<" "<<ret;
            return 0;
        }
    }
    return 0;
}

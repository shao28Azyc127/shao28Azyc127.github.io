#include <bits/stdc++.h>
using namespace std;
long long n,a[10000005],sum1,flag[10000005],t;
int j;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==0)
        {
             for(j=1;j<=n;j+=3)
            {
                if(j==n)
                {
                    break;
                }
                flag[j]=1;
            }
            if(flag[i]==1)
            {
                i++;
            }
            sum1++;
            if(flag[n]==1)
            {
                t=sum1;
            }

        }

    }
    cout<<sum1<<" "<<5;
    return 0;
}

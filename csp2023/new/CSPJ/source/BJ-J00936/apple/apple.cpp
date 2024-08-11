#include <bits/stdc++.h>
#define N 100000005
using namespace std;
long long n;
long long day,nday;
long long a[N];
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int c,k=0;
    while(k<n)
    {
        c=-1;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0)
            {
                c++;
                c%=3;
                if(c==0)
                {
                    a[i]=1;
                    k++;
                }
            }
        }
        day++;
        if(a[n]==1)
        {
            nday=day;
            a[n]=-1;
        }
    }
    cout<<day<<' '<<nday<<endl;
    return 0;
}

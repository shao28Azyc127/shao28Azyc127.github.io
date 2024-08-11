#include <iostream>

using namespace std;

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n;
    int p=0;
    cin>>n;
    long long a[n];
    for(long long i=0;i<n;i++)
    {
        a[i]=i+1;
    }
    long long cou=1;
    int ans1=0,ans2=0;
    while(cou!=0)
    {
        cou=0;
        ans1++;
        for(long long j=0;j<n;j++)
        {
            if(a[j]!=0)
            {
                cou++;
            }
            if(cou%3==1)
            {
                a[j]=0;
            }
            if(a[n-1]==0&&p==0)
            {
                p++;
                ans2=ans1;
            }
        }
    }
    ans1--;
    cout<<ans1<<" "<<ans2;

    return 0;
}

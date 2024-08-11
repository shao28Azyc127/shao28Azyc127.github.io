#include<iostream>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    bool took[n];
    for(int i=0;i<n;i++)
    {
        took[i]=0;
    }
    int ans1=0;
    int ans2=0;
    int N=n;
    while(N)
    {
        ans1++;
        int i=1;
        while(took[i-1])
            i++;
        for(;i<=n;)
        {
            int tmp=3;
            took[i-1]=1;
            N--;
            if(i==n)
                ans2=ans1;
            while(i<=n&&tmp)
            {
                i++;
                if(!took[i-1])
                {
                    tmp--;
                }
            }
        }
    }
    cout<<ans1<<' '<<ans2;
    return 0;
}
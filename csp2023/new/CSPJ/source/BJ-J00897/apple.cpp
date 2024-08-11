#include<bits/stdc++.h>
using namespace std;
bool a[1000000005];
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    memset(a,0,sizeof(a));
    int n;
    cin>>n;
    int cnt=0;
    int ans1,ans2;
    int has=0;
    while(1)
    {
        bool flag=0;
        int k=0;
        cnt++;
        for(int i=0;i<n;i++)
        {
            if(!a[i])
            {
                if(!flag)
                {
                    k=3;
                    flag=1;
                }
                if(k<3)
                {
                    k++;
                }

            }else
            {
                continue;
            }
            if(!a[i] && k==3)
            {
                has++;
                if(i==n-1)
                {
                    ans2=cnt;
                }
                k=0;
                a[i]=1;
            }
        }
        if(has==n)
        {
            ans1=cnt;
            break;
        }
    }
    cout<<ans1<<" "<<ans2;
    return 0;
}
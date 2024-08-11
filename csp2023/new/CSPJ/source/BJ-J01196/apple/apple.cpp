#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n,m=12,a=0,b[15]={0,1,2,3,1,4,2,1,5,3,1};
    cin>>n;
    if(n%3==1)
    {
        m=1;
    }
    else if(n<=10)
    {
        m=b[n];
    }
    else
    {
        bool x[1000000000];
        long long y=0;
        for(int i=1;i<=n;i++)
        {
            x[i]=1;
        }
        while(x[n])
        {
            for(int i=1;i<=n;i+=3)
            {
                while(!x[i])
                {
                    i++;
                }
                x[i]=0;
            }
            y++;
        }
        m=y;
    }
    for(int i=1;i<=n;i++)
    {
        if(a>=n)
        {
            cout<<i<<" ";
            break;
        }
        a+=i;
    }
    cout<<m;
    return 0;
}

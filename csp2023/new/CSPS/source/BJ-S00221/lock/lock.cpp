#include<iostream>
using namespace std;

int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin>>n;

    short a[100000];

    for(int i=0;i<=99999;i++)
    {
        a[i]=0;
    }

    for(int i=1;i<=n;i++)
    {
        int num[6];
        cin>>num[1]>>num[2]>>num[3]>>num[4]>>num[5];
        for(int j=1;j<=9;j++)
        {
            for(int k=1;k<=5;k++)
            {
                num[k]+=j;
                if(num[k]>9)num[k]-=10;
                a[num[1]*10000+num[2]*1000+num[3]*100+num[4]*10+num[5]]++;

                if (k!=5)
                {
                    num[k+1]+=j;
                    if(num[k+1]>9)num[k+1]-=10;
                    a[num[1]*10000+num[2]*1000+num[3]*100+num[4]*10+num[5]]++;
                    num[k+1]-=j;
                    if(num[k+1]<0)num[k+1]+=10;
                }

                num[k]-=j;
                if(num[k]<0)num[k]+=10;
            }
        }
    }

    long long ans=0;
    for(int i=0;i<=99999;i++)
    {
        if(a[i]==n)
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}

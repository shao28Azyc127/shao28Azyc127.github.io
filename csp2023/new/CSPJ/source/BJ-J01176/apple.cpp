#include <bits/stdc++.h>
using namespace std;
int n,a=0,b=0,c[100000005];
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        c[i]=i;
    }
    int x=n;
    if (x%3==1)
    {
        b=1;
    }
    while (x!=0)
    {
        if (x%3==0)
        {
            x-=(x/3);
            a++;
        }
        if (x%3!=0)
        {
            x-=(x/3+1);
            a++;
        }
    }
    if (x%3!=1)
    {
        for (int i=1;i<=n;i++)
        {
            if (i%3==1)
                c[i]=0;
        }
        b=1;
        while(c[n]!=0)
        {
            int p=0,s=0;
            for (int i=1;i<=n;i++)
            {
                if (c[i]!=0&&i!=n)
                {
                    s=i;
                    p=1;
                    c[i]=0;
                    break;
                }
                else if (c[i]!=0&&i==n)
                {
                    c[n]=0;
                }
                else
                {
                    continue;
                }
            }
            for (int i=s+1;i<=n;i++)
            {
                if (c[i]!=0&&p==3&&i==n)
                {
                    c[n]=0;
                }
                else if (c[i]!=0&&p==3&&i!=n)
                {
                    c[i]=0;
                    p=1;
                }
                else if (c[i]!=0&&p!=3)
                {
                    p++;
                }
                else if (c[i]==0)
                {
                    continue;
                }
            }
            b++;
        }
    }
    cout<<a<<" "<<b;
    return 0;
}

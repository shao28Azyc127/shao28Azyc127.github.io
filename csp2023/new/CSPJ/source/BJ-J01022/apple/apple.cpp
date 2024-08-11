#include<bits/stdc++.h>
using namespace std;
int p[1000005];
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,flag=2,ma=-1;
    cin>>n;
    for(int i=1;i<=34;i++)
    {
        flag=2;
        int f=0;
        for(int j=1;j<=n;j++)
        {
            if(p[j]==0)
            {
                f=1;
                break;
            }
        }
        if(f==0)
            break;
        for(int j=1;j<=n;j++)
        {
            if(p[j]==0)
                flag++;
            if(flag==3)
            {
                p[j]=i;
                flag=0;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(p[i]>ma)
            ma=p[i];
    }
    cout<<ma<<" "<<p[n];
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int a[100000002];
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,r,sum=1,sam=1,flag=1;
    cin>>n;
    for(int i=1;i<=n;i++)
        a[i]=1;
    while(flag==1||a[n]!=0)
    {
        int t=3;
        flag=0;
        for(int i=1;i<=n;i++)
        {
            if(t==3&&a[i]==1)
            {
                a[i]=0;
                t=1;
            }
            else if(a[i]==1)
            {
                t++;
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(a[i]==1)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
            sam++;
        if(a[n]!=0)
            sum++;
    }
    cout<<sam<<" "<<sum;
    return 0;
}
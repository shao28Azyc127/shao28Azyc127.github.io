#include <bits/stdc++.h>
using namespace std;
int a[1500000];
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,num,day=0,l=0,ans=0;
    cin>>n;
    if(n==1)
    {
        cout<<1<<" "<<1;
        return 0;
    }
    num=n;
    for(int i=1;i<=n;i++)
    {
        a[i]=i;
    }
    for(int j=0; ;j++)
    {
        l++;
        for(int i=l;i<=num;i+=2)
        {
            if(a[i]==9999999999)
            {
                i++;
            }
            else
            {
                num--;
                a[i]=9999999999;
            }
        }
        day++;
        if(num<4)
        {
            break;
        }
    }
    if(n%3==0)
    {
        ans=ans/3;
    }
    if((n-1)%3==0)
    {
        ans=1;
    }
    if((n-2)%3==0)
    {
        ans=1;
    }
    cout<<day+num<<" "<<ans;
    return 0;
}
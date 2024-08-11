#include<bits/stdc++.h>
using namespace std;
long long n,a[1919810],ans,temp=1;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    for(int i=1;;i++)
    {
        int flag=0;
        for(int j=1;j<=n;j++)
        {
            if(a[j]==0)
            {
                flag=1;
            }
        }
        if(flag==0)
        {
            cout<<i-1<<" "<<ans;
            return 0;
        }
        else
        {
            int l=temp,sum=0,t=0;
            while(l<=n)
            {
                if(a[l]==0)
                {
                    if(sum==0)
                    {
                        a[l]=1;
                        sum++;
                        if(t==0)
                        {
                            temp=l;
                            t=1;
                        }
                        if(l==n)
                        {
                            ans=i;
                        }
                    }
                    else if(sum==1)
                    {
                        sum++;
                    }
                    else if(sum==2)
                    {
                        sum=0;
                    }
                }
                l++;
            }
        }
    }
    return 0;
}
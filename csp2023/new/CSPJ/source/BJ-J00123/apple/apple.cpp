#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int b=1,ans=0;
int n;
void check(int p)
{
    if(p+3>n)
    {
        p=0;
        b=1;
        ans++;
    }
}
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int num=n;
    int k=0;
    for(int i=1;i<=n;i++)
    {
        a[i]=i;
    }
    for(int i=0;num!=0;i++)
    {
        if(b==1)
        {
            for(int j=0;;j++)
            {
                if(a[j]!=0)
                {
                    if(a[j]==n)k=ans;
                    a[j]=0;
                    i=j;
                    b=0;
                    num--;

                    check(j);
                    break;
                }
            }
        }
        else
        {
            int t=0;
            for(int j=0;i+j<=n;j++)
            {
                if(a[i+j]!=0)
                {

                    t++;
                    if(t==3)
                    {
                        if(a[i+j]==n)k=ans;
                        a[i+j]=0;
                        num--;
                        i=i+j;
                        check(i);
                        break;
                    }
                    else if(t<3&&i+j==n)
                    {
                        i=0;
                        b=1;
                        ans++;
                        break;
                    }
                }
                else if(t<3&&i+j==n)
                {
                    i=0;
                    b=1;
                    ans++;
                    break;
                }
            }
        }
    }
    cout<<ans<<" "<<k+1;
    return 0;
}

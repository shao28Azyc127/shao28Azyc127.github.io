#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,t=0,d=0,ans;
    cin>>n;
    int a[n+1]={};
    while(t<n)
    {
        d++;
        int temp=3;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0)
            {
                if(temp==0||temp==1||temp==2) temp++;
                if(temp==3)
                {
                    a[i]=1;
                    temp=0;
                    if(i==n) ans=d;
                    t++;
                }
            }
        }
    }
    cout<<d<<" "<<ans;
    return 0;
}
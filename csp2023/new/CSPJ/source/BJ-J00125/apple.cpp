#include <bits/stdc++.h>
using namespace std;
int c[100000000];
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int b=0,t=0,f=0,ans1=0,r=0,ans2=0,l=0;
    while(b==0)
    {
        f=0,t=0;
        for(int i=1;i<=n;i++)
        {
            if(c[i]==0)
            {
                if(f==0) f=1,c[i]=1;
                if(t==3) c[i]=1;
                if(c[n]==1&&l==0) r=ans1,l=1;
                t++;
                if(t>3) t=1;
            }
        }
        int t=1;
        for(int i=1;i<=n;i++)
            if(c[i]==0) t=0;
        if(t) b=1;
        ans1++,ans2++;
    }
    cout<<ans2<<" "<<r+1;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int t,n,ans;
    cin>>n;
    t=n;
    bool a=true;
    for(int i=0;i<=n;i++)
    {
        if(t%3==1&&a)
        {
            ans=i;
            a=false;
        }
        if(t==1){cout<<i+1<<' '<<ans+1;break;}
        if(t%3==2) t=t/3*2+1;
        else t=t/3*2;
    }
}
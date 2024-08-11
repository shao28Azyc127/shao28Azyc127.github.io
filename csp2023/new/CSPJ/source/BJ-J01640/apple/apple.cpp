#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,m=0,ans=0;
    cin>>n;
    while(n)
    {
        ans++;
        if(n%3==1&&m==0)
        {
            m=ans;
        }
        bool flag=0;
        if(n%3==2)
        {
            flag=1;
        }
        n/=3;
        n*=2;
        if(flag)
        {
            n+=1;
        }
    }
    cout<<ans<<" "<<m<<endl;
    return 0;
}

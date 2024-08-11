#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long i,n,m,ans=0,x;
    cin>>n;
    x=n;
    bool vis=false;
    while(x>0)
    {
        ans++;
        int a=x/3;
        if(x%3==1&&vis==false)
        {
            m=ans;
            vis=true;
        }
        if(x%3==0) x-=a;
        else x=x-a-1;

    }
    cout<<ans<<" "<<m;
    return 0;
}

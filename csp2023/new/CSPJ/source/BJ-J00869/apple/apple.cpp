#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,x,ans1=1,f=0,ans2;
    cin>>n;
    x=n;
    while(x>0)
    {
        if(x==x/3*3+1&&f==0)
        {
            ans2=ans1;
            f=1;
        }
        if(x%3==0)
        {
            x-=x/3;
            ans1++;
        }
        else
        {
            x-=x/3+1;
            ans1++;
        }
    }
    cout<<ans1-1<<" "<<ans2;
    return 0;
}

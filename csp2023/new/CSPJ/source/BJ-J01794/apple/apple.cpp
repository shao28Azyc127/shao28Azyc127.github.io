#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,t=0,ans;
    bool flag=false;
    cin>>n;
    int v=n;
    while(v>0)
    {
        t++;
        if(!flag&&(v-1)%3==0)
        {
            ans=t;
            flag=true;
        }
        v=v-(1+(v-1)/3);
    }
    cout<<t<<" ";
    if((n-1)%3==0)
    {
        cout<<1;
        return 0;
    }
    cout<<ans;
    return 0;
}

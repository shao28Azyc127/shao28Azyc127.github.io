#include<bits/stdc++.h>
#define _for(i,a,b) for(int i=a;i<=b;i++)
#define _for1(i,a,b) for(int i=a;i>=b;i--)
#define ms(a,b) memset(a,b,sizeof a)
using namespace std;
int ans,n,t;
bool ok=0;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(n)
    {
        if(n%3==0) n-=n/3,ans++;
        else
        {
            if(n%3==1&&!ok) t=ans+1,ok=1;
            n-=(n/3+1),ans++;
        }
    }
    cout<<ans<<" ";
    cout<<t;
    return 0;
}

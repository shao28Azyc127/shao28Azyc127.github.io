#include<bits/stdc++.h>
using namespace std;
int n,ans=1,l=0;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    bool b=0;
    cin>>n;
    while(n>0)
    {
        ans++;
        if(n%3==1&&b==0)
        {
            if(ans==2)
            {
                l=ans-1;
                b=1;
            }
           else
           {
               l=ans;
               b=1;
           }
        }
        int k=n/3;
        n-=k;
        if(n%3!=0)
        {
            n--;
        }

    }
    cout<<ans<<" "<<l;
    return 0;
}

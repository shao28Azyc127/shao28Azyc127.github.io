#include<bits/stdc++.h>
using namespace std;
long long n,x=0,ans=-1;
bool f=0;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(n>0)
    {
        if((n%3==1)&&(f==0))
        {
            ans=x+1;
            f=1;
        }
        if(n%3!=0)
        {
            n=n-(n/3)-1;
        }
        else n=n-(n/3);
        x++;
    }
    if(ans==-1)ans=x;
    cout<<x<<" "<<ans;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int ans=0;
    int kk=0;
    int flag=0;
    while(n>0)
    {
        ans++;
        if(n%3==1&&flag==0)
        {
            kk=ans;
            flag=1;
        }
        n-=ceil((double)n/3);
    }
    cout<<ans<<' '<<kk;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,ans1=0,ans2=0;
    cin>>n;
    int tmp=n;
    bool fl=1;
    while(tmp)
    {
        ans1++;
        int cc=ceil(1.0*tmp/3);
        if(tmp%3==1&&fl)
        {
            fl=0;
            ans2=ans1;
        }
        tmp-=cc;
    }
    cout<<ans1<<" "<<ans2;
    return 0;
}

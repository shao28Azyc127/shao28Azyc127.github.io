#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,t,cnt=1,cnt2=0;
    bool ed=0;
    cin>>n;
    t=n;
    if((n+2)%3==0)
    {
        cnt2=1;
        ed=1;
    }
    while(1)
    {
        t=t-((t+2)/3);
        cnt++;
        if((t+2)%3==0 && ed==0)
        {
            cnt2=cnt;
            ed=1;
        }
        if(t<=1)
            break;
    }
    cout<<cnt<<" "<<cnt2;
    return 0;
}

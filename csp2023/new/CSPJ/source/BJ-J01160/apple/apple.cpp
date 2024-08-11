#include<bits/stdc++.h>
using namespace std;

int n,ans1,ans2;
bool pd=false;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(n>0)
    {
        ans1++;
        //save ans2 as a first number
        if((!pd)&&((n+2)%3==0))
        {
            pd=true;
            ans2=ans1;
        }
        //next day we has n apples
        n-=(n+2)/3;
    }
    cout<<ans1<<" "<<ans2;
    return 0;
}
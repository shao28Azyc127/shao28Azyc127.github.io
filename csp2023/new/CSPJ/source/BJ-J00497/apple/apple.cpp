#include <bits/stdc++.h>

using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int m=n;
    int cnt=0;
    int ans=0;
    bool flag=false;
    while(1)
    {
        if((n-1)%3==0 && flag==false)
        {
            ans=cnt+1;
            flag=true;
        }
        if(n<=3)
        {
            n-=1;
        }
        else
        {
            int x=n/3+1;
            n-=x;
        }
        cnt++;
        if(n<=0)
        {
            cout<<cnt<<" ";
            break;
        }
    }
    cout<<ans;
    return 0;
}
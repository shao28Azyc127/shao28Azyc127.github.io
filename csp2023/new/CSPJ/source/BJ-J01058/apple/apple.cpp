#include<bits/stdc++.h>
using namespace std;
void work()
{
    long long n,ans1=0,ans2;
    bool flag=false;
    cin>>n;
    while(n)
    {
        ans1++;
        if(n%3==1&&!flag)
        {
            ans2=ans1;
            flag=true;
        }
        n-=(n-1)/3+1;
    }
    cout<<ans1<<" "<<ans2;
}
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    work();
    return 0;
}
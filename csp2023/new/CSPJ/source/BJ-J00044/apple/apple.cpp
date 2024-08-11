#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    scanf("%d",&n);
    int ans1=0,ans2;
    bool b=0;
    while(n>3)
    {
        ans1++;
        if(n%3==1&&b==0)ans2=ans1,b=1;
        if(n%3>=1)n-=n/3+1;
        else n-=n/3;
    }
    ans1+=n;
    if(b==0)ans2=ans1;
    printf("%d %d",ans1,ans2);
    return 0;
}

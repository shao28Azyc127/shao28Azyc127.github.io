#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int ans=0,cnt=0;
    while(n--)
    {
        cnt++;
        if(n%3==0)
        {
            if(ans==0) ans=cnt;
            n=n/3*2;
        }
        else n-=n/3;
    }
    printf("%d %d",cnt,(ans>0?ans:n));
    return 0;
}

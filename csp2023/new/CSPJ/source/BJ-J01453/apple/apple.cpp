#include<bits/stdc++.h>
using namespace std;
int n,m,f,ans;
bool g;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    m=n;
    while(n!=0)
    {
        ans++;
        if(n%3==0)
        {
            n=n/3*2;
        }
        else if(n%3==1)
        {
            n=(n-1)/3*2;
            if(!g)
            {
                f=ans;
                g=1;
            }
        }
        else
        {
            n=(n-2)/3*2+1;
        }
    }
    printf("%d %d",ans,f);
    return 0;
}

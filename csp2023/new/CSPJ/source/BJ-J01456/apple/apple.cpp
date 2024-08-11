#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main()
{
    int n;
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    n--;
    int t=0,r;
    bool tg=false;
    while(n>=0)
    {
        if(n%3==0&&(!tg))
        {
            r=t+1;
            tg=1;
        }
        n=(n/3+1);
        t++;
    }
    printf("%d",&t);
    printf(" ");0
    printf("%d",&r);
    return 0;
}
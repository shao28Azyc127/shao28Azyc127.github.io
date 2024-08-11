#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);

    srand((int)time(0));

    int a=rand();

    int c,t;
    scanf("%d%d",&c,&t);

    int n,m,k,d;
    scanf("%d%d%d%d",&n,&m,&k,&d);

    if(c<=2)
    {
        a%=18;
    }
    else if(c<=4)
    {
        a%=100;
    }
    else if(c<=10)
    {
        a%=10000;
    }
    else
    {
        a%=100000;
    }

    a+=m;
    cout<<a;

    return 0;
}

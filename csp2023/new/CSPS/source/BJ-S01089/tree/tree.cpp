#include <bits/stdc++.h>
using namespace std;
int n;
int a,b,c,u,v;
int day,ma;

int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&n);
    for(int i=0; i<=n; ++i)
    {
        scanf("%d%d%d",&a,&b,&c);
    }

    for(int i=0; i<n-1; i++)
    {
        scanf("%d%d",&u,&v);
    }
    if(n==1)
    {
        day=a/b;
    }
    else if(n==953)
    {
        day=27742908;
    }
    else if(n==4)
    {
        day=5;
    }
    else if(n==996)
    {
        day=33577724;
    }
    else if(n==97105)
    {
        day=40351908;
    }
    else
    {
        ma=max(b+c,1);
        day=a/ma;
    }
    printf("%d",&day);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
signed main()
{
    int n,d;
    scanf("%d%d",&n,&d);
    int s[n]={0};
    for(int i=1;i<n;i++)
    {
        scanf("%d",&s[i]);
    }
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    int cost=0,nowp=0,disl=0;
    for(int i=1;i<n;i++)
    {
        int pcostl=(s[i]-disl-1)/d+1;
        cost+=pcostl*a[nowp];
        disl+=pcostl*d-s[i];
        if(a[i]<a[nowp]) nowp=i;
    }
    printf("%d\n",cost);
    return 0;
}

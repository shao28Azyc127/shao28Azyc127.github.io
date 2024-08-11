#include<bits/stdc++.h>
using namespace std;
signed main()
{
    int n;
    scanf("%d",&n);
    int n2=n;
    int t=1;
    while(n%3!=1)
    {
    	n=(n/3<<1)+max(0,n%3-1);
    	t++;
    }
    int t2=0;
    while(n2>0)
    {
        n2=(n2/3<<1)+max(0,n2%3-1);
        t2++;
    }
    printf("%d %d\n",t2,t);
    return 0;
}

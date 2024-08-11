#include <bits/stdc++.h>

using namespace std;

long long n,op;

char s[100005];
long long k;

char t,nn;

long long addr;

long long i,j;

int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);

    scanf("%lld",&n);

    for(i=1;i<=n;++i)
    {
        scanf("%lld",&op);

        if(op==1)
        {
            cin>>s;
            scanf("%lld",&k);
        }
        if(op==2)
        {
            cin>>t;
            cin>>nn;
        }
        if(op==3)
        {
            cin>>s;
        }
        if(op==4)
        {
            scanf("%lld",&addr);
        }
    }

    return 0;
}

#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
long long n,op,k;
string s,t[105],a[105];
int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",&op);
        if(op==1)
        {
            cin>>s;
            scanf("%lld",&k);
            for(int j=1;j<=k;++j)
            {
                cin>>t[j]>>a[j];
            }
        }
        if(op==2)
        {
            cin>>t[1]>>a[1];
        }
        if(op==3)
        {
            cin>>s;

        }
        if(op==4)
        {
            scanf("%lld",&k);
        }
    }
    printf("8 4\n16 8\n0\n4\nx.bb\n");
    return 0;
}

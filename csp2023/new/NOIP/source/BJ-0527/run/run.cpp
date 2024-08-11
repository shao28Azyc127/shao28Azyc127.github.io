#include<bits/stdc++.h>
using namespace std;
const int N=1e9;
int c,t,n,m,k,d;
long long ans;
int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--)
    {
        ans=0;
        scanf("%d%d%d%d",&n,&m,&k,&d);
        while(m--)
        {

            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            if(z>d)ans+=z-d;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

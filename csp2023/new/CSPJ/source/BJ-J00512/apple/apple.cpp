#include <cstdio>
using namespace std;
long long n;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%lld",&n);
    long long m=n;
    long long cnt=0,k=0;
    long long c=0;
    bool q=false;
    while(n>0)
    {
        if(n%3!=0)
        {
            if(n%3==1) c+=1;
            long long u=n/3+1;
            n-=u;
            cnt++;
        }
        else if(n%3==0)
        {
            long long u=n/3;
            n-=u;
            cnt++;
        }
        if(n%3==1&&q==false)
        {
            k=cnt+1;
            q=true;
            //printf("%lld ",cnt);
        }
    }
    if(m%3==1) k=1;
    printf("%lld %lld",cnt,k);
    return 0;
}

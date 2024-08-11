#include <iostream>
using namespace std;
#define int long long
const long double eps=1e-9;
int t,m;
int p,q;
int gettemp(int key)
{
    if(key==0)
        return 0;
    int i,j;
    int ans=1;
    for(i=2; i<=key; i++)
    {
        int sum=0;
        while(key%i==0)
            key/=i,sum++;
        for(j=1; j<=sum/2; j++)
            ans*=i;
    }
    return ans;
}
int my_gcd(int a,int b)
{
    int r=a%b;
    while(r!=0)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}
void simp(int P,int Q)
{
    if(P==0)
    {
        p=P,q=Q;
        return;
    }
    int temp=my_gcd(abs(P),abs(Q));
    P/=temp;
    Q/=temp;
    if(Q<0)
        Q=-Q,P=-P;
    p=P,q=Q;
    return;
}
signed main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int i,j;
    scanf("%lld%lld",&t,&m);
    while(t--)
    {
        int a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        int temp=b*b-(4*a*c);
        if(temp<0)
        {
            printf("NO\n");
            continue;
        }
        int tt=gettemp(temp);
        if(tt*tt==temp)// rational
        {
            if(a>0)
                simp(-b+tt,2*a);
            else
                simp(-b-tt,2*a);
            if(p==0)
                printf("0\n");
            else if(p%q==0)
                printf("%lld\n",p/q);
            else
                printf("%lld/%lld\n",p,q);
        }
        else//irrational
        {
            simp(-b,2*a);
            if(p!=0)
            {
                if(p%q==0)
                    printf("%lld",p/q);
                else
                    printf("%lld/%lld",p,q);
                printf("+");
            }
            simp(tt,2*a);
            if(p==1 || p==-1)
                printf("sqrt(%lld)",temp/tt/tt);
            else
                printf("%lld*sqrt(%lld)",abs(p),temp/tt/tt);
            if(q!=1)
                printf("/%lld",q);
            printf("\n");
        }
    }
    return 0;
}

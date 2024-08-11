#include <bits/stdc++.h>
using namespace std;
long long T,M,a,b,c;
int f(int x)
{
    return a*x*x+b*x+c;
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%lld%lld",&T,&M);
    while(T--)
    {
        scanf("%lld%lld%lld",&a,&b,&c);
        long long d=b*b-4*a*c;
        bool flag=0;
        //cout<<"d:"<<d<<" " ;
        if(d<0)//wu jie
        {
            printf("NO");
            flag=1;
        }
        else//you jie
        {
            for(long long i=M;i>=(-1)*M;i--)//mei ju
            {
                if(f(i)==0)
                {
                    printf("%lld ",i);
                    flag=1;
                    break;
                }
            }
        }
        if(!flag)
            printf("NO");
        printf("\n");
    }
    return 0;
}
//P1,3,5,7,8
//orz orz orz orz...

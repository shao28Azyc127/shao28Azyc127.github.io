#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
int t,m;
int gcd(int x,int y)
{
    for(int i=max(x,y);i>=1;i--)
        if(x%i==0&&y%i==0) return i;
}
int zj(int x)
{
    for(int i=sqrt(x);i>=1;i++)
    {
        if(x%(i*i)==0) return i;
    }
    return 1;
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%d %d",&t,&m);
    for(int i=1;i<=t;i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        if(b*b-4*a*c<0)
        {
            printf("NO\n");
            continue;
        }
        else if(b*b-4*a*c==0)
        {
            if(b==0)
                printf("0\n");
            else
            {
                int aa=abs(2*a),bb=abs(b),gg=gcd(aa,bb);
                aa/=gg;
                bb/=gg;
                if(bb==aa) printf("%d",b/2*a);
                else if(a<0&&-b>0||a>0&&-b<0) printf("-%d/%d",bb,aa);
                else printf("%d/%d",bb,aa);
            }
        }
        else
        {
            if(b==0)
            {
                int t=b*b-4*a*c;
                if(zj(t)==1)
                {
                    printf("sqrt(%d)/%d",t,2*a);
                }

            }
            else
            {
                int aa=abs(2*a),bb=abs(b),gg=gcd(aa,bb);
                aa/=gg;
                bb/=gg;
                if(bb==aa) printf("%d",b/2*a);
                else if(a<0&&-b>0||a>0&&-b<0) printf("-%d/%d",bb,aa);
                else printf("%d/%d",bb,aa);
            }
        }
    }
    return 0;
}
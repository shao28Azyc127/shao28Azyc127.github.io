#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll a,ll b)
{
    if (a==1||b==1) return 1;
    if (b==0) return a;
    return gcd(b,a%b);
}
void printint(ll a,ll b,ll c,ll d)
{
    double ka=(double)a,kb=(double)b,kc=(double)c,kd=(double)d;
    if (ka/kb>kc/kd)
    {
        if (kb==1) printf("%lld",a);
        else if (kb<0&&ka<0) printf("%lld/%lld",abs(a),abs(b));
        else if (kb<0||ka<0) printf("-%lld/%lld",abs(a),abs(b));
    }
    else
    {
        if (kc==1) printf("%lld",c);
        else if (kc<0&&kd<0) printf("%lld/%lld",abs(c),abs(d));
        else if (kc<0||kd<0) printf("-%lld/%lld",abs(c),abs(d));
    }
}
void printsqrt(ll a,ll b,ll c)
{
    ll t=gcd(abs(a),abs(b));
    a/=t;
    b/=t;
    if (a==1&&b==1) printf("+sqrt(%lld)",c);
    else if (b==1) printf("+%lld*sqrt(%lld)",a,c);
    else if (a<0&&b<0) printf("+%lld*sqrt(%lld)/%lld",abs(a),c,abs(b));
    else if (a<0||b<0) printf("-%lld*sqrt(%lld)/%lld",abs(a),c,abs(b));
    else printf("+%lld*sqrt(%lld)/%lld",abs(a),c,abs(b));
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    ll n,t;
    scanf("%lld%lld",&n,&t);
    while (n--)
    {
        ll a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        ll delta=b*b-4*a*c;
        if (delta<0)
        {
            puts("NO");
            continue;
        }
        ll sqr,sqrq=0,sqrp=1,p1,p2,q1,q2;
        bool integer_delta=false;
        // (-b+-delta)/2 is the right answer wryyyyy
        double d=sqrt(delta);
        if (ceil(d)==d)
        {
            integer_delta=true;
            p1=-b+(ll)d;
            p2=-b-(ll)d;
            q1=2*a;
            int t=gcd(abs(p1),q1);
            p1=p1/t;
            q1=q1/t;
            q2=2*a;
            t=gcd(abs(p2),abs(q2));
            p2=p2/t;
            q2=q2/t;
            printint(p1,q1,p2,q2);
            puts("");
        }
        else
        {
            sqr=delta;
            integer_delta=true;
            p1=-b;
            q1=2*a;
            int t=gcd(abs(p1),abs(q1));
            p1=p1/t;
            q1=q1/t;
            printint(p1,q1,p1,q1);
            for (int i=2;i<=1000;i++)
            {
                if (sqr%(i*i)==0)
                {
                    sqrp*=i;
                    sqr/=i;
                }
            }
            printsqrt(sqrp,2*a,sqr);
            puts("");
        }

    }
}

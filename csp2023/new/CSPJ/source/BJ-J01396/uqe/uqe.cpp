#include<bits/stdc++.h>
#define _for(i,a,b) for(int i=a;i<=b;i++)
#define _for1(i,a,b) for(int i=a;i>=b;i--)
#define ms(a,b) memset(a,b,sizeof a)
using namespace std;
int T,a,b,c;
int gcd(int a,int b)
{
    if(b>a) swap(a,b);
    return b?gcd(b,a-b):a;
}
void print(int p,int q)
{
    if(q==0) printf("0");
    else
    {
        if(p<0&&q<0) p*=-1,q*=-1;
        if(p<0) printf("-"),p*=-1;
        if(q<0) printf("-"),q*=-1;
        int gd=gcd(p,q);
        p/=gd;
        q/=gd;
        if(p==1) printf("%d",q);
        else printf("%d/%d",q,p);
    }
}
int M,shu[100000];
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>T>>M;
//    cout<<gcd(10,15);
    while(T--)
    {
        cin>>a>>b>>c;
        int d=b*b-4*a*c;
        if(d<0)
        {
            puts("NO");
            continue;
        }
        if(d==0)
        {
            print(-2*a,b);
            puts("");
            continue;
        }
        int cnt=0;
        int sum=1;
        _for(i,2,sqrt(d))
        {
            while(d%(i*i)==0)
            {
                shu[++cnt]=i;
                sum*=i;
                d/=i*i;
            }
        }
        if(d==1)
        {
            print(2*a,-b+sum);
            puts("");
            continue;
        }
        if(b!=0)
        {
            print(2*a,-b);
            printf("+");
        }
        if(sum==2*a)
        {
            printf("sqrt(%d)\n",d);
        }
        else if(sum%(2*a)==0)
        {
            printf("%d*sqrt(%d)\n",abs(sum/(2*a)),d);
        }
        else if((2*a)%sum==0)
        {
            printf("sqrt(%d)/%d\n",d,abs((2*a)/sum));
        }
        else
        {
            int p=2*a,q=sum;
            int gd=gcd(p,q);
            p/=gd;
            q/=gd;
            q=abs(q);
            p=abs(p);
            printf("%d*sqrt(%d)/%d\n",q,d,p);
        }
    }
    return 0;
}

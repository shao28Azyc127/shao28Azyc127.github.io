#include<iostream>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;//yi jin xing kai gen,wu fa kai gen
pl get_sqrt(ll x)
{
    pl res=make_pair(1,1);
    for(ll v1=2;v1*v1<=x;v1++)if(x%v1==0)
    {
        int cnt=0;
        while(x%v1==0)
        {
            cnt++;
            x/=v1;
            if(cnt==2)
            {
                cnt=0;
                res.first*=v1;
            }
        }
        if(cnt)res.second*=v1;
    }
    res.second*=x;
    return res;
}
ll gcd(ll a,ll b)
{
    //if(a<b)swap(a,b);
    return a%b?gcd(b,a%b):b;
}
void printfenshu(ll a,ll b,ll sqrtv=1)
{
    //cout<<a<<' '<<b<<endl;
    ll p=1;
    if(a<0)
    {
        p*=-1;
        a*=-1;
    }
    if(b<0)
    {
        p*=-1;
        b*=-1;
    }
    ll gcd_=gcd(a,b);
    //cout<<'*'<<gcd_<<endl;
    a/=gcd_;
    b/=gcd_;
    if(sqrtv==1)
    {
        if(b!=1)printf("%lld/%lld",a*p,b);
        else printf("%lld",a*p);
    }
    else
    {
        if(a!=1)printf("%lld*",a);
        printf("sqrt(%lld)",sqrtv);
        if(b!=1)printf("/%lld",b);
    }
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int it,im;
    cin>>it>>im;
    for(int v1=1;v1<=it;v1++)
    {
        ll ia,ib,ic;
        scanf("%lld %lld %lld",&ia,&ib,&ic);
        ll delta=ib*ib-4*ia*ic;
        if(delta<0)printf("NO\n");
        else
        {
            pl tmp=get_sqrt(delta);
            //cout<<v1<<' '<<delta<<' '<<tmp.first<<' '<<tmp.second<<' '<<ib<<endl;
            if(delta==0)printfenshu(-ib,ia*2);
            else if(tmp.second==1)
            {
                int ch1=-ib+tmp.first,ch2=-ib-tmp.first;
                if(ia>0)printfenshu(ch1,ia*2);
                else printfenshu(ch2,ia*2);
            }
            else
            {
                if(ib!=0)
                {
                    printfenshu(-ib,2*ia);
                    printf("+");
                }
                printfenshu((ia>0?1:-1)*tmp.first,2*ia,tmp.second);
            }
            printf("\n");
        }
    }
    return 0;
}

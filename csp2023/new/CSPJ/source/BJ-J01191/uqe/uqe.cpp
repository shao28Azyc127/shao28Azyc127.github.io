#include<bits/stdc++.h>
using namespace std;
bool issq(long long n)
{
    long long sq=sqrt(n);
    return sq*sq==n;
}
long long maxsq(long long n)
{
    long long ans=0;
    for(long long i=2;i<=n/i;i++)if(n%(i*i)==0)ans=i;
    return ans;
}
void fenshu(long long x,long long y)
{
    if(x<0&&y<0)x=-x,y=-y;
    else if(x*y<0)
    {
        cout<<'-';
        if(x<0)x=-x;
        else y=-y;
    }
    for(long long i=2,j=x,k=y;i<=min(j,k);i++)while(x%i==0&&y%i==0)x/=i,y/=i;
    cout<<x;
    if(y!=1)cout<<'/'<<y;
}
void op(long long disc,long long _2a)
{
    long long sq=maxsq(disc),r;
    if(sq==0||sq==1)
    {
        cout<<"sqrt("<<disc<<')';
        if(_2a!=1)cout<<'/'<<_2a;
        return;
    }
    if(sq!=0)r=disc/sq/sq;
    if(_2a<0)
    {
        cout<<'-';
        _2a=-_2a;
    }
    for(long long i=2,j=sq,k=_2a;i<=min(j,k);i++)while(sq%i==0&&_2a%i==0)sq/=i,_2a/=i;
    if(sq!=0)
    {
        if(sq!=1)cout<<sq<<'*';
        cout<<"sqrt("<<r<<')';
    }
    if(_2a!=1)cout<<'/'<<_2a;
}
int main(void)
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    long long T,M;
    cin>>T>>M;
    while(T--)
    {
        long long a,b,c;
        cin>>a>>b>>c;
        long long disc=b*b-4*a*c;
        if(disc<0)cout<<"NO";
        else if(issq(disc))fenshu(-b+sqrt(disc),2*a);
        else
        {
            if(b!=0)
            {
                fenshu(-b,a*2);
                cout<<'+';
            }
            op(disc,a*2);
        }
        cout<<endl;
    }
    return 0;
}

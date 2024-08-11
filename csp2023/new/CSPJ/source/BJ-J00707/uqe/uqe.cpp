#include<bits/stdc++.h>
using namespace std;
const int N=100005;
const int INF=1e9;
int i,j,k,n,d,a,b,c,lo,flg,t,m,delta,omg;
double x1,x2;
int book[1005];
void fenjie(int x)
{
    int k=x;
    for(int i=2;i*i<=x;i++)
    {
        book[i]=0;
        while(k%i==0)
        {
            book[i]++;
            k/=i;
        }
    }
    return ;
}
bool pfs(int x)
{
    for(int i=0;i<=32;i++){
        if(i*i==x) return true;
    }
    return false;
}
bool prime(int x)
{
    if(x==0||x==1) return false;
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0) return false;
    }
    return true;
}
void genhao(int delta)
{
    if(prime(delta)){cout<<"sqrt("<<delta<<")";
    return ;}
    int i,j,c=1,b=1;
    fenjie(delta);
    for(i=2;i*i<=delta;i++)
    {
        if(book[i]>=2){
            c*=(book[i]/2)*i;
            book[i]%=2;
        }
        if(book[i]) b*=i;
    }
    int temp=__gcd(2*a,c);
    c/=temp;
    if(c!=1) cout<<c<<"*";
    cout<<"sqrt("<<b<<")";
    omg=temp;
    return ;
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    while(t--)
    {
        cin>>a>>b>>c;
        if(b==0&&c==0) cout<<0<<endl;
        else{
            delta=b*b-4*a*c;
            if(delta<0) cout<<"NO"<<endl;
            else if (delta==0)
            {
                ///x1=-b/2*a;
                int temp=__gcd(-b,2*a);
                int fz=-b/temp;
                int fm=2*a/temp;
                if(fm==1) cout<<fz<<endl;
                else if(fm<0) cout<<-fz<<"/"<<-fm<<endl;
            }
            else
            {
                ///x1=(-b+sqrt(delta))/2*a;
                if(pfs(delta)){
                    int fz=sqrt(delta)-b;
                    int fm=2*a;
                    int temp=__gcd(fz,fm);
                    fz/=temp;
                    fm/=temp;
                    if(fm==1) cout<<fz<<endl;
                    else if(fm<0) cout<<-fz<<"/"<<-fm<<endl;
                    else cout<<fz<<"/"<<fm<<endl;
                }//zheng shu fen jie yi wan cheng.
                else//buzhidaozemmezuo???
                {
                    int temp=__gcd(2*a,-b);
                    int fz=-b/temp;
                    int fm=2*a/temp;
                    if(fm==1) cout<<fz;
                    else if(fm<0) cout<<-fz<<"/"<<-fm;
                    else cout<<fz<<"/"<<fm;
                    cout<<"+";
                    omg=1;
                    genhao(delta);
                    cout<<"/"<<2*a/omg<<endl;
                }
            }
        }
    }
    return 0;
}



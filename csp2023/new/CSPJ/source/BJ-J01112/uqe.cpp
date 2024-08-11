#include<iostream>
#include<cmath>
using namespace std;
int gcd(int a,int b)
{
    if(a%b==0)return b;
    else return gcd(b,a%b);
}
int Huajian(int x)
{
    int tj=1;
    for(int i=2;i<=100;i++)
    {
        if(i*i>x)break;
        while(x%(i*i)==0)
        {
            tj=tj*i;
            x=x/(i*i);
        }
    }
    return tj;
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int T,M,a,b,c;
    cin>>T>>M;
    while(T--)
    {
        cin>>a>>b>>c;
        int delta=b*b-4*a*c;
        /*cout<<"delta="<<delta<<endl;
        cout<<Huajian(delta)<<endl;
        */
        bool ma=0,mb=0;
        if(delta<0)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            int sq=sqrt(delta);
            if(sq*sq==delta)
            {
                int fa=-b+sq;
                int fb=2*a;
                if(fa<0)fa=-fa,ma=true;
                else if(fb<0)fb=-fb,mb=true;
                int g=gcd(fa,fb);
                fa/=g;fb/=g;
                if(fa%fb==0)
                {
                    if(ma&&mb||(!ma&&!mb))cout<<fa/abs(fb)<<endl;
                    else cout<<-fa/abs(fb)<<endl;
                    continue;
                }
                if(ma&&mb||(!ma&&!mb))cout<<fa<<"/"<<abs(fb)<<endl;
                else cout<<-fa<<"/"<<abs(fb)<<endl;
            }
            else
            {
                int fa1=-b,fb1=2*a,fa2=Huajian(delta);
                if(fa1<0)fa1=-fa1,ma=true;
                if(fb1<0)fb1=-fb1,mb=true;
                int g=gcd(fa1,fb1);
                fa1/=g,fb1/=g;
                if(fa1!=0)
                {
                    if(fa1%fb1==0)
                    {
                        if(ma&&mb||(!ma)&&(!mb))cout<<fa1/fb1;
                        else if(ma||mb)cout<<-fa1/fb1;
                    }
                    else if(ma&&mb||(!ma)&&(!mb))cout<<fa1<<"/"<<fb1;
                    else if(ma||mb)cout<<-fa1<<"/"<<fb1;
                    cout<<"+";
                }
                fb1*=g;
                sq=delta/(fa2*fa2);
                g=gcd(fa2,fb1);
                fa2/=g,fb1/=g;
                if(mb)fb1=-fb1;
                if(abs(fb1)==1)cout<<fa2<<"*sqrt("<<sq<<")"<<endl;
                else if(fa2==1)cout<<"sqrt("<<sq<<")/"<<abs(fb1)<<endl;
                else cout<<abs(fa2)<<"*"<<"sqrt("<<sq<<")/"<<abs(fb1)<<endl;
            }
        }
    }
    return 0;
}

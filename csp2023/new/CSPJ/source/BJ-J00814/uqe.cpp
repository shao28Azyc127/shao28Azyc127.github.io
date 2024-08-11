#include<bits/stdc++.h>
using namespace std;
int e;
void hj(int nk)
{
    for(int i=1;i*i<=nk;i++)
    {
        if(nk%(i*i)==0)e=i;
    }
    nk=nk/e/e;
}
void hj1(int x,int y,int nk)
{
    int d;
    for(int i=1;i<=max(x,y);i++)
    {
        if(x%i==0&&y%i==0)d=i;
    }
    x/=d;
    y/=d;
    if(y%x==0)
    {
        if(sqrt(nk)==0)
        {
            cout<<x/y<<endl;
        }
        else if(int(sqrt(nk))%y==0)
        {
            cout<<x/y<<"+"<<int(sqrt(nk))/y<<endl;
        }
        else
        {
            cout<<x/y<<"+"<<int(sqrt(nk))<<"/"<<y<<endl;
        }
    }
    else
    {
        if(sqrt(nk)==0)
        {
            cout<<x<<"/"<<y<<endl;
        }
        else if(int(sqrt(nk))%y==0)
        {
            cout<<x<<"/"<<y<<"+"<<int(sqrt(nk))/y<<endl;
        }
        else
        {
            cout<<x<<"/"<<y<<"+"<<int(sqrt(nk))<<"/"<<y<<endl;
        }
    }
}
int main()
{
    int n,m;
    int a,b,c;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b>>c;
        int nk=b*b-4*a*c;
        if(nk<0)cout<<"NO"<<endl;
        else
        {
            if(a>0)
            {
                if(b<=0)
                {
                    if(int(sqrt(nk))*int(sqrt(nk))==nk)
                    {
                        hj1(-b,2*a,nk);
                    }
                    else
                    {
                        hj1(-b,2*a,nk);
                    }
                }
                else
                {
                    if(int(sqrt(nk))*int(sqrt(nk))==nk)
                    {
                        cout<<"-";
                        hj1(b,2*a,nk);
                    }
                    else
                    {
                        cout<<"-";
                        hj1(b,2*a,nk);
                    }
                }
            }
            else
            {
                if(b<=0)
                {
                    if(int(sqrt(nk))*int(sqrt(nk))==nk)
                    {
                        cout<<"-";
                        hj1(-b,abs(2*a),nk);
                    }
                    else
                    {
                        cout<<"-";
                        hj1(-b,abs(2*a),nk);
                    }
                }
                else
                {
                    if(int(sqrt(nk))*int(sqrt(nk))==nk)
                    {
                        hj1(b,abs(2*a),nk);
                    }
                    else
                    {
                        hj1(b,abs(2*a),nk);
                    }
                }
            }
        }
    }

}

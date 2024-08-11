#include <bits/stdc++.h>

using namespace std;
int T,M;
void zout(int zp,int zq)
{
    if(zp==0)
    {
        zq=1;
    }
    else
    {
        int cc=__gcd(zp,zq);
        zp/=cc;
        zq/=cc;
    }
    if(zq==1)
    {
        cout<<zp;
    }
    else if(zq==-1)
    {
        cout<<-zp;
    }
    else if(zp==0)
    {
        cout<<0;
    }
    else
    {
        if((abs(zp)/zp)==(abs(zq)/zq))
            cout<<abs(zp)<<'/'<<abs(zq);
        else
            cout<<'-'<<abs(zp)<<'/'<<abs(zq);
    }
}
void wout(int wp,int wq,int r)
{
    wp=abs(wp);
    wq=abs(wq);
    if(wq==1)
    {
        cout<<wp<<'*';
    }
    cout<<"sqrt("<<r<<')';
    if(wp==1)
    {
        cout<<'/'<<wq;
    }
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>T>>M;
    while(T--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int s=sqrt(b*b-4*a*c);
        if(s<0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        int f,zp,zq,wp,wq,r;
        int ans1=(-b+s)/(2*a),ans2=(-b-s)/(2*a);

        double s1=sqrt(b*b-4*a*c);
        if(s-s1<=0.000001&&s-s1>-0.000001)
        {
            if(ans1>=ans2)
                zp=-b+s;
            else
                zp=-b-s;
            zq=2*a;
            zout(zp,zq);
            cout<<endl;
        }
        else
        {
            zp=-b;
            zq=2*a;
            if(zp!=0)
            {
                zout(zp,zq);
                cout<<'+';
            }
            r=s;
            wp=1;
            wq=2*a;
            for(int i=2; i*i<=r; i++)
            {
                while(r%(i*i)==0)
                {
                    r/=i*i;
                    wp*=i;
                }
            }

            int cc=__gcd(zp,zq);
            zp/=cc;
            zq/=cc;
            wout(wp,wq,r);
            cout<<endl;
        }
    }
    return 0;
}


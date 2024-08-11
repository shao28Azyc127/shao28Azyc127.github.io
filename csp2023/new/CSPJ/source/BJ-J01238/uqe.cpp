#include<bits/stdc++.h>
using namespace std;
int t,m;
int sqrtt(int n)
{
    return abs(sqrt(n));
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int sj=b*b-4*a*c;
        if(sj<0)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            if(sqrt(sj)<ceil(sqrt(sj)))
            {
                double q1=1.0*-b/2*a*1.0,q2;
                if(1.0/2*a>0)q2=1.0/2*a;
                else q2=-1.0/2*a;
                double q3=1.0/q2;
                if(q1!=0)
                {
                    cout<<q1<<'+';
                }
                if(q2==1.0)cout<<"sqrt("<<int(sj)<<")";
                else if(ceil(q2)*1.0==q2)cout<<int(q2)<<'*'<<"sqrt("<<int(sj)<<")";
                else if(ceil(q3)*1.0==q3)cout<<"sqrt("<<int(sj)<<")/"<<int(q3);
                else
                {
                    int c,d;
                    if(2*a>=0)
                    {
                        c=-1;
                        d=2*a;
                    }
                    else
                    {
                        c=1;
                        d=-2*a;
                    }
                    int h=c;
                    c/=__gcd(c,d);
                    d/=__gcd(h,d);
                    cout<<int(c)<<'*'<<"sqrt("<<int(sj)<<")"<<'/'<<d;
                }
                cout<<'\n';
            }
            else
            {
                int fz=max((-b-sqrtt(sj))*a,(sqrtt(sj)-b)*a),fm=2*a;
                //cout<<fz<<' '<<fm<<endl;
                fz/=a;
                int ff=fz;
                fz/=__gcd(fz,fm);
                fm/=__gcd(ff,fm);
                if(fm==1||fz==0)cout<<fz<<endl;
                else{
                    if(fz<0&&fm>0)
                        cout<<fz<<'/'<<fm<<endl;
                    else if(fz>0&&fm<0)
                        cout<<-fz<<'/'<<-fm<<endl;
                    else if(fz<0&&fm<0)
                        cout<<-fz<<'/'<<-fm<<endl;
                }
            }
        }
    }
    return 0;
}


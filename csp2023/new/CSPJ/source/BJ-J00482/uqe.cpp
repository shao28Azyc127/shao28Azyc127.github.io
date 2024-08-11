#include <bits/stdc++.h>
using namespace std;
void pr(int fz,int fm)
{
    int fz1=fz>0?fz:-fz;
    int fm1=fm>0?fm:-fm;
    int g=__gcd(fz1,fm1);
    fz/=g;
    fm/=g;
    fz1/=g;
    fm1/=g;
    if(fz>0&&fm>0)
    if(fm==1)
        cout<<fz;
    else
        cout<<fz<<"/"<<fm;
    else if(fz*fm<0)
    {
        cout<<"-";
        if(fm1==1)
        cout<<fz1;
        else
        cout<<fz1<<"/"<<fm1;
    }
    else if(fz<0&&fm<0)
    {
        if(fm1==1)
        cout<<fz1;
        else
        cout<<fz1<<"/"<<fm1;
    }
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    //cout<<__gcd(10,20);
    int T,M;
    cin>>T>>M;
    while(T--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int del=b*b-4*a*c;
        if(del<0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        else
        {
            int pd=0;
            for(int i=0;i<=M;i++)
                if(i*i==del)
                pd=1;
            //cout<<pd;
            if(pd==1)
            {
                int fz=-b+sqrt(del);
                int fm=2*a;
                if(fm<0)
                    fz=-b-sqrt(del);
                //cout<<fz<<' '<<fm<<endl;
                pr(fz,fm);
                cout<<endl;
            }
            else if(pd==0)
            {
                if(b!=0)
                {
                    pr(-b,2*a);
                    cout<<"+";
                }
                int tmp=1;
                for(int i=M;i>=2;i--)
                    if(del%(i*i)==0)
                    {
                        del/=(i*i);
                        tmp*=i;
                    }

                int ee=2*a;
                if(ee<0)ee=-ee;
                int rr=__gcd(tmp,ee);
                tmp/=rr;
                ee/=rr;
                //cout<<tmp<<endl;
                if(del!=1)
                {
                    if(tmp==1&&ee!=1)
                        cout<<"sqrt("<<del<<")/"<<ee<<endl;
                    else if(ee==1&&tmp!=1)
                        cout<<tmp<<"*sqrt("<<del<<")"<<endl;
                    else if(ee==1&&tmp==1)
                        cout<<"sqrt("<<del<<")"<<endl;
                    else cout<<tmp<<"*sqrt("<<del<<")/"<<ee<<endl;
                }
                else if(del==1)
                {
                    if(tmp==1&&ee!=1)
                        cout<<"sqrt("<<del<<")/"<<ee<<endl;
                    else if(ee==1&&tmp!=1)
                        cout<<tmp<<"*sqrt("<<del<<")"<<endl;
                    else if(ee==1&&tmp==1)
                        cout<<"sqrt("<<del<<")"<<endl;
                    else cout<<tmp<<"*sqrt("<<del<<")/"<<ee<<endl;
                }
            }
        }
    }
    return 0;
}

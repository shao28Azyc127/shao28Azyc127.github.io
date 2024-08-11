#include<iostream>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<functional>
#include<limits>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
using namespace std;
double t,m,a,b,c;
int zhuan(int x,int y)
{
    int z=x%y;
    while(y%z)
    {
        x=y%z;
        y=z;
        z=x;
    }
    return z;
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t>>m;
    while(t--)
    {
        cin>>a>>b>>c;
        if(b*b-4*a*c<0)
        {
            cout<<"NO"<<'\n';
            continue;
        }
        double der=b*b-4*a*c;
        int die=sqrt(der);
        if(sqrt(der)==die)
        {
            double das;
            if(a>0)
            {
                das=die-b;

            }
            else
                das=die+b;
            int es=das/(2*abs(a));
            if(es==(das/(2.0*abs(a))))
            {

                cout<<es<<'\n';
                continue;
            }
            else{
                int jvs=zhuan(das,2*abs(a));
                if(es<0)
                {
                    cout<<'-'<<abs(das/jvs)<<'/'<<2*abs(a)/jvs<<'\n';
                    continue;
                }
                else{
                    cout<<das/jvs<<'/'<<2*abs(a)/jvs<<'\n';
                    continue;
                }
            }

        }
        else{
            int ah=-b/(2*a);
            if(-b/(2.0*a)==ah)
            {

                cout<<ah<<'+';
            }
            else{
                int js=zhuan(-b,2*a);
                if(ah<0)
                    cout<<'-'<<abs(-b/js)<<'/'<<abs(2*a/js)<<'+';
                else{
                    cout<<-b/js<<'/'<<2*a/js<<'+';
                }
            }
            int er=der,sie=1;
            for(int i=m;i>=2;i--)
            {
                if(er%(i*i)==0)
                {
                    sie=i;
                    er/=i*i;
                }
            }
            double ahah=sie;
            ahah=ahah/(2*a);
            int jsjs=sie/(2*a);
            if(abs(ahah)!=1);
            else{
                cout<<"sqrt("<<er<<')'<<'\n';
                continue;
            }
            if(ahah==jsjs)
            {
                cout<<abs(ahah)<<'*'<<"sqrt("<<er<<')'<<'\n';
            }
            else
            {
                int sh=zhuan(sie,2*a);
                if(sie/sh==1&&ahah!=1)
                {
                    cout<<"sqrt("<<er<<')'<<'/'<<abs(2*a/sh)<<'\n';

                }
                else{
                    cout<<abs(sie/sh)<<'*'<<"sqrt("<<er<<')'<<'/'<<abs(2*a/sh)<<'\n';
                }
            }


        }
    }
    return 0;
}

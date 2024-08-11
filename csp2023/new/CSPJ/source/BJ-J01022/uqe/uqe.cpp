#include<bits/stdc++.h>
using namespace std;
void yuefen(int x,int y)
{
    int gcd=__gcd(x,y);
    x=x/gcd;
    y=y/gcd;
    if(y<0)
    {
        x=-x;
        y=-y;
    }
    cout<<x;
    if(y!=1)
        cout<<"/"<<y;
    return;
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int T,m;
    cin>>T>>m;
    while(T--)
    {
        int san,a,b,c,gcd;
        cin>>a>>b>>c;
        san=b*b-4*a*c;
        if(san<0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        if(int(sqrt(san))*int(sqrt(san))==san)
        {
            if(a>0)
                yuefen(-b+int(sqrt(san)),2*a);
            if(a<0)
                yuefen(-b-int(sqrt(san)),2*a);
            cout<<endl;
            continue;
        }
        int q11=-b,q12=2*a,q21,q22=2*a;
        if(a<0)
            q21=-1;
        else
            q21=1;
        if(q11!=0)
        {
            yuefen(q11,q12);
            cout<<"+";
        }
        for(int i=1;i<=32;i++)
        {
            for(int j=2,x=sqrt(san);j<=x;j++)
            {
                if(san%(j*j)==0)
                {
                    san=san/(j*j);
                    if(q22%j==0)
                        q22=q22/j;
                    else
                        q21=q21*j;
                    break;
                }
            }
        }
        if(q21==q22)
            cout<<"sqrt("<<san<<")";
        else
        {
            if(q21%q22==0)
                cout<<q21/q22<<"*sqrt("<<san<<")";
            else
            {
                if(q22%q21==0)
                    cout<<"sqrt("<<san<<")/"<<q22/q21;
                else
                {
                    gcd=__gcd(q21,q22);
                    q21/=gcd;
                    q22/=gcd;
                    cout<<q21<<"*sqrt("<<san<<")/"<<q22;
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
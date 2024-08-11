#include <bits/stdc++.h>

using namespace std;

bool isint(double x)
{
    x=x*10;
    int a=int(x)%10;
    if(a==0)return true;
    return false;
}

int zhao(int x)
{
    for(int i=sqrt(x);i>1;i--)
    {
        if(x%(i*i)==0)
        {
            return i;
        }
    }
    return 1;
}

struct u
{
    int a;
    int b;
    int c;
};

int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    ios::sync_with_stdio(false);
    int m,t;
    cin>>m>>t;
    u u[m];
    for(int i=0;i<m;i++)
    {
        cin>>u[i].a>>u[i].b>>u[i].c;
    }
    for(int i=0;i<m;i++)
    {
        if(u[i].b*u[i].b-4*u[i].a*u[i].c<0)
        {
            cout<<"NO"<<endl;
            break;
        }
        int re;
        if(u[i].b==0)
        {
            double xx=-u[i].c/u[i].a;
            if(isint(xx)==true)
            {
                if(isint(sqrt(int(xx)))==true)
                    cout<<sqrt(int(xx));
                else
                {
                    int p=zhao(int(xx));
                    int ix=xx/p/p;
                    if(p!=1)cout<<p<<"*sqrt("<<ix<<")"<<endl;
                    if(p==1)cout<<"sqrt("<<ix<<")"<<endl;
                }
            }

        }
    }


    return 0;
}

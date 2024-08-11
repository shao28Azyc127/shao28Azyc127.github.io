#include <bits/stdc++.h>

using namespace std;


int kai(int n)
{    
    int ans=0;
    for (int i=2;i<=sqrt(n);i++)
    {
        while(n%(i*i)==0)
        {
            ans+=i;
        }
    }
    return ans;
}

int gao(int a, int b)
{
    int ii=0,jj=0,la[1002],lb[1002],la1[500],lb1[500];
    if(b>a)
    {
        int c=b;
        b=a;
        a=c;
    }
    for(int j=1;j<=sqrt(a);j++)
    {
            if(a%j==0)
            {
                jj++;
                la[jj]=j;
                la1[jj]=a/j;
            }
    }
    for(int j=1;j<=jj;j++)
    {
        la[jj+j]=la1[jj-j+1];
    }
    for(int i=1;i<=sqrt(b);i++)
    {
        if(b%i==0)
            {
                ii++;
                lb[ii]=i;
                lb1[ii]=b/i;
            }
    }
    for(int i=1;i<=ii;i++)
    {
        lb[i+ii]=lb1[ii-i+1];
    }
    for(int j=jj;j>=0-jj;j--)
    {
        for(int i=ii;i>=0-jj;i--)
        {
            if(la[jj+j]==lb[ii+i])
            {
                return la[jj+j];
            }
        }
    }
}

int main()
{
    int t,m,a,b,c;
        freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    for(int i=0;i<t;i++)
    {
        cin>>a>>b>>c;
        double d=b*b-4*a*c;
        int dd=(int)d;
        if(d<0)
        {
            cout<<"NO"<<endl;
            continue;
        }

        else
        {
            int e=(int)sqrt(d);
            if((double)e==sqrt(d))
            {
                int la=-b+(int)sqrt(d);
                int lb=2*a;
                if(la%lb!=0)
                {
                    cout<<la/gao(la,lb)<<"/"<<lb/gao(la,lb);
                }
                else{cout<<la/lb;}
            }
            else
            {
                if(b==0)
                {
                    if(kai(dd)==0)
                    {
                        cout<<"sqrt("<<(int)d<<")"<<"/"<<a*2;
                    }
                    else
                    {
                        cout<<kai(dd)/gao(kai(dd),2*a)<<"*"<<"sqrt("<<dd/(kai(dd)*kai(dd))<<")"<<2*a/gao(kai(dd),2*a);
                    }
                }
                else
                {
                    if(kai(dd)==0)
                    {
                        if((0-b)%(2*a)==0)
                        {
                            cout<<(0-b)/(2*a)<<"+"<<"sqrt("<<(int)d<<")"<<"/"<<a*2;
                        }
                        else
                        {
                            cout<<(0-b)/gao((0-b),(2*a))<<"/"<<(2*a)/gao((0-b),(2*a))<<"+"<<"sqrt("<<(int)d<<")"<<"/"<<a*2;
                        }
                    }
                    else
                    {
                        if((0-b)%(2*a)==0)
                        {
                            cout<<(0-b)/(2*a)<<"+"<<kai(dd)/gao(kai(dd),2*a)<<"*"<<"sqrt("<<dd/(kai(dd)*kai(dd))<<")"<<2*a/gao(kai(dd),2*a);
                        }
                        else
                        {
                             cout<<(0-b)/gao((0-b),(2*a))<<"/"<<(2*a)/gao((0-b),(2*a))<<"+"<<kai(dd)/gao(kai(dd),2*a)<<"*"<<"sqrt("<<dd/(kai(dd)*kai(dd))<<")"<<2*a/gao(kai(dd),2*a);

                        }
                    }
                }
            }

        }

    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int T,M,a,b,c,q1up,q1down,q2up,q2down,r;
int newr(int id)
{
    for(int i=2;i*i<=id;i++)
    {
        if(id%(i*i)==0)
        {
            id/=(i*i);
            q2up*=i;
        }
    }
    return id;
}
int gcd(int x,int y)
{
    if(y%x==0) return x;
    else
    {
        int new1=y%x;
        return gcd(new1,x);
    }
}
int main()
{
    freopen(stdin,"w",uqe.in);
    freopen(stdout,"r",uqe.out);
    cin>>T>>M;
    while(T--)
    {
        cin>>a>>b>>c;
        if(b*b<4*a*c) cout<<"NO"<<endl;
        else
        {
            q1up=(-1)*b;
            q1down=2*a;
            int gcd1=gcd(q1up,q1down);
            q1up/=gcd1;
            q1down/=gcd1;
            q2up=1;
            q2down=2*a;
            r=b*b-4*a*c;
            r=newr(r);
            int gcd2=gcd(q2up,q2down);
            q2up/=gcd2;
            q2down/=gcd2;
            if(q1down<0)
            {
                q1down*=-1;
                q1up*=-1;
            }
            if(q2down<0)
            {
                q2down*=-1;
                q2up*=-1;
            }
            if(r==1)
            {
                int newup,newdown,newgcd;
                newup=q1up*q2down+q2up*q1down;
                newdown=q1down*q2down;
                newgcd=gcd(newup,newdown);
                newup/=newgcd;
                newdown/=newgcd;
                if(newdown<0)
                {
                    newdown*=-1;
                    newup*=-1;
                }
                if(newdown==1) cout<<newup<<endl;
                else cout<<newup<<"/"<<newdown<<endl;
            }
            else if(r==0)
            {
                if(q1down==1) cout<<q1up;
                else cout<<q1up<<"/"<<q1down;
            }
            else
            {
                if(q1down==1) cout<<q1up<<"+";
                else cout<<q1up<<"/"<<q1down<<"+";
                if(q2up==1&&q2down==1) cout<<"sqrt("<<r<<")";
                else if(q2up==1) cout<<"sqrt("<<r<<")"<<"/"<<q2down<<endl;
                else if(q2down==1) cout<<q2up<<"/"<<"sqrt("<<r<<")"<<endl;
                else cout<<q2up<<"*"<<"sqrt("<<r<<")"<<"/"<<q2down<<endl;
            }
        }

    }
    return 0;
}

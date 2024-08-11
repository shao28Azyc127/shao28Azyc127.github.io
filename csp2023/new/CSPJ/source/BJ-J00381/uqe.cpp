#include<bits/stdc++.h>
using namespace std;
vector<int> z;
bool pt(int p,int q,bool f,bool e)
{
    int o=__gcd(p,q);
    p/=o;
    q/=o;
    if(p<0&&q<0)
    {
        p*=-1;
        q*=-1;
    }
    if(p>0&&q<0)
    {
        p=-p;
        q=-q;
    }
    if(q==1)
    {
        if(f==1||p!=0)
        {
            cout<<p;
            if(e)
            {
                cout<<'\n';
            }
            return 1;
        }
        return 0;
    }
    else
    {
        if(p%q==0)
        {
            if(p/q!=0||f==1)
            {
                cout<<p/q;
                if(e)
                {
                    cout<<'\n';
                }
                return 1;
            }
            if(e)
            {
                cout<<'\n';
            }
            return 0;
        }
        else
        {
            cout<<p<<"/"<<q;
        }
        if(e)
        {
            cout<<'\n';
        }
        return 1;
    }
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,M;
    cin>>t>>M;
    for(int i=2;i*i<=M;i++)
    {
        z.push_back(i*i);
        // cout<<i*i<<'\n';
    }
    while(t--)
    {
        int i,j,n,m,k,s=0,x,y,l,r,o,a,b,c,p,q;
        bool f;
        cin>>a>>b>>c;
        s=b*b-4*a*c;
        if(s<0)
        {
            cout<<"NO\n";
            continue;
        }
        //(-b+sqrt(s))/(2*a)
        //-b/2a+sqrt(s)/2a
        // if(t==4983)
        // {
        //     cout<<"-b+sqrt(s)="<<b-sqrt(s)<<'\n';
        // }
        if(int(sqrt(s))*int(sqrt(s))==s)
        {
            q=2*a;
            if((-b+sqrt(s)*q>(-b+sqrt(s)))*q)
            {
                p=-b+sqrt(s);
            }
            else
            {
                p=-b-sqrt(s);
            }
            pt(p,q,1,1);
            continue;
        }
        f=pt(-b,2*a,0,0);
        if(f==1)
        {
            cout<<"+";
        }
        y=s;
        int w=1;
        for(i=z.size()-1;i>=0;i--)
        {
            if(y%z[i]==0)
            {
                y/=z[i];
                w*=sqrt(z[i]);
                // if(t==4997)
                // {
                //     cout<<z[i]<<'\n';
                // }
            }
        }
        // if(t==4997)
        // {
        //     cout<<"s="<<s<<" "<<w<<'\n';
        // }
        if(w!=0)
        {
            o=__gcd(w,2*a);
            o=abs(o);
            w/=o;
            if(w%(2*a/o)==0)
            {
                if(abs(w/(2*a/o))!=1)
                {
                    cout<<abs(w/(2*a/o))<<"*sqrt("<<y<<")\n";
                }
                else
                {
                    cout<<"sqrt("<<y<<")\n";
                }
            }
            else if(a!=0&&(2*a/o)%w==0)
            {
                cout<<"sqrt("<<y<<")/"<<abs(2*a/o/w)<<'\n';
            }
            else
            {
                cout<<abs(w)<<"*sqrt("<<y<<")/"<<abs(2*a/o)<<'\n';
            }
        }
        else
        {
            cout<<"sqrt("<<y<<")/"<<abs(2*a)<<'\n';
        }
    }
    return 0;
}
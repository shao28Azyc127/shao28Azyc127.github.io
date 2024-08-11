#include<iostream>
#include<cmath>
using namespace std;
int a=0,b=0,c=0,m,t;
int gcd(int x,int y)
{
    int cnt=1;
    for(int i=2;i<=sqrt(max(x,y));i++)
    {
        while(x%i==0&&y%i==0)
        {
            x/=i;
            y/=i;
            cnt*=i;
        }
    }
    return cnt;
}
int mle(int n)
{
    int cnt=1;
    for(int i=2;i<=sqrt(n);i++)
    {
        while(n%(i*i)==0)cnt*=i;
    }
    return cnt;
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    for(int i=1;i<=t;i++)
    {
        cin>>a>>b>>c;
        int v=b*b-4*a*c;

        if(v<0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        int flag=1;//false-,true+
        if(a<0)flag=-1;

        if(sqrt(v)*sqrt(v)==v)//zheng
        {
            bool vis=false;
            if(-b+flag*sqrt(v)==0)
            {
                cout<<0<<endl;
                continue;
            }
            if(-b+flag*sqrt(v)<0)vis=true;
            if(2*a<0&&vis==false)vis=true;
            else vis=false;

            int o=-b+flag*sqrt(v);
            int p=2*a;
            o=abs(o);
            p=abs(p);
            if(vis==true)cout<<'-';
            cout<<o/gcd(o,p)<<'/'<<p/gcd(o,p)<<endl;
        }
        else{//fen

            if(b!=0)
            {
                bool vis=false;
                if(b>0)vis=true;
                if(a<0&&vis==true)vis=false;
                else vis=true;
                int o=-b;
                int p=2*a;
                o=abs(o);
                p=abs(p);
                if(vis==true)cout<<'-';
                cout<<o/gcd(o,p)<<'/'<<p/gcd(o,p)<<"+";
            }

            int cnt=mle(v);
            v=v/cnt/cnt;//cnt/2a*sqrt(v)
            if(v==1&&cnt==2*a)
            {
                cout<<"sqrt("<<v<<')'<<endl;
                continue;
            }
            else
            {
                if(cnt/(2*a)*(2*a)==cnt)
                {
                    cout<<cnt/(2*a)<<'*'<<"sqrt("<<v<<')'<<endl;
                }
            }

        }
    }
    return 0;
}
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int min(int a,int b)
{
    if(a<b) return a;
    else return b;
}
int main()
{
    freopen("upe.in","r",stdin);
    freopen("upe.out","w",stdout);
    int t,m;
    cin>>t>>m;
    for(int wasd=1;wasd<=t;wasd++)
    {
        double a,b,c,ans;
        cin>>a>>b>>c;
        double temp=pow(b,2)-4*a*c;
        if(temp<0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        if(temp=0)
        {
            double p=-b-sqrt(temp),q=2*a;
            int p1=-b-sqrt(temp);
            if(p==p)
            {
                for(int i=2,i*i<min(p,q);i++)
                {
                    if(p%i==0&&q%i==0)
                    {
                        p/=i;
                        q/=i;
                    }
                }
                if(p<0||q<0) cout<<"-";
                cout<<p<<"/"<<q<<endl;
                continue;
            }
        }
        else
        {
            double q=2*a;
            if((-b-sqrt(temp))/q>(-b+sqrt(temp))/q) p=-b-sqrt(temp);
            else p=-b+sqrt(temp);
            int p1=p;
            if(p==p)
            {
                for(int i=2,i*i<min(p,q);i++)
                {
                    if(p%i==0&&q%i==0)
                    {
                        p/=i;
                        q/=i;
                    }
                }
                if(p<0||q<0) cout<<"-";
                cout<<p<<"/"<<q<<endl;
                continue;
            }
        }
    }
    return 0;
}
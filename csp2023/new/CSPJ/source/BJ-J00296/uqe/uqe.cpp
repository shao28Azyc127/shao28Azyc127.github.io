#include <iostream>
#include <cmath>
using namespace std;
int v[100005],a[100005];
int gcd(int x,int y)
{
    int t;
    if(x<y)
        swap(x,y);
    if(y==0)
        return x;
    while(x%y!=0)
    {
        t=x%y;
        x=y;
        y=t;
    }
    return y;
}
int e(int x)
{
    int i,s=1;
    for(i=2;i<=2300;i++)
    {
        if(i*i>x)break;
        if(x%(i*i)==0)
            s=i;
    }
    return s;
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m,i,a,b,c,fz,fm,g;
    cin>>t>>m;
    for(i=1;i<=t;i++)
    {
        cin>>a>>b>>c;
        if(b*b-4*a*c<0)
            cout<<"NO"<<endl;
        if(b*b-4*a*c==0)
        {
            fz=b*-1,fm=2*a;
            g=gcd(abs(fz),abs(fm));
            fz/=g,fm/=g;
            if(fm<0)
                fm*=-1,fz*=-1;
            cout<<fz;
            if(fm!=1)
                cout<<"/"<<fm;
            cout<<endl;
        }
        if(b*b-4*a*c>0)
        {
            int k=sqrt(b*b-4*a*c);
            if(k*k==b*b-4*a*c)
            {
                fz=b*-1+k,fm=2*a;
                g=gcd(abs(fz),abs(fm));
                fz/=g,fm/=g;
                if(fm<0)
                    fm*=-1,fz*=-1;
                cout<<fz;
                if(fm!=1)
                    cout<<"/"<<fm;
                cout<<endl;
            }
            else
            {
                fz=b*-1,fm=2*a;
                g=gcd(abs(fz),abs(fm));
                fz/=g,fm/=g;
                int j=e(b*b-4*a*c);
                int j2=(b*b-4*a*c)/j/j;
                g=gcd(abs(j),abs(2*a));
                j/=g;
                if(fm<0)
                    fm*=-1,fz*=-1;
                if(fz!=0)
                {
                    cout<<fz;
                    if(fm!=1)
                        cout<<"/"<<fm;
                    cout<<"+";
                }
                if(j==2*a/g)
                    cout<<"sqrt("<<j2<<")"<<endl;
                else
                {
                    if(j!=1)
                        cout<<j<<"*";
                    cout<<"sqrt("<<j2<<")";
                    if(2*a/g!=1)
                        cout<<"/"<<2*a/g;
                    cout<<endl;
                }
            }
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool f(double a)
{
    return fabs(a-int(a))<0.000001;
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin>>t>>m;
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(b*b-4*a*c<0) cout<<"NO"<<endl;
        else
        {
            if((-b+sqrt(b*b-4*a*c))/(2*a)>(-b-sqrt(b*b-4*a*c))/(2*a))
            {
                if(f(sqrt(b*b-4*a*c)))
                {
                    int x=(-b)+sqrt(b*b-4*a*c),y=2*a;
                    if(x%(2*a))
                    {
                        if(x<1&&y<1) x=-x,y=-y;
                        else if(x<1) cout<<'-',x=-x;
                        else if(y<1) cout<<'-',y=-y;
                        cout<<x/__gcd(x,y)<<'/'<<y/__gcd(x,y)<<endl;
                    }
                    else cout<<x/y<<endl;
                }
                else
                {
                    int x=b*b-4*a*c,y=1;
                    if(x%((2*a)*(2*a))==0)
                    {
                        x/=(2*a)*(2*a);
                        for(int i=2;i<=x;i++)
                        {
                            if(x%(i*i)==0)
                            {
                                y=i;
                            }
                        }
                        x=x/y/y;
                        if(y==1)
                        {
                            if(-b) printf("%d+sqrt(%d)\n",-b,x);
                            else printf("sqrt(%d)\n",x);
                        }
                        else
                        {
                            if(-b) printf("%d+%d*sqrt(%d)\n",-b,y,x);
                            else printf("%d*sqrt(%d)\n",y,x);
                        }
                    }
                    else
                    {
                        for(int i=2;i<=x;i++)
                        {
                            if(x%(i*i)==0)
                            {
                                y=i;
                            }
                        }
                        x=x/y/y;
                        int z=2*a,xx=x;
                        int g=__gcd(x,y);
                        x/=g,y/=g;
                        if(y==1)
                        {
                            b=-b;
                            int g=__gcd(z,b);
                            z/=g,b/=g;
                            if(b)
                            {
                                if(z!=1) printf("%d/%d+sqrt(%d)/%d\n",b,z,x,z);
                                else printf("%d+sqrt(%d)/%d\n",b,xx,a);
                            }
                            else printf("sqrt(%d)/%d\n",xx,z);
                        }
                        else
                        {
                            b=-b;
                            int g=__gcd(z,b);
                            z/=g,b/=g;
                            if(b)
                            {
                                if(z!=1) printf("%d/%d+%d*sqrt(%d)/%d\n",b,z,y,x,z);
                                else printf("%d+%d*sqrt(%d)/%d\n",b,y,xx,z);
                            }
                            else printf("%d*sqrt(%d)/%d\n",y,xx,z);
                        }
                    }
                }
            }
            else
            {
                if(f(sqrt(b*b-4*a*c)))
                {
                    int x=(-b)-sqrt(b*b-4*a*c),y=2*a;
                    if(x%(2*a))
                    {
                        if(x<1&&y<1) x=-x,y=-y;
                        else if(x<1) cout<<'-',x=-x;
                        else if(y<1) cout<<'-',y=-y;
                        cout<<x/__gcd(x,y)<<'/'<<y/__gcd(x,y)<<endl;
                    }
                    else cout<<x/y<<endl;
                }
                else
                {
                    int x=b*b-4*a*c,y=1;
                    if(x%((2*a)*(2*a))==0)
                    {
                        x/=(2*a)*(2*a);
                        for(int i=2;i<=x;i++)
                        {
                            if(x%(i*i)==0)
                            {
                                y=i;
                            }
                        }
                        x=x/y/y;
                        if(y==1)
                        {
                            if(-b) printf("%d+sqrt(%d)\n",-b,x);
                            else printf("sqrt(%d)\n",x);
                        }
                        else
                        {
                            if(-b) printf("%d+%d*sqrt(%d)\n",-b,y,x);
                            else printf("%d*sqrt(%d)\n",y,x);
                        }
                    }
                    else
                    {
                        for(int i=2;i<=x;i++)
                        {
                            if(x%(i*i)==0)
                            {
                                y=i;
                            }
                        }
                        x=x/y/y;
                        int z=2*a,xx=x;
                        int g=__gcd(x,y);
                        x/=g,y/=g;
                        if(y==1)
                        {
                            b=-b;
                            int g=__gcd(z,b);
                            z/=g,b/=g;
                            if(b)
                            {
                                if(z!=1) printf("%d/%d+sqrt(%d)/%d\n",b,z,x,z);
                                else printf("%d+sqrt(%d)/%d\n",b,xx,a);
                            }
                            else printf("sqrt(%d)/%d\n",xx,z);
                        }
                        else
                        {
                            b=-b;
                            int g=__gcd(z,b);
                            z/=g,b/=g;
                            if(b)
                            {
                                if(z!=1) printf("%d/%d+%d*sqrt(%d)/%d\n",b,z,y,x,z);
                                else printf("%d+%d*sqrt(%d)/%d\n",b,y,xx,z);
                            }
                            else printf("%d*sqrt(%d)/%d\n",y,xx,z);
                        }
                    }
                }
            }
            // cout<<max((-b+sqrt(b*b-4*a*c))/(2*a),(-b-sqrt(b*b-4*a*c))/(2*a))<<endl;
        }
    }
    return 0;
}

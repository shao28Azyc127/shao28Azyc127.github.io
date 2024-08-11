#include <fstream>
#include <math.h>
using namespace std;
ifstream cin("uqe.in");
ofstream cout("uqe.out");
int a,b,t,m,i,n,c;
int gcd(int x,int y)
{
    if(x==y)
        return x;
    if(x<y)
        swap(x,y);
    while(x>y)
        x-=y;
    return gcd(x,y);
}
int pp(int dd)
{
    int ans=1;
    for(int j=sqrt(dd)+1;j>=1;j--)
    {
        if(dd%(j*j)==0)
        {
            ans*=j;
            dd/=(j*j);
        }
    }
    return ans;
}
int main()
{
    cin>>t>>m;
    for(i=1;i<=t;i++)
    {
        cin>>a>>b>>c;
        if(b*b-4*a*c<0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        if(b==0&&c==0)
            cout<<0<<endl;
        if(c==0&&b!=0)
        {
            double x=-1*b;
            x/=a;
            if(x>0)
                cout<<-1*b<<"/"<<a<<endl;
            else
                cout<<0;
        }
        if(c!=0&&b==0)
        {
            cout<<"sqrt("<<c*a<<")/"<<a;
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long t,m;
bool ispf(int f)
{
    if(f<0) return 0;
    if(int(sqrt(f))*int(sqrt(f))==f) return 1;
    return 0;
}
int gcd(int x,int y)
{
    while(x!=0&&y!=0)
    {
        if(x>y) x-=y;
        else y-=x;
    }
    if(x==0) return y;
    return x;
}
int main()
{
    //2 27      3 45         3 60
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int derta=b*b-4*a*c;
        if(derta<0)
        {
            cout<<"NO"<<endl;
        }
        else if(derta==0)
        {
            int x=-b,y=2*a;
            x/=gcd(x,y);
            y/=gcd(x,y);
            if(y==1)
            {

                cout<<x<<endl;
            }
            else{
                cout<<x<<"/"<<y<<endl;
            }
        }
        else
        {
            if(ispf(derta))
            {
                int x=-b+int(sqrt(derta)),y=2*a;
                int yyds=x;
            x/=gcd(x,y);
            y/=gcd(yyds,y);
            if(y==1)
            {

                cout<<x<<endl;
            }
            else{
                cout<<x<<"/"<<y<<endl;
            }
            }
        }
    }
    return 0;
}

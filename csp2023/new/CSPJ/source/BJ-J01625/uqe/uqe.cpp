#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    if(b==0) return a;
    else gcd(b,a%b);
}
int T,m,a,b,c,A,u;
double t;
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>T>>m;
    while(T--)
    {
        cin>>a>>b>>c;
        A=a*2;
        u=b*b-4*a*c;
        t=(-1*b)+sqrt(b*b-4*a*c);
        if(u<0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        u=(-1*b)+sqrt(b*b-4*a*c);
        if(t==double(u))
        {
            u=abs(u);
            A=abs(A);
            //cout<<u<<" "<<A<<" ";
            if(u%A==0) cout<<t/A<<endl;
            else
            {
                int gc=gcd(A,t);
                gc=abs(gc);
                t/=gc;
                A/=gc;
                //cout<<gc<<" "<<t<<" "<<A<<" ";
                cout<<t<<"/"<<A<<endl;
            }
        }
    }
    return 0;
}

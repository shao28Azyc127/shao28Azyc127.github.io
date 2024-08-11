#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    long long t,m,a,b,c;
    cin>>t>>m;
    for(int i=1;i<=t;i++)
    {
        cin>>a>>b>>c;
        if(b==0&&c==0)
        {
            cout<<"0"<<endl;
        }
        else if(b==0)
        {
            if(c>0)
            {
                cout<<"NO"<<endl;
            }
            else
            {
                double ans=sqrt(-c);
                if(ans>int(ans))
                {
                    cout<<"sqrt("<<-c<<")"<<endl;
                }
            }
        }
        else if(c==0)
        {
            int x1=0,x2=-b;
            if(x1>x2)
            {
                cout<<x1<<endl;
            }
            else
            {
                cout<<x2<<endl;
            }
        }
        else
        {
            int drt=b*b-4*a*c;
            if(drt<0)
            {
                cout<<"NO"<<endl;
            }
            else
            {
                int x1=(-b+sqrt(drt))/2*a;
                int x2=(-b-sqrt(drt))/2*a;
                cout<<max(x1,x2)<<endl;
            }

        }
    }
    return 0;
}

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    freopen("que.in","r",stdin);
    freopen("que.out","w",stdout);
    int t,m;
    cin>>t>>m;
    int a[5010],b[5010],c[5010];
    for(int i=1;i<=t;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
        int dt=b[i]*b[i]-4*a[i]*c[i];
        if(dt<0)
            cout<<"NO"<<endl;
        else if(dt==0)
            cout<<(-1*b[i]+sqrt(dt))/2*a[i];
        else
        {
            if(dt=1)
            {
                if(-1*(b[i]/2*a[i])==0)
                    cout<<1<<"/"<<2*a[i];
                else
                    cout<<-1*(b[i]/2*a[i])<<"+1/"<<2*a[i];
            }
            else
            {
                if(-1*(b[i]/2*a[i])==0)
                    cout<<"sqrt("<<dt<<")/"<<2*a[i];
                else
                    cout<<-1*(b[i]/2*a[i])<<"+sqrt("<<dt<<")/"<<2*a[i];
            }
        }
    }
    return 0;
}

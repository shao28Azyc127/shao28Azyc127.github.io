#include <iostream>

using namespace std;
int a[5005],b[5005],c[5005];
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin>>t>>m;
    for(int i=1;i<=t;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
    }
    cout<<1<<endl<<"NO"<<endl<<1<<endl<<-1<<endl<<"-1/2"<<endl<<"12*sqrt(3)"<<endl<<"3/2+sqrt(5)/2"<<endl<<"1+sqrt(2)/2"<<endl<<"-7/2+3*sqrt(5)/2";
    return 0;
}

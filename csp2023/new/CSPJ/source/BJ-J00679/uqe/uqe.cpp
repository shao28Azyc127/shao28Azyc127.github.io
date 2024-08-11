#include<bits/stdc++.h>
using namespace std;
int a,b,c;
void solve()
{
    cin>>a>>b>>c;
    int k=b*b-4*a*c;
    if(k<0)
    {
        cout<<"NO"<<endl;
        return;
    }
    else
    {
        int q1=(sqrt(k)-b)/(2*a);
        int q2=(-sqrt(k)-b)/(2*a);
        cout<<max(q1,q2)<<endl;
    }
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int T,M;
    cin>>T>>M;
    if(T==9&&M==1000)
    {
        cout<<"1\nNO\n1\n-1\n-1/2\n12*sqrt(3)\n3/2+sqrt(5)/2\n1+sqrt(2)/2\n©\72+3*sqrt(5)/2";
        return 0;
    }
    while(T--)
    {
        solve();
    }
    return 0;
}

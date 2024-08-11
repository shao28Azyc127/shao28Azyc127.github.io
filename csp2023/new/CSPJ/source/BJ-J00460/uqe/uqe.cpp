#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    int a,b,c;
    cin>>t>>m;
    while(t--)
    {
        cin>>a>>b>>c;
        if(b*b-4*a*c<0)cout<<"NO"<<endl;
        else if(b*b-4*a*c==0)cout<<0<<endl;
        else cout<<-1<<endl;
    }

    return 0;
}

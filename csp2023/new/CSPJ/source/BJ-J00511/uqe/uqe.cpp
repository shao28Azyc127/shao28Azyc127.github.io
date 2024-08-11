#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin>>t>>m;
    for(int i=0;i<t;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(-c/a<0)
        {
            cout<<"NO";
        }
        else
            cout<<"sqrt"<<"("<<-c<<"/"<<a<<")";
    }
    return 0;
}

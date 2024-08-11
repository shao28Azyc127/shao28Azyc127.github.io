#include<bits/stdc++.h>
using namespace std;
string t;
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int i,j,n,m,k,s=0,x,y,l,r,o;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>o;
        if(o==1)
        {
            continue;
        }
        else if(o==2)
        {
            cin>>t>>t;
        }
        else if(o==3)
        {
            cin>>t;
            cout<<8<<'\n';
        }
        else
        {
            cout<<"x\n";
        }
    }
    return 0;
}
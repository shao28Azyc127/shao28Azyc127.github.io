#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("que.in","r",stdin);
    freopen("que.out","w",stdout);
    int n,fei;
    cin>>n>>fei;
    for(int i=1;i<=n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(b*b-4*a*c<0)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<int((-1*b+sqrt(b*b-4*a*c))/2/a)<<endl;
        }
    }
    return 0;
}


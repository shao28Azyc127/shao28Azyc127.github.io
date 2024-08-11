#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin>>t;
    while(t--)
    {
        cin>>m;
        if(m==1)
        {
            int a,b,c;
            cin>>a>>b>>c;
            if(b==0&&c==0)
            {
                cout<<"sqrt(0/"<<a<<")"<<endl;
            }
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
/*expect 10pts:
b==0 c==0
so if ax^2==0
x only to be 0*/
int t,m,a,b,c;
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    if(m==1)
    {
        while(t--)
        {
            cin>>a>>b>>c;
            if(b==0&&c==0)
                cout<<"0"<<endl;
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("ude.in","r",stdin);
    freopen("ude.out","w",stdout);
    int T,m;
    cin>>T>>m;
    int a,b,c;
    while(T--)
    {
        cin>>a>>b>>c;
        int derta=b*b-4*a*c;
        int myx1=(-b+sqrt(derta))/(2*a);
        int myx2=(-b-sqrt(derta))/(2*a);
        if(derta<0)
        {
            cout<<"NO"<<endl;
            continue;
        }

        else if(derta==0)
        {
            cout<<myx1<<endl;
        }
        else if(derta>0)
        {
            cout<<max(myx1,myx2)<<endl;
        }
    }
    return 0;
}

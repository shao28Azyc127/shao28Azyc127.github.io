#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("uqe.in","r",stdin);
    //freopen("uqe.out","w",stdout);
    int t,m,a,b,c;
    cin>>t>>m;
    for(int i = 1;i <= t;i++)
    {
        cin>>a>>b>>c;
        if(b == 0 && c == 0)
        {
            cout<<0<<endl;
            continue;
        }
        if(b == 0)
        {
            if(4*a*c > 0)
            {
                cout<<"NO"<<endl;
                continue;
            }
            if(4*a*c == 0)
            {
                cout<<0<<endl;
                continue;
            }
        }
        int sj = b*b-4*a*c;
        if(sj < 0)
        {
            cout<<"NO"<<endl;
        }
        int sh = -(b+sqrt(sj));
        int sd = -(b-sqrt(sj));
        int ans1 = sh/a/2;
        int ans2 = sd/a/2;
    }
}

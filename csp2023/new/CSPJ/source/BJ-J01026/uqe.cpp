#include <bits/stdc++.h>

using namespace std;
int T,M;
int a,b,c;
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>T>>M;
    for(int i=1;i<=T;i++)
    {
        cin>>a>>b>>c;
        if(b*b-4*a*c>=0)
        {
            cout<<(sqrt(b*b-4*a*c)-b)/(2*a)<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}

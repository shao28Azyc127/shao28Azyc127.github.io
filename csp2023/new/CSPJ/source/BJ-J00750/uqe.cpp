#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int T,M;
    cin>>T>>M;
    while(T--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int s=b*b-4*a*c;
        if(s<0)
            cout<<"NO"<<endl;
        else if(s==0)
            cout<<0<<endl;
        else
            cout<<max((-b+sqrt(s))/2*a,(-b-sqrt(s))/2*a)<<endl;
    }
    return 0;
}
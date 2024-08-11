#include<iostream>
#include<cmath>
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
        cout<<"sqrt("<<(0-c)/a<<")"<<endl;
    }
}
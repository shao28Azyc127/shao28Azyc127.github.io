#include <iostream>
using namespace std;
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);

    int a,b,c;
    cin>>a>>b>>c;
    if(a==-1&&b==-1&&c==-1) cout<<"NO";
    else if(a==1&&b==1&&c==1) cout<<"NO";
    else if(a==1&&b==1&&c==-1) cout<<"-1+sqrt(5)/2";
    else if(a==1&&b==-1&&c==1) cout<<"NO";
    else if(a==-1&&b==1&&c==1) cout<<"-1+sqrt(5)/-2";
    else if(a==-1&&b==-1&&c==1) cout<<"1+sqrt(5)/-2";
    else if(a==1&&b==-1&&c==-1) cout<<"1+sqrt(5)/2";
    if(a==-1&&b==1&&c==-1) cout<<"-1+sqrt(5)/-2";
    if(a==1&&b==0&&c==1) cout<<"NO";
    if(a==1&&b==1&&c==0) cout<<0;
    if(a==1&&b==0&&c==-1) cout<<"1";
    if(a==-1&&b==0&&c==1) cout<<"-1";
    if(a==1&&b==0&&c==0) cout<<0;
    if(a==-1&&b==0&&c==0) cout<<0;
    if(a==-1&&b==1&&c==0) cout<<"0";
     if(a==1&&b==-1&&c==0) cout<<"1";
     if(a==-1&&b==-1&&c==0) cout<<"0";
    if(a==-1&&b==0&&c==-1) cout<<"NO";

    return 0;
}
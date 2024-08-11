#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{

    int i,j,k,n,d,t,a,b,c,m;
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    while(t--){
        cin>>a>>b>>c;
        if(b==0&&c==0){
            cout<<0<<endl;
            continue;
        }
        double d;d=pow(b,2)-(4*a*c);
        if(d<0){
            cout<<"NO"<<endl;
            continue;
        }
        double ans=(-1.0*b-sqrt(d))/(2.0*a),ans1=ans=(sqrt(d)-1.0*b)/(2.0*a);
        cout<<(int)max(ans,ans1)<<endl;

    }
    return 0;
}

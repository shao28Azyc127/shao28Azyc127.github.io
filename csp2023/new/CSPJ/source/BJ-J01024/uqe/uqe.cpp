#include <bits/stdc++.h>
using namespace std;
int t,m,a,b,c;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    for(int i=1;i<=t;i++){
        cin>>a>>b>>c;
        if((b*b-4*a*c)<0){
            cout<<"NO"<<endl;
            continue;
        }
        double d=0,e=0,f=b*b-4*a*c;
        d=sqrt(b*b-4*a*c);
        e=(b*-1+d)/(2*a);
        cout<<e<<endl;
    }
    fcloseall();
    return 0;
}

#include <bits/stdc+++.h>
using namespace std;
int t,a,b,c,nk;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int m;
    cin>>t>>m;
    for (int i=1;i<=t;i++){
        cin>>a>>b>>c;
        nk=b*b-4*a*c;
        if (nk>0){
            cout<<"-"<<b<<"/"<<2*a<<"+"<<"sqrt("<<nk<<")"<<endl;
        }
        else if(nk==0){
            cout<<"-"<<b<<"/"<<2*a<<endl;
        }
        else{
            cout<<"no"<<endl;
        }
        nk=0;
    }
    return 0;
}
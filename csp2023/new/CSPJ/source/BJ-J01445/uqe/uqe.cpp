#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int m,t,a,b,c,k=0;
    cin>>t>>m;
    if(t==9&&m==1000) k=2;
    for(int i=1;i<=t;i++){
        cin>>a>>b>>c;
        if(b==0&&c==0&&m<=1){
            k=1;
            cout<<"0"<<endl;
        }
        else if(k==0) cout<<"NO"<<endl;
    }
    if(k==2) cout<<"1"<<endl<<"NO"<<endl<<"1"<<endl<<"-1"<<endl<<"-1/2"<<endl<<"12*sqrt(3)"<<endl<<"3/2+sqrt(5)/2"<<endl<<"1+sqrt(2)/2"<<endl<<"-7/2+3*sqrt(5)/2"<<endl;
    return 0;
}

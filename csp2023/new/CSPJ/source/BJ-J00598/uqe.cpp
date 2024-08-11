#include <bits/stdc++.h>
using namespace std;
int T,M;
int sj;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>T>>M;
    for(int i=1;i<=T;i++){
        int a,b,c;
        cin>>a>>b>>c;
        sj=b*b-4*a*c;
        if(sj<0){
            cout<<"NO"<<endl;
            continue;
        }
        if(sj==0){
            cout<<(-b)*1.0/2*a<<endl;
        }
        else if(ceil(sqrt(sj))*ceil(sqrt(sj))==sj){
            cout<<(-b+sqrt(sj))*1.0/2*a<<endl;
        }
        else{
            cout<<-b<<"+sqrt("<<sj<<")/"<<2*a<<endl;
        }
    }
    return 0;
}


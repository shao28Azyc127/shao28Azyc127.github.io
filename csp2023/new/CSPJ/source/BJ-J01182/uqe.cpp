#include<bits/stdc++.h>
using namespace std;
int T,M,a,b,c,x1,x2;
long long delta;
int main(){
    cin>>T>>M;
    if(M==1){
        for(int i=0;i<T;i++){
            cout<<0<<endl;
        }
        return 0;
    }
    for(int i=0;i<T;i++){
        cin>>a>>b>>c;
        delta=b*b-4*a*c;
        if(delta<0) cout<<"NO"<<endl;
        else{
            x1=(0-b+sqrt(delta))/2*a;
            x2=(0-b-sqrt(delta))/2*a;
            cout<<max(x1,x2)<<endl;
        }
    }
    return 0;
}
//我是秦始皇,V我50助力我统一六国事成之后封你为C国侯掌管OI事物
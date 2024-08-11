#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int T,M,a,b,c,d;
    cin>>T>>M;
    for(int i=0;i<T;i++){
        cin>>a>>b>>c;
        d=b*b-4*a*c;
        if(d<0){
            cout<<"NO";
            continue;
        }
        else if(d==0){
            if(b==0){
                cout<<"0";
            }
            else{
                if((0-b)%(2*a)==0){
                    cout<<(0-b)%(2*a);
                }
                else{
                    cout<<0-b<<"/"<<2*a;
                }
            }
        }
        else{
            if((0-b)%(2*a)==0){
                cout<<(0-b)%(2*a);
            }
            else{
                cout<<0-b<<"/"<<2*a;
            }
            int xi=1;
            for(int j=2;j<sqrt(M);j++){
                if(d%(j*j)==0){
                    while(d%(j*j)!=0){
                        xi*=j;
                        d/=j*j;
                    }
                }
            }
            if(d==1){
            }
            else if(xi==1){
                cout<<"+sqrt("<<d<<")"<<"/"<<2*a;
            }
            else{
                a*=2;
                for(int j=2;j<xi;j++){
                    if(a%j==0 || xi%j==0){
                        a/=j;
                        xi/=j;
                    }
                }
                cout<<"+"<<xi<<"*"<<"sqrt("<<d<<")"<<"/"<<a;
            }
        }
        cout<<endl;
    }
    return 0;
}
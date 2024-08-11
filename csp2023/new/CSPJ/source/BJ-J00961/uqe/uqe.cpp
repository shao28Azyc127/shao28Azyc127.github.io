#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    long long t,m,a,b,c;
    cin>>t>>m;
    for(int i=0;i<t;i++){
            cin>>a>>b>>c;
        if(m==1){
           cout<<0<<endl;
           }
           else{
                if((b*b-4*a*c)<0)
                {cout<<"NO"<<endl;}
           else{
               cout<<1<<endl;
           }
        }

    }
    return 0;}

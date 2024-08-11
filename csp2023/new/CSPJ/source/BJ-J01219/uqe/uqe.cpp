#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
long long t,m,a,b,c,x;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    for(int i=1;i<=t;i++){
        cin>>a>>b>>c;
        x=b*b-4*a*c;
        if(x<0){
            cout<<"NO"<<endl;
            continue;
        }else if(x>=0){
            cout<<int((sqrt(x)-b)/2*a);
        }
    }
    return 0;
}

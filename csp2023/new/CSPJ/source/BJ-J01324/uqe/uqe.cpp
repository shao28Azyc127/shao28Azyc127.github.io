#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int t,m;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        if(m==1 and b==0 and c==0){
            cout<<0<<endl;
            continue;
        }
        double delta=b*b-4*a*c;
        if(delta<0){
            cout<<"NO"<<endl;
        }else if(delta==0){
            cout<<(-b/(2*a))<<endl;
        }else{
            double xx1=((-b+sqrt(delta))/(2*a)),xx2=((-b-sqrt(delta))/(2*a));
            cout<<max(xx1,xx2)<<endl;
        }
    }
    return 0;
}
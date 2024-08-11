#include<bits/stdc++.h>
using namespace std;
int T,M;
int a,b,c;
int dlt=0;
int num1=0;
int num2=0;
string ans;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>T>>M;
    while(T--){
        cin>>a>>b>>c;
        dlt=b*b-4*a*c;
        if(dlt<0){
            cout<<"NO"<<endl;
        }else if(dlt==0){
            num1=(-b+sqrt(dlt))/(2*a);
            cout<<num1<<endl;
        }else if(dlt>0){
            num1=(-b+sqrt(dlt))/(2*a);
            num2=(-b-sqrt(dlt))/(2*a);
            if(num1>num2){
                cout<<num1<<endl;
            }else{
                cout<<num2<<endl;
            }
        }
    }
    
    return 0;
}
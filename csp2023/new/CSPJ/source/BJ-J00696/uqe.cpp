#include<iostream>
#include<cmath>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin>>t>>m;
    for(int i=1;i<=t;i++){
        int a,b,c;
        cin>>a>>b>>c;
        int del=b*b-4*a*c;
        if(del<0)
        cout<<"NO"<<endl;
        else{
        int x1=(-b+sqrt(del))/(2*a);
        int x2=(-b+sqrt(del))/(2*a);
        if(x1>x2){
            cout<<x1<<endl;
        }else{
            cout<<x2<<endl;
        }
    }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
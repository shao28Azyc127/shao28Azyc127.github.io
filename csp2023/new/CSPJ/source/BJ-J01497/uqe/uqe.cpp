#include<bits/stdc++.h>
using namespace std;
long long n;
int t,m;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        int del=b*b-4*a*c;
        if(del<0){
            cout<<"NO"<<endl;
        }
        else if(del==0){
            cout<<sqrt(a)<<endl;
        }
    }
    return 0;
}

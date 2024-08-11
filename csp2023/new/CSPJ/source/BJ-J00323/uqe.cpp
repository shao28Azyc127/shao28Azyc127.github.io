#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int main(){
    freopen("uqe.in","w",stdin);
    freopen("uqe.out","r",stdout);
    int t,m;
    cin>>t>>m;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        int t=b*b-4*a*c;
        if(t<0){
            cout<<"NO"<<endl;
            continue;
        }
        
    }
    return 0;
}

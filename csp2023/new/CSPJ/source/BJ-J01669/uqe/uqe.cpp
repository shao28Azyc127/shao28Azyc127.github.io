#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    a=abs(a);
    b=abs(b);
    if(a==1){
        return 1;
    }
    if(a==0){
        return b;
    }else{
        gcd(b,a%b);
    }
}
bool isping(int n){
    if((int)(sqrt(n))*(int)(sqrt(n))==n){
        return 1;
    }
    return 0;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++){
        int a,b,c;cin>>a>>b>>c;
        if(b*b<4*a*c){
            cout<<"NO"<<endl;
            continue;
        }
        if(c==0){
            if(b<0){
                cout<<(-1)*b<<endl;
            }
            if(b>=0){
                cout<<0<<endl;
            }
            continue;
        }
        if(isping(b*b-4*a*c)){
            int d=sqrt(b*b-4*a*c);
            if(abs((-1*b+d))%abs((2*a))==0){
                cout<<((-1)*b+d)/(2*a)<<endl;
            }else{
                cout<<(-1*b+d)/gcd((-1*b+d),2*a)<<"/"<<(2*a)/gcd((-1*b+d),2*a)<<endl;
            }
        }else{
            if(((-1*b)/gcd((-1*b),2*a))/((2*a)/gcd((-1*b),2*a))!=0){
                cout<<(-1*b)/gcd((-1*b),2*a)<<"/"<<(2*a)/gcd((-1*b),2*a)<<"+"<<"sqrt("<<b*b-4*a*c<<")"<<endl;
            }else{
                cout<<"sqrt("<<b*b-4*a*c<<")"<<endl;
            }
        }
    }
    return 0;
}

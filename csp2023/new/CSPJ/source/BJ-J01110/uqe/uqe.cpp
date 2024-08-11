#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
int out(int a){
    int ans=1;
    for(int i=2;i*i<=a;i++){
        while(!(a%(i*i))){
            a/=(i*i);
            ans*=i;
        }
    }
    return ans;
}
bool fra(int a,int b){
    if(a){
        if(b==1){
            cout<<a;
        }
        else{
            cout<<a<<'/'<<b;
        }
        return 0;
    }
    else{
        return 1;
    }
}
int main(){
    int t,m;
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    for(int i=1;i<=t;i++){
        int a,b,c,q1q,q1p,q2q,q2p,r,o;
        cin>>a>>b>>c;
        if((b*b-4*a*c)<0){
            cout<<"NO"<<endl;
            continue;
        }
//        q1p=abs(-b)/gcd(abs(-b),abs(2*a))*(-b)*(2*a)/abs((-b)*(2*a));
        q1p=abs(-b)/gcd(abs(-b),abs(2*a))*((-b)*(2*a)>=0?1:-1);
        q1q=abs(2*a)/gcd(abs(-b),abs(2*a));
        o=out(b*b-4*a*c);
        r=(b*b-4*a*c)/o/o;
        q2p=o/gcd(o,abs(2*a));
        q2q=abs(2*a)/gcd(o,abs(2*a));
        if(r!=1&&r!=0){
            fra(q1p,q1q);
            if(q1p){
                cout<<'+';
            }
//            if(q2p!=q2q){
                if(q2p!=1){
                    cout<<q2p<<'*';
                }
                cout<<"sqrt("<<r<<')';
                if(q2q!=1){
                    cout<<'/'<<q2q;
//                }
            }
        }
        else{
            if(r==0){
                if(fra(q1p,q1q)){
                    cout<<0;
                }
            }
            else{
                if(fra((q1p*q2q+q2p*q1q)/gcd(abs(q1p*q2q+q2p*q1q),abs(q1q*q2q)),(q1q*q2q)/gcd(abs(q1p*q2q+q2p*q1q),abs(q1q*q2q)))){
                    cout<<0;
                }
            }
        }
        cout<<endl;
    }
    return 0;
}

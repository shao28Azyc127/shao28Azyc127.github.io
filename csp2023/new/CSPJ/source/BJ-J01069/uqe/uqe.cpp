#include<iostream>
#include<cmath>
using namespace std;
int gcd(int n,int m){
    if(n<0){
        n=-n;
    }
    if(m<0){
        m=-m;
    }
    if(n<m){
        swap(n,m);
    }
    if(m==0){
        return n;
    }else{
        return gcd(m,n%m);
    }
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m,a,b,c;
    cin>>t>>m;
    for(int i=1;i<=t;i++){
        cin>>a>>b>>c;
        int delta=b*b-4*a*c;
        if(delta<0){
            cout<<"NO"<<endl;
            continue;
        }
        if((int)sqrt(delta)*(int)sqrt(delta)==delta){
            if((int)(-b+sqrt(delta))%(2*a)==0){
                cout<<(int)(-b+sqrt(delta))/(2*a)<<endl;
                continue;
            }
            cout<<(int)(-b+sqrt(delta))/gcd((int)(-b+sqrt(delta)),2*a)<<'/'<<(2*a)/gcd((int)(-b+sqrt(delta)),2*a)<<endl;
            continue;
        }
        if(-b/(2*a)!=0){
            if(-b%(2*a)==0){
                cout<<-b/(2*a)<<'+';
            }else{
                cout<<(-b)/gcd(-b,2*a)<<'/'<<(2*a)/gcd(-b,2*a)<<'+';
            }
        }
        int n=1,m=delta;
        for(int i=2;i*i<=delta;i++){
            if(delta%(i*i)==0){
                n=i;
                m=delta/(i*i);
            }
        }
        if(n==2*a){
            cout<<"sqrt("<<m<<')';
        }else if(n%(2*a)==0){
            cout<<n/(2*a)<<'*'<<"sqrt("<<m<<')';
        }else if((2*a)%n==0){
            cout<<"sqrt("<<m<<')'<<'/'<<(2*a)/n;
        }else{
            cout<<n/gcd(n,2*a)<<'*'<<"sqrt("<<m<<')'<<'/'<<(2*a)/gcd(n,2*a);
        }
        cout<<endl;
    }
    return 0;
}

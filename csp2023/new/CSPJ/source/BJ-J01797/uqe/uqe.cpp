#include<bits/stdc++.h>
using namespace std;
int t,m;
int gcd(int a,int b){
    if(a%b==0){
        return b;
    }
    int c=a%b;
    if(c<0){
       c=b+c;
    }
    return gcd(b,c);
}
int fj(int n){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0&&sqrt(n/i)*sqrt(n/i)==n/i){
            return n/i;
        }
        if(n%i==0&&sqrt(i)*sqrt(i)==i){
            return i;
        }
    }
    return 1;
}
void hj(int a,int b){
    if(a%b==0){
        cout<<a/b;
    }else{
        int ggcd=gcd(a,b);
        if(ggcd==1){
            cout<<a<<"/"<<b;
        }else{
            cout<<a/ggcd<<"/"<<b/ggcd;
        }
    }
    return;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    for(int i=1;i<=t;i++){
        int a,b,c;
        cin>>a>>b>>c;
        int temp=b*b-4*a*c;
        if(temp<0){
            cout<<"NO"<<endl;
            continue;
        }
        int r;
        if(sqrt(temp)==int(sqrt(temp))){
            r=0-b+sqrt(temp);
            hj(r,2*a);
            cout<<endl;
        }else{
            if(b!=0){
                hj(0-b,2*a);
                cout<<"+";
            }
            int n=fj(temp);
            int so=sqrt(n),mo=2*a;
            int gys=gcd(so,mo);
            so/=gys,mo/=gys;
            if(so!=1){
                cout<<so<<"*";
            }
            cout<<"sqrt("<<temp/n<<")";
            if(mo!=1){
                cout<<"/"<<mo;
            }
            cout<<endl;
        }
    }
    return 0;
}

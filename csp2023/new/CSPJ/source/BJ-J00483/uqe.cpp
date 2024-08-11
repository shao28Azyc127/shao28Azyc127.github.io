#include<bits/stdc++.h>
using namespace std;
int t,m,a,b,c;
int d;
int f;
struct stu{
    int a;
    int b;
    int c;
}l[10010];
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    for(int i=1;i<=t;i++){
        cin>>l.a>>l.b>>l.c;
    }
    if((b)*(b)-(4*(a)*(c)<0)){
        cout<<"NO";
        return 0;
    }
    d=sqrt((b)*(b)-(4*(a)*(c)));
    if((b)*(b)-(4*(a)*(c))==0){
        if(d*d==(b)*(b)-(4*(a)*(c))){
            if(double ((b*(-1)+d))==int ((b*(-1)+d))){
                if(double ((b*(-1)+d)/2*a)==int ((b*(-1)+d)/2*a)){
                    cout<<((b*(-1)+d)/2*a);
                }
                else{
                    cout<<(b*(-1)+d)<<"/"<<2*a;
                }
            }
        }
        else
            cout<<b*(-1)<<"+"<<sqrt(d)<<"/"<<2*a;
        return 0;
    }
    if((b)*(b)-(4*(a)*(c))>0){
        if(((b)*(-1)-d)/2*(a)>((b)*(-1)+d)/2*(a))
            if(d*d==(b)*(b)-(4*(a)*(c))){
                if(double ((b*(-1)+d))==int ((b*(-1)+d))){
                    if(double ((b*(-1)+d)/2*a)==int ((b*(-1)+d)/2*a)){
                        cout<<((b*(-1)+d)/2*a);
                    }
                    else{
                        cout<<(b*(-1)+d)<<"/"<<2*a;
                    }
                }
            }
            else{
                cout<<b*(-1)<<"+"<<sqrt(d)<<"/"<<2*a;
            }

    }
    else{
        if(d*d==(b)*(b)-(4*(a)*(c))){
            if(double ((b*(-1)-d))==int ((b*(-1)-d))){
                if(double ((b*(-1)-d)/2*a)==int ((b*(-1)-d)/2*a)){
                    cout<<((b*(-1)-d)/2*a);
                }
                else{
                    cout<<(b*(-1)-d)<<"/"<<2*a;
                   }
            }
        }
        else{
            cout<<b*(-1)<<"+"<<sqrt(d)<<"/"<<2*a;
        }
        return 0;
    }
    return 0;
}

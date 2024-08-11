#include<bits/stdc++.h>
using namespace std;
void gcbb(int &x,int &y){
    int targ=1;
    for(int i=1;i<=min(x,y);i++){
        if(x%i==0 and y%i==0){
            targ=i;
        }
    }
    x=x/targ;
    y=y/targ;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin>>t>>m;
    for(int i=1;i<=t;i++){
    int a,b,c;
    cin>>a>>b>>c;
    int det=b*b-4*a*c;
    if(det<0){
        cout<<"NO"<<endl;
    }
    int d=1;
    for(int i=1;i<=sqrt(det);i++){
        if(det%(i*i)==0 and i>d){
            d=i;
        }
    }
    int sq=det/(d*d);
    int b0=-b;
    int a0,a1=2*a;
    gcbb(b0,a0);
    gcbb(d,a1);
    if(a0==1){
        if(a1==1){
            if(sq==1){
                cout<<b0+d<<endl;
            }
            else{
                cout<<b0<<"+"<<d<<"*sqrt("<<sq>>")"<<endl;
                }
        }
        else if(sq==1){
            cout<<b0<<"+"<<d<<"/"<<a1<<endl;
        }
        else{
            cout<<b0<<"+"<<d<<"*sqrt("<<sq<<")/"<<a1<<endl;
        }

    }
    else if(sq==1){
        cout<<b0<<"/"<<a0<<"+"<<d<<"/"<<a1<<endl;
    }
    else{
        cout<<b0<<"/"<<a0<<"+"<<d<<"*sqrt("<<sq<<")/"<<a1<<endl;
    }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
    }
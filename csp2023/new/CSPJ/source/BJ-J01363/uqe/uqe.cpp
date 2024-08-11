#include <iostream>
using namespace std;
int print1(int a,int b){
    bool less=false;
    if(int(a/b)*b==a){
        cout<<a/b<<endl;
        return 0;
    }
    if(b<0&&a<0){
        a=-a;b=-b;
    }
    if(b<0){
        b=-b;
        less=true;
    }
    if(a<0){
        a=-a;
        less=true;
    }
    for(int i=2;i<=min(a,b);i++){
        if(a%i==0&&b%i==0){
            a/=i;
            b/=i;
        }
    }
    if(less) cout<<"-";
    cout<<a<<'/'<<b;
    return 0;
}
int print2(int a;int b;int c){
    print1(a,c);
    cout<<"+";
    int able=1;
    for(int i=2;i*i<=b;i++){
        while(b%(i*i)==0){
            b/=i*i;
            able*=i;
        }
    }
    for(int i=2;i<=min(able,c);i++){
        while(c%i==0&&able%i==0){
            c/=i;
            able/=i;
        }
    }
    if(able>1){
        cout<<able<<"*";
    }
    cout<<"sqrt("<<b<<")";
    if(c>1){
        cout<<"/"<<c;
    }
    return 0;
}
int main(){
    freopen("uqe.in",'r',stdin);
    freopen("uqe.out",'w',stdout);
    int a,b,c,n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c;
        if(b*b-4*a*c<0){
            cout<<"No"<<endl;
            continue;
        }
        if(int(sqrt(b*b-4*a*c))*int(sqrt(b*b-4*a*c))==b*b-4*a*c){
            if(a>0){
                print1(-b+sqrt(b*b-4*a*c),2*a);
            }
            else print1(-b-sqrt(b*b-4*a*c),2*a);
            cout<<endl;
            continue;
        }
        if(a>0){
            print2(-b,b*b-4*a*c,2*a);
        }
        else print2(-b,-b*b-4*a*c,2*a);
        cout<<endl;
    }
    return 0;
}
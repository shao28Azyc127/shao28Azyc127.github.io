#include <bits/stdc++.h>
using namespace std;

int t,m,v;
int w;
double x,x1,x2;

void f(int a,int b,int c){
    
    w=b*b-4*a*c;
    if(w<0){
        cout<<"NO"<<endl;
        return;
    }
    x1=(-b+sqrt(w))/(2*a);
    x2=(-b-sqrt(w))/(2*a);
    if(x1-x2>=0.00001){
        x=
    }

}

int main(){

    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);

    cin>>t>>m;
    for(int i=1;i<=t;i++){
        int a,b,c;
        f(a,b,c);
    }
    return 0;
}

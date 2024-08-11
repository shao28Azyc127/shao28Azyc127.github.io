#include<bits/stdc++.h>
using namespace std;
int t,m;
void fun1(int v){
    for(int p=-m;p<=m;p++){
        if(p%v==0){
            int q=p/v;
            if(q>0){
                if(q==1){
                    cout<<p;
                }else{
                    cout<<p<<"/"<<q;
                }
                cout<<endl;
                return;
            }
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
        int t=b*b-4*a*c;
        if(t<0){
            cout<<"NO"<<endl;
        }else{
            double x1=(-b+sqrt(t))/(2*a);
            double x2=(-b-sqrt(t))/(2*a);
            int x;
            if(x1>=x2) x=x1;
            else x=x2;
            fun1(x);
        }
    }
    return 0;
}

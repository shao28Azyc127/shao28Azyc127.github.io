#include<bits/stdc++.h>
using namespace std;
bool iuqe(int a,int b,int c){
    int x=pow(b,2)-4*a*c;
    if(x<0)return false;
    else return true;
}
int main(){
    freopen("uqe.in",r);
    freopen("uqe.out",w);
    int t,m;
    cin>>t>>m;
    int a,b,c;
    for(int i=0;i<t;i++){
        cin>>a>>b>>c;
        if(iuqe(a,b,c)==0){
            cout<<"NO"<<endl;
            continue;
        }
        double d=pow(b,2)-4*a*c;
        double p1=-b+sqrt(d);
        double p2=-b-sqrt(d);
        long long q=a*a;
        double x1=p1/q;
        double x2=p2/q;
        if(x2>x1){
            if(x2%1!=0){
                int m=gcd(p2,q);
                cout<<p2/m<<"/"<<q/m<<endl;
            }
            else cout<<int(x2)<<endl;
        }
        else{
            if(x1%1!=0){
                int m=gcd(p1,q);
                cout<<p1/m<<"/"<<q/m<<endl;
            }
            else cout<<int(x1)<<endl;
        }
    }
    fclose();
    return 0;
}
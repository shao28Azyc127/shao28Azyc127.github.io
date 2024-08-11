#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    long long t,m;
    cin >> t >> m;
    for(int i=1;i<=t;i++){
        long long a,b,c,d;
        double x;
        cin >> a >> b >> c;
        d=b*b-4*a*c;
        if(d<0){
            cout<<"NO"<<endl;
            continue;
        }
        else{
            x=(-b+sqrt(d))/(2*a);
            if(x==floor(x))cout <<x<<endl;
            else{
                if(sqrt(d)==floor(sqrt(d))){
                    cout<<-b+sqrt(d)<<"/"<<2*a<<endl;
                }
                else{
                    long long p=0,q=0;
                    //cout <<sqrt(d)<<endl;
                    q = floor(sqrt(d));
                    //cout<<q<<endl;
                    p = d-q*q;
                    cout <<-b<<"/"<<2*a<<"+"<<("sqrt(")<<p<<(")")<<"/"<<2*a<<endl;
                }
            }
        }
    }
    return 0;
}

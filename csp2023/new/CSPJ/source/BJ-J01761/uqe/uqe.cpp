#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

double gcd(int a,int b){
    if(a==0) return b;
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin>>t>>m;
    while(t--){
        int a,b,c;
        double delta,xbig;
        cin>>a>>b>>c;
        delta=b*b-4*a*c;
        if(delta<0){
            cout<<"NO"<<endl;
        }else{
            if(delta!=0) xbig=(0-b+sqrt(delta))/(2*a);
            else xbig=(0-b)/(2*a);
            if(sqrt(delta)==int(sqrt(delta))){
                int cgcd=gcd((0-b+sqrt(delta)),2*a);
                if(2*a/cgcd<0) cout<<'-';
                cout<<(0-b+sqrt(delta))/cgcd;
                if(fabs(2*a/cgcd)!=1) cout<<'/'<<fabs(2*a/cgcd);
            }else{
                ;
            }cout<<endl;
        }
    }return 0;
}

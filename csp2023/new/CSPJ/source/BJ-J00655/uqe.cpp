#include <bits/stdc++.h>
using namespace std;
int T,M;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>T>>M;
    while(T--){
        double a,b,c;
        cin>>a>>b>>c;
        double p=b*b-4*a*c;
        if(p<0){
            cout<<"NO"<<endl;
            continue;
        }
        double x1,x2;
        x1=(-b)-sqrt(p);
        x1=x1*1.0/(2*a*1.0);
        x2=(-b)+sqrt(p);
        x2=x2*1.0/(2*a*1.0);
        cout<<max(x1,x2)<<endl;
    }
    return 0;
}

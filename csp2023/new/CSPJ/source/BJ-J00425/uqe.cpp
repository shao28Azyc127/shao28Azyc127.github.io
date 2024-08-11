//佛祖保佑
//佛祖保佑
//佛祖保佑
//佛祖保佑
//佛祖保佑
#include <bits/stdc++.h>
using namespace std;
int t,m,a,b,c;
int gcd(int a,int b){
    while(a!=b) (a>b)?(a-=b):(b-=a);
    return a;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    for(int z=1;z<=t;z++){
        cin>>a>>b>>c;
        int delta=b*b-4*a*c;
        if(delta<0){
            cout<<"NO"<<endl;
        }
        else{
            if(c==0){
                if(b*a<0){
                    int g=gcd(abs(a),abs(b));
                    if(a!=g){
                        cout<<abs(b)/g<<"/"<<abs(a)/g<<endl;
                    }
                    else{
                        cout<<abs(b)/g<<endl;
                    }
                }
                else{
                    cout<<"0"<<endl;
                }
            }
            else{
                double x=(-1*b+sqrt(delta))/(2*a);
                cout<<x<<endl;
            }

        }
    }
    return 0;
}

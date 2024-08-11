#include<cmath>
#include<iostream>
using namespace std;
int a,b,c,delta,m,t;
bool is_int(double x){
    if((int)x==x)return 1;
    else return 0;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    while(t--){
        cin>>a>>b>>c;
        delta=b*b-4*a*c;
        if(delta<0)cout<<"NO\n";
        else{
            if(is_int(sqrt(delta))){
                if(is_int((-b+sqrt(delta))/(2*a)))cout<<(-b+sqrt(delta))/(2*a);
                else cout<<(-b+sqrt(delta))<<" "<<(2*a);
            }
            else{
                if(!b)cout<<"sqrt("<<delta<<")/"<<(2*a);
                else cout<<-b<<"+sqrt("<<delta<<")/"<<(2*a);
            }
            cout<<endl;
        }
    }
    return 0;
}

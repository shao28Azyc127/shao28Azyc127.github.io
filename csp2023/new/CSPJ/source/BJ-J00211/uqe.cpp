#include<bits/stdc++.h>
using namespace std;
bool isI(double t){
    int x=t;
    if(t-x==0) return true;
    return false;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,d;
    cin>>t>>d;
    while(t--){
        doube delta=b*b-4*a*c;
        if(delta<0) cout<<"NO";
        else if(delta>=0){
            if(isI(sqrt(delta))==true){
                int gen=(sqrt(delta)-b)/(2*a);
                if(isI(gen)==true){
                    cout<<gen<<endl;
                }
            }else{
                cout<<(-b)/(2*a)<<"+sqrt("<<delta<<")"<<endl;
            }
        }
    }
    return 0;
}
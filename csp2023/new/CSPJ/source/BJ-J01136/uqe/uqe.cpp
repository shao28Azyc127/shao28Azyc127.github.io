#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin>>t>>m;
    while(t--){
        int a,b,c;
        double v;
        cin>>a>>b>>c;
        v=b*b-4*a*c;
        if(v<0){
            cout<<"NO"<<endl;
        }
        else{
            if(c==0){
                cout<<0<<endl;
            }
        }
    }
    return 0;
}

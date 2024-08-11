#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int t,m;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    for(int i=1;i<=t;i++){
        cin>>a>>b>>c;
        if(b*b-4*a*c<0){
            cout<<"NO"<<endl;
            continue;
        }
        if(b==0 && c==0){
            cout<<0<<endl;
            continue;
        }
        cout<<(-b+sqrt(b*b-4*a*c))/(2*a)<<endl;
    }
    return 0;
}

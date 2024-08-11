#include <bits/stdc++.h>
using namespace std;
int t,m;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        if(b*b-4*a*c<0){
            cout<<"NO"<<'\n';
        }else{
            cout<<int(max((-b+sqrt(b*b-4*a*c))/(2*a),(-b-sqrt(b*b-4*a*c))/(2*a)))<<'\n';
        }
    }
    return 0;
}


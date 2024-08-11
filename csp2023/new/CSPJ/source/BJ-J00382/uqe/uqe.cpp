#include<bits/stdc++.h>
using namespace std;
int t,m,a,b,c,tp;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    for(int i=1;i<=t;i++){
        cin>>a>>b>>c;
        int tp=b*b-4*a*c;
        if(tp<0){
            cout<<"NO\n";
            continue;
        }else{
            int k1=-b+int(sqrt(tp)),k2=-b+int(sqrt(tp));
            k1/=(2*a),k2/=(2*a);
            cout<<max(k1,k2)<<'\n';
        }
    }
    return 0;
}

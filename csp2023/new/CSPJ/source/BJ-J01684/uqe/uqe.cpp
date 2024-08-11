#include<bits/stdc++.h>
using namespace std;
int t,m,a,b,c;
set<int>s;
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    while(t--){
        cin>>a>>b>>c;
        if(b*b-4*a*c<0) cout<<"NO"<<endl;
        else{
            int delta=b*b-4*a*c;
            int ans1=(-b+sqrt(delta))/(2*a),ans2=(-b-sqrt(delta))/(2*a);
            //cout<<-b-sqrt(delta)<<" "<<-b+sqrt(delta)<<" "<<2*a<<endl;
            cout<<max(ans1,ans2)<<endl;
        }
    }
    return 0;
}
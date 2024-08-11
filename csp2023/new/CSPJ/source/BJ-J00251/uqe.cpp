#include<bits/stdc++.h>
using namespace std;
long long t,m;
long long a,b,c;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    for(int i=0;i<t;i++){
        cin>>a>>b>>c;
        long long u=b*b-4*a*c;
        if(u<0)cout<<"NO"<<endl;
        else cout<<max((-b+sqrt(u))/(2*a),(-b-sqrt(u))/(2*a))<<endl;
    }
    return 0;
}

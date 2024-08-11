#include <bits/stdc++.h>
using namespace std;
struct yls{
    long long p;
    long long q;
};
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin.tie(0);
    ios::sync_with_stdio(0);
    long long t,m;
    cin>>t>>m;
    while(t--){
        long long a,b,c;
        cin>>a>>b>>c;
        long long tmp=b*b-4*a*c;
        if(tmp<0)cout<<"NO\n";
        else if(tmp==0){
            cout<<(0-b)/(2*a)<<endl;
        }
        else{
            long long x=(-b+sqrt(tmp))/(2*a),y=(-b-sqrt(tmp))/(2*a);
            cout<<max(x,y)<<endl;
        }
    }

    return 0;
}

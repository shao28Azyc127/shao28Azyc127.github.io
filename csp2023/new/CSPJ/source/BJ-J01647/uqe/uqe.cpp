#include <bits/stdc++.h>
using namespace std;
signed main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,m;
    cin>>t>>m;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        if(b==0&&c==0)cout<<"0\n";
        else if(b*b-4*a*c<0)cout<<"NO\n";
        else{
            cout<<max((int)((-b+sqrt(b*b-4*a*c))/(2*a)),(int)((-b-sqrt(b*b-4*a*c))/(2*a)))<<"\n";
        }
    }
}

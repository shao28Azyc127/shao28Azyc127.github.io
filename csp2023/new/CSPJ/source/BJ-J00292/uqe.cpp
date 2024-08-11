#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+6;
int t,m;
signed main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        if(b*b-4*a*c<0) puts("NO");
        else if(b*b-4*a*c==0) cout<<'0'<<endl;
        else cout<<b*b-4*c*a<<endl;
    }
    return 0;
}

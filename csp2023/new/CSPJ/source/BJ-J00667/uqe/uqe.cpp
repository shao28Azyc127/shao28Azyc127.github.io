#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define mod 1000000007
using namespace std;
signed main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int T,M;
    cin>>T>>M;
    while(T--){
        int a,b,c;
        cin>>a>>b>>c;
        if(b*b<4*a*c){
            cout<<"NO"<<endl;
        }else{
            cout<<max((-b+sqrt(b*b-4*a*c))/2/a,(-b-sqrt(b*b-4*a*c))/2/a)<<endl;
        }
    }
    return 0;
}

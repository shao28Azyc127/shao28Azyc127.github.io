#include<bits/stdc++.h>
using namespace std;
bool check(int n){
    for(int i=1;i<=sqrt(n)+1;i++)
        if(n/i==i) return true;
    return false;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t,m;
    cin>>t>>m;
    for(int i=1;i<=t;i++){
        int a,b,c;
        cin>>a>>b>>c;
        int dt=b*b-4*a*c;
        if(dt<0) cout<<"NO"<<endl;
        else if(dt==0) cout<<-1*b/2*a<<endl;
        else if(dt>0){
            check(dt);
            if(check){
                int x=(-1*b+sqrt(dt))/2*a;
                cout<<x<<endl;
            }
            else cout<<-1*b<<"/"<<2*a<<"+"<<"sqrt("<<dt<<")/"<<2*a<<endl;
        }
    }
    return 0;
}
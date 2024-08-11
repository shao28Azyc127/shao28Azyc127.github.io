#include <bits/stdc++.h>
using namespace std;
int t,a,b,c,dt,up;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>up,++t;
    while(--t){
        cin>>a>>b>>c,dt=b*b-4*a*c;
        if(dt<0) cout<<"NO\n";
        else{
            double ans1=(-b+sqrt(dt))/2*a,ans2=(-b+sqrt(dt))/2*a;
            cout<<max(ans1,ans2)<<"\n";
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int t,m,a,b,c;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    while(t--){
        cin>>a>>b>>c;
        int del=b*b-4*a*c;
        if(del<0) cout<<"NO\n";
        else{
            cout<<max((-b+sqrt(del)/(2*a)),(-b-sqrt(del))/(2*a))<<"\n";
        }
    }
    return 0;
}

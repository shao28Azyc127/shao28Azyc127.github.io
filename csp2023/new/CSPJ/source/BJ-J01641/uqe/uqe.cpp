#include<bits/stdc++.h>
using namespace std;
int t,m,a,b,c,s;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    for(int i=1;i<=t;i++){
        cin>>a>>b>>c;
        s=b*b-4*a*c;
        if(s<0)cout<<"NO"<<endl;
        else cout<<1<<endl;
    }
    return 0;
}

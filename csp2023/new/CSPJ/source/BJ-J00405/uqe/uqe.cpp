#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,m;
    freopen("uqe.in.in","r",stdin);
    cin>>t>>m;
    for(int i=1;i<=t;i++){
        int d,a,b,c;
        d=b*b-4*a*c;
        cin>>a>>b>>c;
        if(d<0){
        freopen("uqe.out.out","w",stdout);
            cout<<"NO";
        }else{
        freopen("uqe.out.out","w",stdout);
            cout<<-1*b/2/a<<"+sprt("<<d/2/a<<")";
        }
    }
    return 0;
}
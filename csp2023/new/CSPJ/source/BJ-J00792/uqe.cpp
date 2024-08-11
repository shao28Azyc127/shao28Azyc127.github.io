#include<bits/stdc++.h>
using namespace std;
int de(int a,int b,int c){
    return b*b-4*a*c;
}
int qi(int del,int a,int b){
    int x1,x2;
    x1=((0-b)+(int)(sqrt(del)))/(2*a);
    x2=((0-b)-(int)(sqrt(del)))/(2*a);
    return max(x1,x2);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin>>t>>m;
    for(int i=1;i<=t;i++){
        int a,b,c;
        cin>>a>>b>>c;
        int del=de(a,b,c);
        if(del<0) cout<<"NO"<<endl;
        else if(del>=0){
            cout<<qi(del,a,b)<<endl;
        }
    }
    return 0;
}

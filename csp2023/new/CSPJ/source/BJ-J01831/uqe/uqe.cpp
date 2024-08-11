#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int g(int a,int b){
    if(a%b==0){
        return b;
    }
    return g(b,a%b);
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int n,m,i;
    cin>>n>>m;
    int a,b,c;
    for(i=1;i<=n;i++){
        cin>>a>>b>>c;
        double d=b*b+4*a*c;
        if(d<0){
            cout<<"NO";
            continue;
        }
        if(d==0){
            cout<<(-1)*b/g(max(2*a,b),min(2*a,b))<<"/"<<2*a/g(max(2*a,b),min(2*a,b));
        }
        else{
            if(sqrt(d)*sqrt(d)==d){
                cout<<(-1)*b/g(max(2*a,b),min(2*a,b))<<"/"<<2*a/g(max(2*a,b),min(2*a,b))<<"+"<<sqrt(d)/g(max(sqrt(d),2*a),min(sqrt(d),2*a))<<"/"<<2*a/g(max(sqrt(d),2*a),min(sqrt(d),2*a));
            }else{
                cout<<(-1)*b/g(max(2*a,b),min(2*a,b))<<"/"<<2*a/g(max(2*a,b),min(2*a,b))<<"+"<<sqrt(d)/g(max(sqrt(d),2*a),min(sqrt(d),2*a))<<"sqrt("<<d-sqrt(d)*sqrt(d)<<")<<"/"<<2*a/g(max(sqrt(d),2*a),min(sqrt(d),2*a));
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

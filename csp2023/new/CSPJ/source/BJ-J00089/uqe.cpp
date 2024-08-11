#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m,a,b,c;
    cin>>t>>m;
    
    for(int i=0;i<t;i++){
        cin>>a>>b>>c;
        if(b==0&&c==0){
            cout<<0;
        }
        if(pow(b,2)<4*a*c){
            cout<<NO;
        }else if(pow(b,2)==4*a*c){
            int l=2*a,n=-b;
            if(n%l==0){
                cout<<n/l;
            }
            else cout<</__gcd(n,l)<<"/"<<l/__gcd(n,l);
        }
    }
    return 0;
}

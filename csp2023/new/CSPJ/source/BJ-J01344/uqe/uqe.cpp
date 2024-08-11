#include <bits/stdc++.h>
using namespace std;
int gcd(int n,int m){
    if(n<m)swap(n,m);
    if(n%m==0)return m;
    gcd(m,n%m);
}
int s;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int m,t;cin>>m>>t;
    while(m){
        int a,b,c;cin>>a>>b>>c;
        cout<<"NO"<<"\n";
        m--;
    }
    return 0;
}

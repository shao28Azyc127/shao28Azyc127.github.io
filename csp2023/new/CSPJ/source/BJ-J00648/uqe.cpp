#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int maxn=1e4+10;
int a,b,c,m;
int gcd(int x,int y){
    if(x%y==0) return y;
    return gcd(y,x%y);
}
void so(){
    cin>>a>>b>>c;
    int d=b*b-4*a*c;
    if(d<0){
        cout<<"NO\n";
        return;
    }
    double x1=(1.0*-b+sqrt(d))/2/a;
    double x2=(1.0*-b-sqrt(d))/2/a;
    if(x1<x2) swap(x1,x2);
    for(int i=-1000;i<=1000;i++){
        int j=1.0*i/x1;
        if(1.0*i/j==x1&&abs(gcd(i,j))==1){
            if(i%j==0) cout<<i/j<<endl;
            else cout<<i<<'/'<<j<<endl;
            return;
        }
    }
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t;cin>>t>>m;
    while(t--) so();
    return 0;
}


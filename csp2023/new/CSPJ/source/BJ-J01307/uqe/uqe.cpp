#include<bits/stdc++.h>
#define int long double
using namespace std;
int t,m;
int a,b,c;
bool is_yl(int x){
    int q;
    int p=x*q;
    if(p/q==x) return true;
    else return false;
}
void write(int x){
    int p=1;
    int q=1/x;
    long long p1,q1;
    p1=p*1000;
    q1=q*1000;
    int gcd=__gcd(p1,q1);
    p1/=gcd,q1/=gcd;
    if(q1==1) cout<<p1;
    else cout<<p1<<"/"<<q1;
}
signed main(){
    ios::sync_with_stdio(false);
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    while(t--){
        cin>>a>>b>>c;
        if(b==0&&c==0){
            cout<<0;
            continue;
        }
        if(b*b-4*a*c<0) cout<<"NO";
        else if(b*b-4*a*c==0){
            int delta=(-b+sqrt((b*b-4*a*c)))/2;
            if(is_yl(delta)){
                write(delta);
            }
        }
    }
    return 0;
}

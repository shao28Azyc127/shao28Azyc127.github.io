#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,ans;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>n>>m;
    while(n--){
        int a,b,c;
        cin>>a>>b>>c;
        if(-1*b%a==0)cout<<-1*b/a<<'\n';
        else {
            if(a/__gcd(-1*b,a)>0)cout<<(-1)*b/__gcd(-1*b,a)<<'/'<<a/__gcd(-1*b,a)<<'\n';
            else cout<<b/__gcd(-1*b,a)<<'/'<<(-1)*a/__gcd(-1*b,a)<<'\n';
        }
    }
    return 0;
}

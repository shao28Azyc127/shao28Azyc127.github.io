#include<bits/stdc++.h>
using namespace std;
int t,m,a,b,c;
long long x;
bool check(int a,int b,int c){
    int ans=b*b-4*a*c;
    if(ans<0) return 0;
    return 1;
}
long long mae(int a,int b,int c){
    long long an=b*b-4*a*c,ans;
    an=sqrt(an);
    ans=-1*b+an;
    ans=ans/2*a;
    return ans;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    while(t--){
        cin>>a>>b>>c;
        bool f=check(a,b,c);
        if(!f) cout<<"NO"<<endl;
        else{
            x=mae(a,b,c);
            cout<<x<<endl;
        }
    }
    return 0;
}

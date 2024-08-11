#include<bits/stdc++.h>
#include<cmath>
#include<algorithm>
using namespace std;
int t,m;
int a,b,c;
int ans;

int gcd(int x){
    int r1,r2;
    for(int i=1;i<=x;i++){
        if(x/i%1==0) r1=i,r2=x/i;
    }
    if(r1==1) return r2;
    if(r2==1) return r1;
    else return r1/r2;

}

int main(){
    int x;
    int x1,x2;
    cin>>t,m;
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    for(int i=1;i<=t;i++){
        cin>>a>>b>>c;
        if((b*b-4*(a*c))<0) cout<<"NO"<<endl;
        if((b*b-4*(a*c))==0){
            x=(-b+sqrt(b*b-4*(a*c)))/2*a;
            cout<<gcd(x)<<endl;
        }
        if((b*b-4*(a*c))==0){
            x1=(-b+sqrt(b*b-4*(a*c)))/2*a;
            x2=(-b-sqrt(b*b-4*(a*c)))/2*a;
            if(x1>x2) x=x1;
            else x=x2;
            cout<<gcd(x)<<endl;
        }
    }
    return 0;
}

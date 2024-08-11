#include<bits/stdc++.h>
using namespace std;
long long a,b,c,tr,q,w;
long long gcd(long long w,long long r){
    long long t=1;
    for(int i=1;i<=min(w,r);i++){
        if(w%i==0 and r%i==0)
            t=i;
    }
    return t;
}
void ctt(long long a1,long long b1){
            if((a1%b1)!=0)
            cout<<a1/gcd(a1,b1)<<"/"<<b1/gcd(a1,b1)<<endl;
            else
            cout<<a1/b1<<endl;
            //cout<<gcd(a1,b1)<<endl;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
  cin>>q>>w;

    for(int i=1;i<=q;i++){
    cin>>a>>b>>c;
    tr=b*b-4*a*c;
    if(tr<0)cout<<"NO"<<endl;
    if(tr==0)cout<<0;
    if(tr>0){
        if(sqrt(double(tr))==floor(double(sqrt(tr)))){
            ctt(sqrt(tr)-b,2*a);
        }

    }
    }

    return 0;
}
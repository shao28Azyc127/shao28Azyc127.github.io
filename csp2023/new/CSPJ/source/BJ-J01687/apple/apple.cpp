#include<bits/stdc++.h>
using namespace std;
int nstep=-1;
int getn (long long n,int maxstep){
    int ans;
    if(n%3==1&&nstep==-1){
            nstep=maxstep;
    }
    if(n==0){
        return 0;
    }
    long long minusn=n/3;
    if(n%3!=0){minusn++;}
    n=n-minusn;
    return getn(n,maxstep+1)+1;
}
int main(){
    long long n;
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int ans=getn(n,1);
    cout<<ans<<' '<<nstep<<endl;
    return 0;
}

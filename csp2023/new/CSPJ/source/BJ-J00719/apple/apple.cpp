#include<bits/stdc++.h>
using namespace std;
int sz(double x){
    double t=int(x);
    if((x-t)!=0){
        return int(x+1);
    }else{
        return int(x);
    }
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int ans1=0,ans2=0;
    bool nflag=false;
    while(n!=0){
        if(n%3==1&&nflag==false){
            ans2=ans1+1;
            nflag=true;
        }
        double t=n;
        n-=sz(t/3);
        ans1++;
        //cout<<ans2<<endl;
    }
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}

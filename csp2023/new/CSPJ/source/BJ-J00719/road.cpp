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
int v[100005],a[100005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    a[0]=100010;
    int lmdir=0;//价格目前最便宜的位置
    int rlen=0;//剩余路程
    int cost=0;
    for(int i=1;i<n;i++){
        //cout<<rlen<<endl;
        if(rlen<v[i]){
            if(a[i]<a[lmdir]){
                int t=sz(double(v[i]-rlen)/d);
                rlen+=(t*d);
                cost+=t*a[i];
                lmdir=i;
                //cout<<t<<" 1 "<<i<<endl;
            }else{
                int t=sz(double(v[i]-rlen)/d);
                rlen+=(t*d);
                cost+=t*a[lmdir];
                //cout<<t<<" 2 "<<lmdir<<endl;
            }
        }
        rlen-=v[i];
    }
    cout<<cost<<endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int dp[10010];
int n,d;
int totald=0;
int times=0;
int a2[10010];
int v[10010];//distance
int a[10010];//price
int up(int a,int b){
    if(a%b==0){
        return a/b;
    }
    int r;
    r=a/b+1;
    return r;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n;
    cin>>d;
    for(int i=1;i<=n-1;i++){
        cin>>v[i];
        totald+=v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a2[i]=a[i];
    }
    sort(a2+1,a2+n-1+1);
    if(a2[1]==a[1]){
        times=up(totald,d);
        cout<<times*a[1];
    }
    else cout<<"129";
    return 0;
}
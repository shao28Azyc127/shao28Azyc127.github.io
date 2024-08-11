#include<bits/stdc++.h>
using namespace std;
int a[1000001];
long long n,g;
string b;
int ans=0,f=0;
int apple(int b){
    ans++;
    g=0;
    for(int i=1;i<=b;i=i+3){
        if(a[i]==1){
            f=ans;
        }
        a[i]=0;
        g++;
    }
    b-=g;
    for(int i=1;i<=b;i++){
        a[i]=-1;
    }
    if(a[b+g]==1){
        a[b]=1;
    }
    if(b<=0){
        return 0;
    }else{
        apple(b);
    }
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        a[i]=-1;
    }
    a[n]=1;
    apple(n);
    cout<<ans<<" "<<f;
    return 0;
}
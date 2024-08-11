#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n,a[100001]={},cnt=0,t=0;
    cin>>n;
    if(n==1){
        cout<<'1'<<' '<<'1';
        return 0;
    }
    for(int i=1;i<=n;i++){
        a[i]=i;
    }
    int s=n,r=1;
    while(s){
        if(n==a[r]){
            t=cnt;
        }
        for(int i=r;i<=s;i++){
            a[i]=a[i+1];
        }
        s-=1;
        r+=3;
        if(r>s){
            r=1;
            cnt++;
        }
    }
    cout<<cnt-1<<' '<<t;
    return 0;
}
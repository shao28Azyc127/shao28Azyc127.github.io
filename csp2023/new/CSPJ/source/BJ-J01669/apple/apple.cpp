#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;cin>>n;
    if(n%3==1){
        cout<<n/2+1<<' '<<1;
        return 0;
    }
    for(int i=1;i<=n;i++){
        a[i]=i;
    }
    for(int i=1;i<=n/2+1;i++){
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(cnt%3==0&&j==n){
                cout<<n/2+1<<" "<<i+1;
                return 0;
            }
            if(a[j]!=0){
                cnt++;
            }
            if(cnt%3==0){
                a[j]=0;
            }
        }
    }
    return 0;
}

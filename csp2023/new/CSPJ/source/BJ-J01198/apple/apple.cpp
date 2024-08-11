#include <bits/stdc++.h>
using namespace std;
int n,cnt=0,ans=0,arr[1000005],m,tmp;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    m=n;
    for(int i=1;i<=n;i++){
        arr[i]=i;
    }
    while(n>0){
        cnt++;
        tmp=0;
        for(int i=1;i<=n;i+=3){
            if(arr[i]==m)ans=cnt;
            arr[i]=1e9;
            tmp++;
        }
        sort(arr+1,arr+n+1);
        n-=tmp;
    }
    cout<<cnt<<" "<<ans;
    return 0;
}
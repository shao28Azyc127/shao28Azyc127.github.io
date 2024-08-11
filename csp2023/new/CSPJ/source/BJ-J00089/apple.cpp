#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,cnt=0;
    scanf("%d",&n);
    while(n){
        if(n%3!=0){
            n=n-n/3-1;
            cnt++;
        }
        else{
            n=n-n/3;
            cnt++;
        }

    }
    cout<<cnt<<" ";
    if(n%3==1){
        cout<<1;
        return 0;
    }
    else cout<<cnt;
    return 0;
}

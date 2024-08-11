#include<bits/stdc++.h>
using namespace std;
int ans;
int cnt;
int n;
int main(){
    //freopen("apple.in","r",stdin);
    //freopen("apple.out","w",stdout);

    cin>>n;
    if(n==1){
        cout<<1<<" "<<1;
        return 0;
    }else{
        cout<<n%3<<n%3;
    }
    
    return 0;
}

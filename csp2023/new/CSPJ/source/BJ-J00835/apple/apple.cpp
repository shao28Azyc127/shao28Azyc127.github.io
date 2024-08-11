#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n;
    cin>>n;
    long long k=n;
    int ans1=0;
    while(k){
        ans1++;
        k-=int(k/3.0+0.9);
    }
    cout<<ans1<<" ";
    k=n;
    int ans2=1;
    while(1){
        if(k%3==1)break;
        ans2++;
        k-=int(k/3.0+0.9);
    }
    cout<<ans2;
    return 0;
}

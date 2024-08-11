#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;cin>>n;
    int cnt=0,ans=0;
    int nowd=n;
    while(nowd>0){
            cnt++;
            if(nowd%3==1&&ans==0)ans=cnt;
            if(nowd%3==0)nowd=nowd/3*2;
            else nowd=nowd-nowd/3-1;
    }
    cout<<cnt<<" "<<ans;
}

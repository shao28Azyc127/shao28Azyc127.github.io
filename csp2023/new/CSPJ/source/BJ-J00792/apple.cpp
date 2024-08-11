#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int ans=0;
    int cnt=0;
    bool f=false;
    while(n>0){
        if(n%3==1&&f==false){
            cnt=ans+1;
            f=true;
        }
        if(n%3==0){
            n-=n/3;
        }
        else{
            n-=n/3+1;
        }
        ans++;
    }
    cout<<ans<<' '<<cnt<<endl;
    return 0;
}

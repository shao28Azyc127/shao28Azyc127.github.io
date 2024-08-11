#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,ans,day=0,k=1,c=0;
    cin>>n;
    ans=n;
    while(ans){
        day++;
        if(ans-1==0){
            ans=0;
            continue;
        }
        if(((ans-1)%3)==0&&k==1){
            c=day;
            k=0;
        }
        ans-=((ans-1)/3)+1;

    }
    if(c==0){
        c=day;
    }
    cout<<day<<" "<<c<<endl;
    return 0;
}

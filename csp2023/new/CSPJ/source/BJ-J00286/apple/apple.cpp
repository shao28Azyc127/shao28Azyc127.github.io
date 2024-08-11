#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,ans=0,ans2=0,x;
    bool flag=0;
    cin>>n;
    x=n;
    while(x){
        if(x%3==1 && !flag){
            flag=1;
            ans2++;
        }
        else if(x%3!=1 && !flag) ans2++;
        if(n>0){
            if(x%3==0) x-=x/3;
            else x-=(x/3+1);
            ans++;
        }else{
            break;
        }
    }
    cout<<ans<<" "<<ans2;
    return 0;
}

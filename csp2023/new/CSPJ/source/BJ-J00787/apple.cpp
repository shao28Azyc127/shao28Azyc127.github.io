#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,t,ans=1,f=0,ans2=0;
    cin>>n;
    t=n;
    while(t!=0){
        if(f==0&&(t-1)%3==0){
            f=1;
            ans2=ans;
        }
        n=t-((t-1)/3+1);
        t=n;
        ans++;
    }
    cout<<ans-1<<' '<<ans2;
}

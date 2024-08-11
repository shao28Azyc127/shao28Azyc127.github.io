#include<bits/stdc++.h>
using namespace std;
int n,m,ans1,ans2;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    m=n;
    if(n%3==1) ans2=1;
    while(m!=0){
        m-=1+(m-1)/3;
        ans1++;
        if(m%3==1&&ans2==0){
            ans2=ans1+1;
        }
    }
    cout<<ans1<<" "<<ans2;
    return 0;
}

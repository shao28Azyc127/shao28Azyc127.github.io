#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,ans1=0,ans2,flag=1;
    cin>>n;
    if(n<=3){
        cout<<n<<" "<<n;
        return 0;
    }
    int n1=n;
    while(n1>3){
        ans1++;
        if((n1-1)%3==0&&flag==1){
            ans2=ans1;
            flag=0;
        }
        int x=(n1-1)/3;
        n1-=1+x;
    }
    if(flag==1)ans2=ans1+n1;
    cout<<ans1+n1<<" "<<ans2;
    return 0;
}

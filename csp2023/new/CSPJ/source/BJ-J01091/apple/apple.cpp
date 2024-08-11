#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int ans1=0,ans2=0;
    while(n){
        ans1++;
        int temp;
        if(n%3==1&&ans2==0)ans2=ans1;
        if(n%3==0){
            temp=n/3;
        }
        else{
            temp=n/3+1;
        }
        n-=temp;
    }
    cout<<ans1<<" "<<ans2;
    return 0;
}

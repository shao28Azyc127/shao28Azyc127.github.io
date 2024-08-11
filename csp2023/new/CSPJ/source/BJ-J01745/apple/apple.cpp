#include<bits/stdc++.h>
long long n,ans1=0,ans2=9999999999;
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(n!=0){
        ans1++;
        if((n-1)%3==0){
            ans2=min(ans2,ans1);
        }
        n-=(n-1)/3+1;
    }
    cout<<ans1<<" "<<ans2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
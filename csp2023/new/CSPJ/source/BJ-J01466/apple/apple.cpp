#include<bits/stdc++.h>
using namespace std;
long long n,ans1,ans2,flag=0;
int main(){
    std::ios::sync_with_stdio(0);
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(n>3){
        if(n%3==1&&flag==0){
            ans2=ans1+1;
            flag=1;
        }
        n=n*2/3;
        ans1++;
    }
    if(ans2==0){
        ans2=ans1+n;;
    }
    cout<<ans1+n<<" "<<ans2<<endl;
    return 0;
}
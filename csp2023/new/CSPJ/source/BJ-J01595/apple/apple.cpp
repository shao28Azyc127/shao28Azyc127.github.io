#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
ll n,ans=0,ans1=-1;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
   cin>>n;
    while(n>0){
        if(n%3==1&&ans1==-1){
            ans1=ans+1;
        }
        n=n-((n-1)/3+1);
        ans++;
    }
    cout<<ans<<" "<<ans1<<endl;
    return 0;
}

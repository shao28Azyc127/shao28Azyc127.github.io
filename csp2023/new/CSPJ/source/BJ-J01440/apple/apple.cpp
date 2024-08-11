#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ans,sum,num;
int main(){
    freopen("apple.in",stdin,"r");
    freopen("apple.out",stdout,"w");
    cin>>n;
    ll s=n/3,k=n+1;
    if((n-1)%3==0)num=1;
    else if(n%3==0&&s%2==1)num=3;
    else if(n%3==0&&s%2==0)num=2;
    else if(k%3==0&&k/3%3==2)num=4;
    else if(k%3==0&&k/3%3==1)num=2;
    else if(k%3==0&&k/3%3==0)num=5;
    for(int i=1;;i++){
        ll w=n%3;
        ll r=n/3;
        if(r>0){
            ans++;
            sum+=r;
        }
        if(w>0){
            if(r==0)++ans;
            ++sum;
        }
        if(n<=1)break;
        n-=sum;
        sum=0;
    }
    cout<<ans<<' '<<num;
    return 0;
}

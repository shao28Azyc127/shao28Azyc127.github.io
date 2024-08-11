#include<bits/stdc++.h>
using namespace std;
long long a[1000000];
long long n,ans,ans2,n2,i=1;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    if(n==0){
        cout<<"0"<<" "<<"0";
        return 0;
    }
    if(n==3){
        cout<<"3"<<" "<<"3";
        return 0;
    }
    if(n==2){
        cout<<2<<" "<<2;
        return 0;
    }
    if(n==1){
        cout<<1<<" "<<1;
        return 0;
    }
    for(long long j=1;j<=n;j++){
        a[j]=1;
    }

    for(i;i<=n;i=i+3){
        if(i+3>n){
            ans++;
            a[i]=0;
            if(a[n]==0){
                ans2=ans;
            }
            i=ans+1;
            i=i-3;
            continue;
        }
        a[i]=0;
        if(a[n]==0){
                ans2=ans;
            }
        if(a[n]==0){
            ans2=ans;
        }
        for(long long k=1;k<=n;k++){
            if(a[k]==0){
                n2++;
            }
        }
    }
    if(n2==n){
            n2==0;
            cout<<ans<<" "<<ans2;
        }
    return 0;
}


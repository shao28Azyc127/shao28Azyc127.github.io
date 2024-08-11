#include <bits/stdc++.h>
using namespace std;

int a[1000000005];
int n,t,ans,i,j;
int sum=1;
int u;
int f;
int ans[2];

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        a[i]=1;
    }
    while(true){
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                continue;
            }
            if(sum==1){
                a[i]=0;
            }
            sum++;
            sum%=3;
        }
        sum=0;
        ans[0]++;
        if(a[n]==0 && u==0){
            ans[1]=ans[0];
            u=1;
        }
        f=0;
        for(int i=1;i<=n;i++){
            if(a[i]==1){
                f=1;
            }
        }
        if(f==0){
            break;
        }
    }
    cout<<ans[0]<<" "<<ans[1];
    return 0;
}

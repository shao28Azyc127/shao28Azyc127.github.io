#include<bits/stdc++.h>
using namespace std;
int n,cnt=1,sum,ans;
bool a[10000007];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(cnt){
        sum++;
        cnt=0;
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                cnt++;
                if(cnt%3==1){
                    a[i]=1;
                    if(i==n)ans=sum;
                }
            }
        }
    }
    cout<<sum-1<<" "<<ans<<endl;
    return 0;
}

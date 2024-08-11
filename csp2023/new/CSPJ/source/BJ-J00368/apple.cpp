#include<bits/stdc++.h>
using namespace std;
int n,ans1,ans2;
bool s[1000005];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    if(n==1) ans1=1;
    int flag=0;
    while(flag==0||flag==1){
        if(flag==0) ans2++;
        int saasd=2,asasas=0;
        ans1++;
        for(int i=1;i<=n;i++){
            if(!s[i]) saasd++;
            if(saasd==3){
                saasd=0;
                s[i]=1;
                if(i==n){
                    flag=1;
                    break;
                }
            }
            if(s[i]==1) asasas++;
        }
        if(asasas==n) flag=2;
    }
    cout<<ans1<<" "<<ans2;
	  return 0;
}
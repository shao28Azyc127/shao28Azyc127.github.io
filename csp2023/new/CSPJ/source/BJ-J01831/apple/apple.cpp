#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int a[100000010]={},cnt=0,ans=0,ans1=0,i;
    while(cnt!=n){
         int q=2;
         for(i=1;i<=n;i++){
            if(a[i]==0){
                if(q==2){
                   a[i]=1;
                   q=0;
                   cnt++;
                   if(i==n){
                      ansl=cnt;
                   }
                }else{
                   q++;
                }
            }
         }
         ans++;
     }
     cout<<ans;
     cout<<" "<<ans1;
     fclose(stdin);
     fclose(stdout);
     return 0;
}

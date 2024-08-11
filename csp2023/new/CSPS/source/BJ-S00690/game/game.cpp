#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
     ios::sync_with_stdio(0);
     int n;string s;cin>>n>>s;
     long long ans=0;
    if(n>100000){
        char stk[2000005];
    int top=0;
    long long ans=0,cnt=0;
    for(int i=0;i<n;i++){
        if(top==0||stk[top]!=s[i])stk[++top]=s[i];
        else {top--;ans++;}
        if(top==0){
            cnt++;
        }
    }
    ans+=cnt*(cnt-1)/2;
    cout<<ans;
    return 0;
    }
    for(int i=0;i<n;i++){
      char st[2000005],top=0;
       for(int j=i;j<n;j++){
          if(top==0||st[top]!=s[j])st[++top]=s[j];
          else top--;
          if(!top)ans++;
       }
     }
     cout<<ans<<endl;
 }

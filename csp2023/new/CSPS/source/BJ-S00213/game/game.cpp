#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
string s;
ll ans=0;
bool pd(ll l,ll r){
    for(ll i=l;i<=(l+r-1)>>1;i++){
        if(s[i]!=s[r-(i-l)]){
            return false;
        }
    }
    return true;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%lld",&n);
    cin>>s;
    ll las=0,kuai=0,tmp=0,flag=0,cnt=0;
   for(ll i=0;i<n;i++){
      //  cout<<las;
        flag=0;
        tmp=0;
        for(ll j=i+1;j<n;j+=2){
            if(pd(i,j)==true){
                ans++;
                tmp=j;
                flag=1;
            }
            }
        if(cnt==0&&flag==1){
            las=tmp;
            cnt=1;
        }
        else if(i==las+1){ //if close
            if(flag){//if have
            las=tmp;   //new las
            kuai++; //new block
            }else{
                ans+=kuai*(kuai+1)/2;
                kuai=0; //return to zero
            }
        }
        }
        ans+=kuai*(kuai+1)/2;
    printf("%lld",ans);
    return 0;
}
// I think this is a MAnacher. Unfortunately,I dont know how to write it
//there is a lot of bug

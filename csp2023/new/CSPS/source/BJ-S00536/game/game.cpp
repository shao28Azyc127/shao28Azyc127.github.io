#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ll n;
    cin>>n;
    string s;
    cin>>s;
    s=" "+s;
    ll ans=0;
    for (int len=2;len<=n;len+=2){
        for (int l=1;l+len-1<=n;l++){
            ll r=l+len-1;
            ll xiao=0;
            ll last=l;
            for(int i=l;i<r;i++){
                if(s[i]==s[i+1]){
                    ll l1=i,r1=i+1;
                    while(l1>=last&&r1<=r){
                        if(s[l1]==s[r1]){
                            l1--,r1++;
                            xiao+=2;
                        }else{
                            break;
                        }
                    }
                    last=r1;
                    i=r1-1;
                }
            }
            if(xiao>=len){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

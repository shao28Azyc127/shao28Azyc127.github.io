#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,p,ans;string s;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>s;s=" "+s;
    for(ll i=1;i<=n;i++) 
        for(ll j=i+1;j<=n;j++){
            string x=s.substr(i,j-i+1);
            while(x.size()>=2){
                bool flag=0;
                if(x.size()==2&&x[0]!=x[1]) break;
                if(x.size()==2&&x[0]==x[1]) ans++;
                ll len=x.size();
                for(ll k=0;k<len-1;k++)
                    if(x[k]==x[k+1]){
                        if(k==0) x=x.substr(2,len-2);
                        else if(k==len-2)x=x.substr(0,len-2);
                        else x=x.substr(0,k)+x.substr(k+2,len-k-2);
                        flag=1;break;
                    }
                if(!flag) break;
            }
        }
    cout<<ans<<'\n';
    return 0;
}
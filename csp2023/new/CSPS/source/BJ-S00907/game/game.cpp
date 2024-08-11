#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+10;
const int mod1=998244353;
const int mod2=1e9+7;
mt19937 rnd(time(0));
int n;ll pw1[N],pw2[N];
string s;
unordered_map <ll,int> mp;
ll res,now1,now2,base1,base2;
char st[N];int Top;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>s;s=" "+s;
    base1=rnd()%10000+1;
    base2=rnd()%10000+1;
    pw1[0]=pw2[0]=1;
    for(int i=1;i<=n;i++){
        pw1[i]=(pw1[i-1]*base1)%mod1;
        pw2[i]=(pw2[i-1]*base2)%mod2;
    }
    mp[0]++;
    for(int i=1;i<=n;i++){
        if(Top==0){
            now1+=pw1[Top]*(s[i]-'a'+1);
            now1%=mod1;
            now2+=pw2[Top]*(s[i]-'a'+1);
            now2%=mod2;
            st[++Top]=s[i];
        }else{
            if(st[Top]==s[i]){
                Top--;
                now1-=pw1[Top]*(s[i]-'a'+1);
                now1%=mod1;now1+=mod1;now1%=mod1;
                now2-=pw2[Top]*(s[i]-'a'+1);
                now2%=mod2;now2+=mod2;now2%=mod2;
            }else{
                now1+=pw1[Top]*(s[i]-'a'+1);
                now1%=mod1;
                now2+=pw2[Top]*(s[i]-'a'+1);
                now2%=mod2;
                st[++Top]=s[i];
            }
        }
        //cout<<now1<<" "<<now2<<endl;
        res+=mp[1ll*now1*(mod2+1)+now2];
        mp[1ll*now1*(mod2+1)+now2]++;
    }
    cout<<res<<endl;
	return 0;
}

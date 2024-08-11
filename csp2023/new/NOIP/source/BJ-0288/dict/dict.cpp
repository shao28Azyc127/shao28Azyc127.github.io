#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define repp(i,a,b) for(int i=(a);i>=(b);--i)
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
ll n,m,mx[3005],mmn=26,mn[3005],cnt;
string s;
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    rep(i,1,n){
        cin>>s;
        mn[i]=25;
        rep(j,0,m-1){
            mn[i]=min(mn[i],(ll)s[j]-'a');
            mx[i]=max(mx[i],(ll)s[j]-'a');
        }
        if(mx[i]==mmn) ++cnt;
        if(mx[i]<mmn){
            mmn=mx[i];
            cnt=1;
        }
    }
    rep(i,1,n) printf("%d",(mn[i]<mmn||(mn[i]==mmn&&cnt==1&&mx[i]==mmn))?1:0);
    return 0;
}

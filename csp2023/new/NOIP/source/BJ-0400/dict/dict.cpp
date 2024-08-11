#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll MAXN=3000+5;
ll n,m;
string s[MAXN],S[MAXN];
bool check(ll i){
    if(s[i]==S[1]){
        return s[i]<S[2];
    }
    return s[i]<S[1];
}
bool check1(ll i){
    for(int j=1;j<=n;++j){
        if(i==j){
            continue;
        }
        if(s[i]>=S[j]){
            return false;
        }
    }
    return true;
}
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;++i){
        cin>>s[i];
        sort(s[i].begin(),s[i].end());
        S[i]=s[i];
        reverse(S[i].begin(),S[i].end());
    }
    if(n<=300&&m<=300){
        for(int i=1;i<=n;++i){
            if(check1(i)){
                printf("1");
            }else{
                printf("0");
            }
        }
    }else{
        sort(S+1,S+n+1);
        for(int i=1;i<=n;++i){
            if(check(i)){
                printf("1");
            }else{
                printf("0");
            }
        }
    }
    return 0;
}


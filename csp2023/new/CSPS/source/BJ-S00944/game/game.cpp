#include <cstdio>
#include <string>
#include <iostream>
#include <stack>
#include <map>
using namespace std;
string s;
stack<char> st;
map<pair<long long,long long>,int> mp;
long long ans=0;
const long long cj=19260817,MOD=998244353,cc=314159,cMOD=1000000007;
long long ksm(long long a,int k){
    long long res=1;
    while(k){
        if(k&1) (res*=a)%=MOD;
        k>>=1;
        (a*=a)%=MOD;
    }
    return res;
}
long long ksmb(long long a,int k){
    long long res=1;
    while(k){
        if(k&1) (res*=a)%=cMOD;
        k>>=1;
        (a*=a)%=cMOD;
    }
    return res;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    scanf("%d",&n);
    cin>>s;
    long long ha1=0,ha2=0,B=ksm(cj,MOD-2),A=ksmb(cc,cMOD-2);
    for(int i=0;i<n;i++){
        ans+=mp[make_pair(ha1,ha2)];
        mp[make_pair(ha1,ha2)]++;
        if(!st.empty() && st.top()==s[i]){
            st.pop();
            ha1=(ha1-s[i]+MOD)%MOD;
            (ha1*=B)%=MOD;
            ha2=(ha2-s[i]+cMOD)%cMOD;
            (ha2*=A)%=cMOD;
        }else{
            st.push(s[i]);
            (ha1*=cj)%=MOD;
            (ha1+=s[i])%=MOD;
            (ha2*=cc)%=cMOD;
            (ha2+=s[i])%=cMOD;
        }
    }
    ans+=mp[make_pair(ha1,ha2)];
    printf("%lld",ans);
    return 0;
}
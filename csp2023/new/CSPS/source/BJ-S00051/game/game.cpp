#include <bits/stdc++.h>
using namespace std;
long long n, cnt=0;
string s;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%lld",&n);
    cin>>s;
    for(long long i=0;i<n;i++) if(s[i]==s[i+1]) cnt++;
    return printf("%lld",cnt)&0;
}

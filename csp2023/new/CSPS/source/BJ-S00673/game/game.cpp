#include<bits/stdc++.h>
using namespace std;
struct st{
    char c;
    int i;
};
long long n,ans,is[1000005],num[1000005];
char s[1000005];
stack<st> q;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    for(int b=1;b<=n;b++){
        cin>>s[b];
        if(!q.empty() && q.top().c==s[b]){
            num[q.top().i]++;
            q.pop();
            ans++;
            is[b]=1;
        }else{
            st nb;
            nb.c=s[b];
            nb.i=b;
            q.push(nb);
        }
    }
    for(int b=1;b<=n;b++){
        if(is[b]){
            ans=ans+num[b+1];
        }
    }
    cout<<ans;
    return 0;
}
